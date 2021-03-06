using System;
using System.Net.Sockets;
using System.Collections.Generic;
using Xunit;
namespace ff
{
    public delegate void SocketMsgHandler(IFFSocket ffsocket, UInt16 cmd, byte[] strData);
    class SocketCtrl
    {
        public Int32 size;
        public UInt16 cmd;
        public Int16 flag;
        public byte[] m_strRecvData;
        public SocketMsgHandler         m_funcMsgHandler;
        public SocketBrokenHandler      m_funcBroken;
        public WSProtocol               m_oWSProtocol;
        public SocketCtrl(SocketMsgHandler funcMsg, SocketBrokenHandler funcBroken){
            size = 0;
            cmd  = 0;
            flag = 0;
            m_strRecvData    = new byte[0];
            m_funcMsgHandler = funcMsg;
            m_funcBroken     = funcBroken;
            m_oWSProtocol = new WSProtocol();
        }
        public byte[] PreSendCheck(byte[] data)
        {
            if (m_oWSProtocol.IsWebSocketConnection())
            {
                return m_oWSProtocol.BuildPkg(data);
            }
            return data;
        }
        public void HandleRecv(IFFSocket ffsocket, byte[] strData){
            
            if (m_oWSProtocol.HandleRecv(strData))
            {
                if (ffsocket.GetProtocolType().Length == 0)
                {
                    ffsocket.SetProtocolType("websocket");
                }
                foreach (var eachWaitSend in m_oWSProtocol.GetSendPkg())
                {
                    ffsocket.AsyncSend(eachWaitSend, false);
                }
                m_oWSProtocol.ClearSendPkg();

                foreach (var eachRecvPkg in m_oWSProtocol.GetRecvPkg())
                {
                    int nHeadEndIndex = -1;
                    for (int i = 0; i < eachRecvPkg.Length; ++i)
                    {
                        if (eachRecvPkg[i] == '\n')
                        {
                            nHeadEndIndex = i;
                            break;
                        }
                    }
                    UInt16 nCmd = 0;
                    byte[] dataBody = eachRecvPkg;
                    if (nHeadEndIndex > 0)
                    {
                        byte[] bytesHead = new byte[nHeadEndIndex];
                        dataBody  = new byte[eachRecvPkg.Length - nHeadEndIndex - 1];
                        Array.Copy(eachRecvPkg, 0, bytesHead, 0, bytesHead.Length);
                        Array.Copy(eachRecvPkg, nHeadEndIndex + 1, dataBody, 0, dataBody.Length);

                        string[] strHeads = Util.Byte2String(bytesHead).Split(",");
                        string[] strCmds  = strHeads[0].Split(":");
                        if (strCmds.Length == 2 && strCmds[1].Length > 0)
                        {
                            nCmd = Convert.ToUInt16(strCmds[1]);
                        }
                    }
                    FFLog.Trace(string.Format("cmd={0},data={1}", nCmd, Util.Byte2String(dataBody)));
                        
                    try
                    {
                        m_funcMsgHandler(ffsocket, nCmd, dataBody);
                    }
                    catch (Exception ex)
                    {
                        FFLog.Error("wsscoket.HandleRecv error:" + ex.Message);
                    }
                }
                m_oWSProtocol.ClearRecvPkg();
                if (m_oWSProtocol.IsClose())
                {
                    ffsocket.Close();
                }
                return;
            }
            
            m_strRecvData = Util.MergeArray(m_strRecvData, strData);
            while (m_strRecvData.Length >= 8){
                size = System.Net.IPAddress.NetworkToHostOrder(BitConverter.ToInt32(m_strRecvData, 0));
                cmd  = (UInt16)System.Net.IPAddress.NetworkToHostOrder(BitConverter.ToInt16(m_strRecvData, 4));
                flag = System.Net.IPAddress.NetworkToHostOrder(BitConverter.ToInt16(m_strRecvData, 6));
                FFLog.Trace(string.Format("HandleRecv cmd:{0},len:{1}", cmd, size));
                if (m_strRecvData.Length < 8 + size){
                    break;
                }
                byte[] msgBody = new byte[size];
                Array.Copy(m_strRecvData, 8, msgBody, 0, size);
                if (m_strRecvData.Length == 8 + size)
                {
                    m_strRecvData = new byte[0];
                }
                else{
                    byte[] leftData = new byte[m_strRecvData.Length - (8 + size)];
                    Array.Copy(m_strRecvData, 8 + size, leftData, 0, size);
                    m_strRecvData = leftData;
                }
                try
                {
                    m_funcMsgHandler(ffsocket, cmd, msgBody);
                }
                catch (Exception ex)
                {
                    FFLog.Error("scoket.HandleRecv error:" + ex.Message);
                }
            }
        }
        public void HandleBroken(IFFSocket ffsocket){
            m_funcBroken(ffsocket);
        }
    }

    struct TimerData
    {
        public FFTask task;
        public Int64 endms;
    };
    class FFNetContext
    {
        private TaskQueue m_taskQueue;
        private List<TimerData> m_taskTimer;
        private System.Timers.Timer m_timer;
        public FFNetContext()
        {
            m_taskQueue = new TaskQueue();
            m_taskTimer = new List<TimerData>();
            m_taskQueue.Run();
            m_timer = new System.Timers.Timer(50);
            m_timer.Elapsed += new System.Timers.ElapsedEventHandler(this.HandleTimeout);//到达时间的时候执行事件；
            m_timer.AutoReset = true;//设置是执行一次（false）还是一直执行(true)；
            m_timer.Enabled = true;//是否执行System.Timers.Timer.Elapsed事件；
        }
        public void Cleanup()
        {
            if (GetTaskQueue().IsRunning())
            {
                GetTaskQueue().Stop();
            }
        }
        public TaskQueue GetTaskQueue() { return m_taskQueue; }
        public void HandleTimeout(object source, System.Timers.ElapsedEventArgs e)
        {
            System.DateTime currentTime = DateTime.Now;
            Int64 n = ((Int64)currentTime.Second) * 1000 + currentTime.Millisecond;
            m_taskTimer.RemoveAll(data =>
            {
                if (n >= data.endms)
                {
                    m_taskQueue.Post(() =>
                    {
                        data.task();
                    });
                    return true;
                }
                return false;
            });
        }
        public void Timerout(int nms, FFTask task)
        {
            System.DateTime currentTime = DateTime.Now;
            TimerData data;
            data.task = task;
            data.endms = ((Int64)currentTime.Second) * 1000 + currentTime.Millisecond + nms;
            m_taskTimer.Add(data);
        }
    };
    class FFNet
    {
        public static FFNetContext gInstanceContext = null;
        public static FFNetContext GetContext()
        {
            if (gInstanceContext == null)
            {
                gInstanceContext = new FFNetContext();
            }
            return gInstanceContext;
        }
        public static TaskQueue GetTaskQueue() { return GetContext().GetTaskQueue();  }
        public static void Timerout(int nms, FFTask task)
        {
            GetContext().Timerout(nms, task);
        }

        public static bool Cleanup()
        {
            GetContext().Cleanup();
            return true;
        }
        public static IFFSocket Connect(string host, SocketMsgHandler funcMsg, SocketBrokenHandler funcBroken){
            string[] strList = host.Split(":");
            if (strList.Length != 3)
            {
                return null;
            }
            string ip = strList[1];
            string[] ipList = ip.Split("//");
            if (ipList.Length == 2)
            {
                ip = ipList[1];
            }
            else
            {
                ip = ipList[0];
            }

            int port = int.Parse(strList[2]);
            SocketCtrl ctrl = new SocketCtrl(funcMsg, funcBroken);
            IFFSocket ffsocket = new FFScoketAsync(new SocketRecvHandler(ctrl.HandleRecv), new SocketBrokenHandler(ctrl.HandleBroken));
            if (ffsocket.Connect(ip, port)){
                return ffsocket;
            }
            return null;
        }
        public static FFAcceptor Listen(string host, SocketMsgHandler funcMsg, SocketBrokenHandler funcBroken){
            string[] strList = host.Split(":");
            if (strList.Length != 3)
            {
                return null;
            }
            string ip = strList[1];
            string[] ipList = ip.Split("//");
            if (ipList.Length == 2)
            {
                ip = ipList[1];
            }
            else
            {
                ip = ipList[0];
            }

            int port = int.Parse(strList[2]);
            SocketCtrl ctrl = new SocketCtrl(funcMsg, funcBroken);
            FFAcceptor ffacceptor = new FFAcceptor(new SocketRecvHandler(ctrl.HandleRecv), new SocketBrokenHandler(ctrl.HandleBroken), new SocketPreSendCheck(ctrl.PreSendCheck));
            if (ffacceptor.Listen(ip, port)){
                return ffacceptor;
            }
            return null;
        }
        public static void SendMsg(IFFSocket ffsocket, UInt16 cmdSrc, byte[] strData){
            if (ffsocket.GetProtocolType() == "websocket")
            {
                byte[] cmddata = Util.String2Byte(string.Format("cmd:{0}\n", cmdSrc));
                byte[] wsData = Util.MergeArray(cmddata, strData);
                ffsocket.AsyncSend(wsData);
                return;
            }
            int len = strData.Length;
            len = System.Net.IPAddress.HostToNetworkOrder(len);
            UInt16 cmd = (UInt16)System.Net.IPAddress.HostToNetworkOrder((Int16)cmdSrc);
            byte[] lenArray = BitConverter.GetBytes(len);
            byte[] cmdArray = BitConverter.GetBytes(cmd);
            byte[] resArray = new byte[2]{0, 0};
            byte[][] p = { lenArray, cmdArray, resArray, strData };
            byte[] sendData = Util.MergeArray(p);
            ffsocket.AsyncSend(sendData);
            FFLog.Trace(string.Format("SendMsg cmd:{0},len:{1},len2:{2}", cmdSrc, strData.Length, sendData.Length));
        }

        public static void SendMsg(IFFSocket ffsocket, UInt16 cmd, Thrift.Protocol.TBase reqMsg)
        {
            byte[] strData = EncodeMsg(reqMsg);
            SendMsg(ffsocket, cmd, strData);
        }
        public static byte[] EncodeMsg(Thrift.Protocol.TBase reqMsg)
        {
            var tmem = new Thrift.Transport.TMemoryBuffer();
            var proto = new Thrift.Protocol.TBinaryProtocol(tmem);
            //proto.WriteMessageBegin(new Thrift.Protocol.TMessage("ff::RegisterToBrokerReq", Thrift.Protocol.TMessageType.Call, 0));
            reqMsg.Write(proto);
            //proto.WriteMessageEnd();
            byte[] byteData = tmem.GetBuffer();
            return byteData;
        }
        public static bool DecodeMsg(Thrift.Protocol.TBase reqMsg, string strData)
        {
            if (strData.Length == 0)
            {
                return false;
            }
            byte[] data = Util.String2Byte(strData);
            var tmem = new Thrift.Transport.TMemoryBuffer(data);
            var proto = new Thrift.Protocol.TBinaryProtocol(tmem);
            //var msgdef = new Thrift.Protocol.TMessage("ffthrift", Thrift.Protocol.TMessageType.Call, 0);
            //proto.ReadMessageBegin();
            reqMsg.Read(proto);
            //proto.ReadMessageEnd();
            return true;
        }
        public static bool DecodeMsg(Thrift.Protocol.TBase reqMsg, byte[] data)
        {
            if (data.Length == 0)
            {
                return false;
            }
            var tmem = new Thrift.Transport.TMemoryBuffer(data);
            var proto = new Thrift.Protocol.TBinaryProtocol(tmem);
            //var msgdef = new Thrift.Protocol.TMessage("ffthrift", Thrift.Protocol.TMessageType.Call, 0);
            //proto.ReadMessageBegin();
            reqMsg.Read(proto);
            //proto.ReadMessageEnd();
            return true;
        }
        public static byte[] MergeArray(byte[] array1, byte[] array2)
        {
            byte[] ret = new byte[array1.Length + array2.Length];
            array1.CopyTo(array1, 0);
            array2.CopyTo(array2, array1.Length);
            return ret;
        }
        public static byte[] MergeArray(List<byte[]> listByteArray)
        {
            int totalLen = 0;
            foreach (var each in listByteArray)
            {
                totalLen += each.Length;
            }
            byte[] ret = new byte[totalLen];
            totalLen = 0;
            foreach (var each in listByteArray)
            {
                each.CopyTo(ret, totalLen);
                totalLen += each.Length;
            }
            return ret;
        }
    }
}
