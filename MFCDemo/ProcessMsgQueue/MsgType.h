/** 
* @file         MsgType.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-21
*/

#pragma once
#include <vector>
#include <boost/function.hpp>

using namespace std;
using namespace boost;

typedef function<void()> OperateFunction;

enum ReqMsgQueueType{
	REQ_MQT_SOURCE_ROLEINFO = 0
};

enum RESPMsgQueueType{
	RESP_MQT_SOURCE_ROLEINFO = 100
};