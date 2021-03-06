using System;
using System.Net.Sockets;
using System.Collections.Generic;

namespace ff
{
    public interface IFFSocket{
        bool Connect(string ip, int port);
        void AsyncRecv();
        void AsyncSend(byte[] strData, bool c = true);
        void Close();
        void SetSessionData(object o);
        object GetSessionData();
        string GetIP();
        string GetProtocolType();
        void SetProtocolType(string s);
    }
    public delegate void SocketRecvHandler(IFFSocket ffsocket, byte[] strData);
    public delegate void SocketBrokenHandler(IFFSocket ffsocket);
    public delegate byte[] SocketPreSendCheck(byte[] strData);
    class FFScoketAsync: IFFSocket
    {
        protected Socket                        m_oSocket;
        protected byte[]                        m_oBuffer;
        protected List<byte[]>                  m_oBuffSending;
        protected SocketRecvHandler             m_funcRecv;
        protected SocketBrokenHandler           m_funcBroken;
        protected SocketPreSendCheck            m_funcPreSendCheck;
        protected object                        m_sessionData;
        protected int                           m_nStatus;
        protected string                        m_strProtocolType;
        public string GetProtocolType(){   return m_strProtocolType;   }
        public void SetProtocolType(string s) { m_strProtocolType = s; }
        public void SetSessionData(object data)
        {
            m_sessionData = data;
        }
        public object GetSessionData()
        {
            return m_sessionData;
        }
        public FFScoketAsync(SocketRecvHandler onRecv, SocketBrokenHandler onBroken, SocketPreSendCheck checkFunc = null, Socket socket = null)
        {
            m_nStatus = 0;
            if (socket == null)
            {
                m_oSocket   = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            }
            else
            {
                m_oSocket   = socket;
            }

            m_oBuffer       = new byte[1024*4];
            m_oBuffSending  = new List<byte[]>();
            m_funcRecv      = onRecv;
            m_funcBroken    = onBroken;
            m_funcPreSendCheck = checkFunc;
            m_sessionData   = null;
            m_strProtocolType = "";
        }
        void SetPreSendCheckFunc(SocketPreSendCheck f) { m_funcPreSendCheck = f; }
        public bool Connect(string ip, int port){
            try{
                m_oSocket.Connect(ip, port);
            }
            catch (Exception ex)
            {
                FFLog.Trace("scoket: connect Error " + ex.Message);
                return false;
            }
            AsyncRecv();
            return true;
        }
        public void Close(){
            FFNet.GetTaskQueue().Post(() =>
            {
                HandleClose();
            });
        }
        public void AsyncRecv()
        {
            m_nStatus = 1;
            m_oSocket.BeginReceive(m_oBuffer, 0, m_oBuffer.Length, SocketFlags.None, new AsyncCallback(HandleRecv), m_oSocket);
        }
        public void PostMsg(byte[] data){
            m_funcRecv(this, data);
        }
        public void HandleRecv(IAsyncResult ar)
        {
            if (m_nStatus == 0)
            {
                FFLog.Trace("scoket: HandleRecv has closed");
                return;
            }
            var length = 0;
            try
            {
                Socket socket = (Socket)ar.AsyncState;
                if (socket == null)
                {
                    return;
                }
                length = socket.EndReceive(ar);
            }
            catch (Exception ex)
            {
                FFLog.Warning("scoket: recv Error1 " + ex.Message);
                HandleClose();
                return;
            }
            //FFLog.Trace(string.Format("scoket: recv 1111 {0}", length));
            if (length == 0)
            {
                FFLog.Warning("HandleRecv: recv end ok file ");
                HandleClose();
                return;
            }
            FFNet.GetTaskQueue().Post(() =>
            {
                try
                {
                    byte[] message = new byte[length];
                    Array.Copy(m_oBuffer, 0, message, 0, length);
                    PostMsg(message);
                    //接收下一个消息
                    if (m_oSocket != null)
                    {
                        m_oSocket.BeginReceive(m_oBuffer, 0, m_oBuffer.Length, SocketFlags.None, new AsyncCallback(HandleRecv), m_oSocket);
                    }
                }
                catch (Exception ex)
                {
                    FFLog.Error("scoket: recv Error2 " + ex.Message);
                    HandleClose();
                }
            });
        }
        public void AsyncSend(byte[] strData, bool bCheckSend = true){
            FFNet.GetTaskQueue().Post(() =>
            {
                if (strData.Length == 0 || m_oSocket == null)
                {
                    return;
                }

                if (bCheckSend == true && m_funcPreSendCheck != null)
                {
                    strData = m_funcPreSendCheck(strData);
                }

                m_oBuffSending.Add(strData);
                if (m_oBuffSending.Count == 1)
                {
                    m_oSocket.BeginSend(strData, 0, strData.Length, 0, new AsyncCallback(handleSendEnd), m_oSocket);
                }
            });
        }
        private void handleSendEnd(IAsyncResult ar)
        {
            try
            {
                var socket = ar.AsyncState as Socket;
                socket.EndSend(ar);
            }
            catch (SocketException ex)
            {
                FFLog.Trace("scoket: send Error " + ex.Message);
                HandleClose();
                return;
            }
            FFNet.GetTaskQueue().Post(() =>
            {
                if (m_oBuffSending.Count > 0)
                {
                    m_oBuffSending.RemoveAt(0);
                }
                try
                {
                    if (m_oBuffSending.Count > 0 && m_oSocket != null)
                    {
                        byte[] data = m_oBuffSending[0];
                        m_oSocket.BeginSend(data, 0, data.Length, 0, new AsyncCallback(handleSendEnd), m_oSocket);
                    }
                }
                catch (SocketException ex)
                {
                    FFLog.Trace("scoket: send Error " + ex.Message);
                    HandleClose();
                }
            });
        }
        public void HandleClose(){
            if (m_nStatus == 0)
            {
                return;
            }
            m_nStatus = 0;
            FFNet.GetTaskQueue().Post(() =>
            {
                if (m_oSocket == null)
                {
                    return;
                }

                m_oSocket.Close();
                m_oSocket = null;
                m_oBuffSending.Clear();
                m_funcBroken(this);
            });
        }
        public string GetIP()
        {
            return ((System.Net.IPEndPoint)m_oSocket.RemoteEndPoint).Address.ToString();//
        }
    }
}
