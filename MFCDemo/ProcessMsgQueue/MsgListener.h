/** 
* @file         MsgListener.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-19
*/
#pragma once
#include<boost/signals2.hpp>  

#include "interprocessConstant.h"
#include "MsgDispatch.h"

typedef signals2::signal<void(int type)> MsgTypeSignal;
typedef MsgTypeSignal::slot_type MsgTypeSlot;
typedef boost::signals2::connection		SIGCONECTION;

class	MsgListener
{
public:
	MsgListener(const string& queueName);
	~MsgListener(void);

	void		start();
	void		registerFuncitons(const vector<OperateFunction>& functions);
	SIGCONECTION connectMsgType(const MsgTypeSlot& slot);
private:
	void		onLisnten();
	
private:
	interprocess::message_queue msgQueue_;
	MsgDispatch	msgDispatch_;
	map<int, OperateFunction>	cheatFunctons_;
	MsgTypeSignal			msgTypeSignal_;
};
