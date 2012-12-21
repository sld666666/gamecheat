#include "stdafx.h"
#include "MsgSender.h"
#include "log.h"


MsgSender::MsgSender(const string& queueName)
: msgQueue_(interprocess::open_or_create
			, queueName.c_str(), 1, sizeof(int))
{
	Log::debugMsg("MsgSender");
}

MsgSender::~MsgSender(void)
{
	//interprocess::message_queue::remove(INTERPRCESS_MESSAGE_QUEUE_NAME);

}

void MsgSender::sendMessageQueue(int type)
{
	msgQueue_.send(&type, sizeof(int), 0);
}


