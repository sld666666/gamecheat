/** 
* @file         MsgDispatch.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-21
*/
#pragma once
#include "interprocessConstant.h"
#include "MsgType.h"

class MsgDispatch
{
public:
	MsgDispatch(void);
	~MsgDispatch(void);

	void		registerFuncitons(const vector<OperateFunction>& functions);
	void		doOperator(ReqMsgQueueType type);
private:
	vector<OperateFunction>	functons_;
};
