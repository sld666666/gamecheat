
#pragma once
#include "interprocessConstant.h"
#include "MsgType.h"

class	MsgSender
{
public:
	MsgSender(const string& queueName);
	~MsgSender(void);

public:
	void	sendMessageQueue(int type);
	
private:
	interprocess::message_queue msgQueue_;

};
