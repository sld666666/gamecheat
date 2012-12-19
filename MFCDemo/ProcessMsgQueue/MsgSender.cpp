#include "stdafx.h"
#include "MsgSender.h"


MsgSender::MsgSender(void)
: msgQueue_(interprocess::open_or_create
			, INTERPRCESS_MESSAGE_QUEUE_NAME, 1, sizeof(int))
{
}

MsgSender::~MsgSender(void)
{
	interprocess::message_queue::remove(INTERPRCESS_MESSAGE_QUEUE_NAME);

}

void MsgSender::sendMessageQueue()
{
	int i (1);
	msgQueue_.send(&i, sizeof(i), 0);
}
