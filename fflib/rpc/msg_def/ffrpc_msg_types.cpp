/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ffrpc_msg_types.h"

#include <algorithm>

namespace ff {

const char* SessionOfflineReq::ascii_fingerprint = "7CBAC864381682B525334E49955F454B";
const uint8_t SessionOfflineReq::binary_fingerprint[16] = {0x7C,0xBA,0xC8,0x64,0x38,0x16,0x82,0xB5,0x25,0x33,0x4E,0x49,0x95,0x5F,0x45,0x4B};

uint32_t SessionOfflineReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->session_id);
          this->__isset.session_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SessionOfflineReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SessionOfflineReq");

  xfer += oprot->writeFieldBegin("session_id", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->session_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SessionOfflineReq &a, SessionOfflineReq &b) {
  using ::std::swap;
  swap(a.session_id, b.session_id);
  swap(a.__isset, b.__isset);
}

const char* RouteLogicMsgReq::ascii_fingerprint = "EADC45C9A213F80E462BAA7CE9FA080F";
const uint8_t RouteLogicMsgReq::binary_fingerprint[16] = {0xEA,0xDC,0x45,0xC9,0xA2,0x13,0xF8,0x0E,0x46,0x2B,0xAA,0x7C,0xE9,0xFA,0x08,0x0F};

uint32_t RouteLogicMsgReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->session_id);
          this->__isset.session_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->cmd);
          this->__isset.cmd = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->body);
          this->__isset.body = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->session_ip);
          this->__isset.session_ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RouteLogicMsgReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("RouteLogicMsgReq");

  xfer += oprot->writeFieldBegin("session_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->session_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cmd", ::apache::thrift::protocol::T_I16, 2);
  xfer += oprot->writeI16(this->cmd);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("body", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->body);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("session_ip", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->session_ip);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RouteLogicMsgReq &a, RouteLogicMsgReq &b) {
  using ::std::swap;
  swap(a.session_id, b.session_id);
  swap(a.cmd, b.cmd);
  swap(a.body, b.body);
  swap(a.session_ip, b.session_ip);
  swap(a.__isset, b.__isset);
}

const char* GateChangeLogicNodeReq::ascii_fingerprint = "3CC2C885F5B9D03E96907F8376BF80E9";
const uint8_t GateChangeLogicNodeReq::binary_fingerprint[16] = {0x3C,0xC2,0xC8,0x85,0xF5,0xB9,0xD0,0x3E,0x96,0x90,0x7F,0x83,0x76,0xBF,0x80,0xE9};

uint32_t GateChangeLogicNodeReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->session_id);
          this->__isset.session_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->alloc_worker);
          this->__isset.alloc_worker = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->cur_group_name);
          this->__isset.cur_group_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->dest_group_name);
          this->__isset.dest_group_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->extra_data);
          this->__isset.extra_data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t GateChangeLogicNodeReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("GateChangeLogicNodeReq");

  xfer += oprot->writeFieldBegin("session_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->session_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("alloc_worker", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->alloc_worker);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cur_group_name", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->cur_group_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dest_group_name", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->dest_group_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("extra_data", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->extra_data);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(GateChangeLogicNodeReq &a, GateChangeLogicNodeReq &b) {
  using ::std::swap;
  swap(a.session_id, b.session_id);
  swap(a.alloc_worker, b.alloc_worker);
  swap(a.cur_group_name, b.cur_group_name);
  swap(a.dest_group_name, b.dest_group_name);
  swap(a.extra_data, b.extra_data);
  swap(a.__isset, b.__isset);
}

const char* GateCloseSessionReq::ascii_fingerprint = "56A59CE7FFAF82BCA8A19FAACDE4FB75";
const uint8_t GateCloseSessionReq::binary_fingerprint[16] = {0x56,0xA5,0x9C,0xE7,0xFF,0xAF,0x82,0xBC,0xA8,0xA1,0x9F,0xAA,0xCD,0xE4,0xFB,0x75};

uint32_t GateCloseSessionReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->session_id);
          this->__isset.session_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t GateCloseSessionReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("GateCloseSessionReq");

  xfer += oprot->writeFieldBegin("session_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->session_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(GateCloseSessionReq &a, GateCloseSessionReq &b) {
  using ::std::swap;
  swap(a.session_id, b.session_id);
  swap(a.__isset, b.__isset);
}

const char* GateRouteMsgToSessionReq::ascii_fingerprint = "0F4880829CCE5EA99C09EDF6EED29938";
const uint8_t GateRouteMsgToSessionReq::binary_fingerprint[16] = {0x0F,0x48,0x80,0x82,0x9C,0xCE,0x5E,0xA9,0x9C,0x09,0xED,0xF6,0xEE,0xD2,0x99,0x38};

uint32_t GateRouteMsgToSessionReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->session_id.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->session_id.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readI64(this->session_id[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.session_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->cmd);
          this->__isset.cmd = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->body);
          this->__isset.body = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t GateRouteMsgToSessionReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("GateRouteMsgToSessionReq");

  xfer += oprot->writeFieldBegin("session_id", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->session_id.size()));
    std::vector<int64_t> ::const_iterator _iter5;
    for (_iter5 = this->session_id.begin(); _iter5 != this->session_id.end(); ++_iter5)
    {
      xfer += oprot->writeI64((*_iter5));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cmd", ::apache::thrift::protocol::T_I16, 2);
  xfer += oprot->writeI16(this->cmd);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("body", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->body);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(GateRouteMsgToSessionReq &a, GateRouteMsgToSessionReq &b) {
  using ::std::swap;
  swap(a.session_id, b.session_id);
  swap(a.cmd, b.cmd);
  swap(a.body, b.body);
  swap(a.__isset, b.__isset);
}

const char* GateBroadcastMsgToSessionReq::ascii_fingerprint = "15896F1A4438B1ECBB80CEA66AD0C4C5";
const uint8_t GateBroadcastMsgToSessionReq::binary_fingerprint[16] = {0x15,0x89,0x6F,0x1A,0x44,0x38,0xB1,0xEC,0xBB,0x80,0xCE,0xA6,0x6A,0xD0,0xC4,0xC5};

uint32_t GateBroadcastMsgToSessionReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->cmd);
          this->__isset.cmd = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->body);
          this->__isset.body = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t GateBroadcastMsgToSessionReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("GateBroadcastMsgToSessionReq");

  xfer += oprot->writeFieldBegin("cmd", ::apache::thrift::protocol::T_I16, 1);
  xfer += oprot->writeI16(this->cmd);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("body", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->body);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(GateBroadcastMsgToSessionReq &a, GateBroadcastMsgToSessionReq &b) {
  using ::std::swap;
  swap(a.cmd, b.cmd);
  swap(a.body, b.body);
  swap(a.__isset, b.__isset);
}

const char* WorkerCallMsgReq::ascii_fingerprint = "15896F1A4438B1ECBB80CEA66AD0C4C5";
const uint8_t WorkerCallMsgReq::binary_fingerprint[16] = {0x15,0x89,0x6F,0x1A,0x44,0x38,0xB1,0xEC,0xBB,0x80,0xCE,0xA6,0x6A,0xD0,0xC4,0xC5};

uint32_t WorkerCallMsgReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->cmd);
          this->__isset.cmd = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->body);
          this->__isset.body = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t WorkerCallMsgReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("WorkerCallMsgReq");

  xfer += oprot->writeFieldBegin("cmd", ::apache::thrift::protocol::T_I16, 1);
  xfer += oprot->writeI16(this->cmd);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("body", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->body);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(WorkerCallMsgReq &a, WorkerCallMsgReq &b) {
  using ::std::swap;
  swap(a.cmd, b.cmd);
  swap(a.body, b.body);
  swap(a.__isset, b.__isset);
}

const char* WorkerCallMsgRet::ascii_fingerprint = "AB879940BD15B6B25691265F7384B271";
const uint8_t WorkerCallMsgRet::binary_fingerprint[16] = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

uint32_t WorkerCallMsgRet::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->err);
          this->__isset.err = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg_type);
          this->__isset.msg_type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->body);
          this->__isset.body = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t WorkerCallMsgRet::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("WorkerCallMsgRet");

  xfer += oprot->writeFieldBegin("err", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->err);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("msg_type", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->msg_type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("body", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->body);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(WorkerCallMsgRet &a, WorkerCallMsgRet &b) {
  using ::std::swap;
  swap(a.err, b.err);
  swap(a.msg_type, b.msg_type);
  swap(a.body, b.body);
  swap(a.__isset, b.__isset);
}

const char* BrokerRouteMsgReq::ascii_fingerprint = "C07CD6450B7CF81ECAF7242A818797B7";
const uint8_t BrokerRouteMsgReq::binary_fingerprint[16] = {0xC0,0x7C,0xD6,0x45,0x0B,0x7C,0xF8,0x1E,0xCA,0xF7,0x24,0x2A,0x81,0x87,0x97,0xB7};

uint32_t BrokerRouteMsgReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->dest_service_name);
          this->__isset.dest_service_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->dest_msg_name);
          this->__isset.dest_msg_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->dest_node_id);
          this->__isset.dest_node_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->from_node_id);
          this->__isset.from_node_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->callback_id);
          this->__isset.callback_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->body);
          this->__isset.body = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->err_info);
          this->__isset.err_info = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t BrokerRouteMsgReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("BrokerRouteMsgReq");

  xfer += oprot->writeFieldBegin("dest_service_name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->dest_service_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dest_msg_name", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->dest_msg_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dest_node_id", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->dest_node_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("from_node_id", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->from_node_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("callback_id", ::apache::thrift::protocol::T_I64, 7);
  xfer += oprot->writeI64(this->callback_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("body", ::apache::thrift::protocol::T_STRING, 8);
  xfer += oprot->writeString(this->body);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("err_info", ::apache::thrift::protocol::T_STRING, 9);
  xfer += oprot->writeString(this->err_info);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(BrokerRouteMsgReq &a, BrokerRouteMsgReq &b) {
  using ::std::swap;
  swap(a.dest_service_name, b.dest_service_name);
  swap(a.dest_msg_name, b.dest_msg_name);
  swap(a.dest_node_id, b.dest_node_id);
  swap(a.from_node_id, b.from_node_id);
  swap(a.callback_id, b.callback_id);
  swap(a.body, b.body);
  swap(a.err_info, b.err_info);
  swap(a.__isset, b.__isset);
}

const char* RegisterToBrokerReq::ascii_fingerprint = "3F5FC93B338687BC7235B1AB103F47B3";
const uint8_t RegisterToBrokerReq::binary_fingerprint[16] = {0x3F,0x5F,0xC9,0x3B,0x33,0x86,0x87,0xBC,0x72,0x35,0xB1,0xAB,0x10,0x3F,0x47,0xB3};

uint32_t RegisterToBrokerReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->node_type);
          this->__isset.node_type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->service_name);
          this->__isset.service_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RegisterToBrokerReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("RegisterToBrokerReq");

  xfer += oprot->writeFieldBegin("node_type", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->node_type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("service_name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->service_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RegisterToBrokerReq &a, RegisterToBrokerReq &b) {
  using ::std::swap;
  swap(a.node_type, b.node_type);
  swap(a.service_name, b.service_name);
  swap(a.__isset, b.__isset);
}

const char* RegisterToBrokerRet::ascii_fingerprint = "1F41639F8135007E546B5DA3F7363917";
const uint8_t RegisterToBrokerRet::binary_fingerprint[16] = {0x1F,0x41,0x63,0x9F,0x81,0x35,0x00,0x7E,0x54,0x6B,0x5D,0xA3,0xF7,0x36,0x39,0x17};

uint32_t RegisterToBrokerRet::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->register_flag);
          this->__isset.register_flag = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->node_id);
          this->__isset.node_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->service2node_id.clear();
            uint32_t _size6;
            ::apache::thrift::protocol::TType _ktype7;
            ::apache::thrift::protocol::TType _vtype8;
            xfer += iprot->readMapBegin(_ktype7, _vtype8, _size6);
            uint32_t _i10;
            for (_i10 = 0; _i10 < _size6; ++_i10)
            {
              std::string _key11;
              xfer += iprot->readString(_key11);
              int64_t& _val12 = this->service2node_id[_key11];
              xfer += iprot->readI64(_val12);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.service2node_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RegisterToBrokerRet::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("RegisterToBrokerRet");

  xfer += oprot->writeFieldBegin("register_flag", ::apache::thrift::protocol::T_I16, 1);
  xfer += oprot->writeI16(this->register_flag);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("node_id", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->node_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("service2node_id", ::apache::thrift::protocol::T_MAP, 3);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->service2node_id.size()));
    std::map<std::string, int64_t> ::const_iterator _iter13;
    for (_iter13 = this->service2node_id.begin(); _iter13 != this->service2node_id.end(); ++_iter13)
    {
      xfer += oprot->writeString(_iter13->first);
      xfer += oprot->writeI64(_iter13->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RegisterToBrokerRet &a, RegisterToBrokerRet &b) {
  using ::std::swap;
  swap(a.register_flag, b.register_flag);
  swap(a.node_id, b.node_id);
  swap(a.service2node_id, b.service2node_id);
  swap(a.__isset, b.__isset);
}

const char* EmptyMsgRet::ascii_fingerprint = "99914B932BD37A50B983C5E7C90AE93B";
const uint8_t EmptyMsgRet::binary_fingerprint[16] = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

uint32_t EmptyMsgRet::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EmptyMsgRet::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("EmptyMsgRet");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EmptyMsgRet &a, EmptyMsgRet &b) {
  using ::std::swap;
  (void) a;
  (void) b;
}

const char* SessionEnterWorkerReq::ascii_fingerprint = "1F10F993631B3ABD721D79EE58C2056E";
const uint8_t SessionEnterWorkerReq::binary_fingerprint[16] = {0x1F,0x10,0xF9,0x93,0x63,0x1B,0x3A,0xBD,0x72,0x1D,0x79,0xEE,0x58,0xC2,0x05,0x6E};

uint32_t SessionEnterWorkerReq::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->session_id);
          this->__isset.session_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->session_ip);
          this->__isset.session_ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->from_gate);
          this->__isset.from_gate = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->from_worker);
          this->__isset.from_worker = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->to_worker);
          this->__isset.to_worker = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->extra_data);
          this->__isset.extra_data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SessionEnterWorkerReq::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SessionEnterWorkerReq");

  xfer += oprot->writeFieldBegin("session_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->session_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("session_ip", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->session_ip);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("from_gate", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->from_gate);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("from_worker", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->from_worker);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("to_worker", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->to_worker);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("extra_data", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->extra_data);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SessionEnterWorkerReq &a, SessionEnterWorkerReq &b) {
  using ::std::swap;
  swap(a.session_id, b.session_id);
  swap(a.session_ip, b.session_ip);
  swap(a.from_gate, b.from_gate);
  swap(a.from_worker, b.from_worker);
  swap(a.to_worker, b.to_worker);
  swap(a.extra_data, b.extra_data);
  swap(a.__isset, b.__isset);
}

} // namespace
