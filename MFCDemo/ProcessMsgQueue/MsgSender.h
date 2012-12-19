
#pragma once
#include "interprocessConstant.h"

class _declspec(dllexport) MsgSender
{
public:
	MsgSender(void);
	~MsgSender(void);

	void	sendMessageQueue();
	
private:
	interprocess::message_queue msgQueue_;

};
