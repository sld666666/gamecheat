/** 
* @file         MsgListener.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-19
*/
#pragma once
#include "interprocessConstant.h"
#include "MsgDispatch.h"

class	MsgListener
{
public:
	MsgListener(const string& queueName);
	~MsgListener(void);

	void		start();
	void		registerFuncitons(const vector<OperateFunction>& functions);
private:
	void		onLisnten();
	
private:
	interprocess::message_queue msgQueue_;
	MsgDispatch	msgDispatch_;
	map<int, OperateFunction>	cheatFunctons_;
};
