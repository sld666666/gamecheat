/** 
* @file         MsgListener.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-19
*/
#pragma once
#include "interprocessConstant.h"

class	MsgListener
{
public:
	MsgListener(const string& queueName);
	~MsgListener(void);

	void		start();
private:
	void		onLisnten();
	void		doOperator(MSG_QUEUE_TYPE type);
private:
	interprocess::message_queue msgQueue_;
};
