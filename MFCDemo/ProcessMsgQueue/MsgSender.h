
#pragma once
#include "interprocessConstant.h"

class	MsgSender
{
public:
	MsgSender(const string& queueName);
	~MsgSender(void);

public:
	void	sendMessageQueue();
	
private:
	interprocess::message_queue msgQueue_;

};
