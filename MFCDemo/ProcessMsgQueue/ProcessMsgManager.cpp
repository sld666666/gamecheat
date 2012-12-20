#include "StdAfx.h"
#include "ProcessMsgManager.h"

ProcessMsgManager::ProcessMsgManager(const string& msgNameIn
									 , const string& msgNameOut)
{
	sender_ = (shared_ptr<MsgSender>(new MsgSender(msgNameIn)));
	listenner_ = (shared_ptr<MsgListener>(new MsgListener(msgNameOut)));
	startListerner();
}

ProcessMsgManager::~ProcessMsgManager(void)
{
}

void ProcessMsgManager::removeMsgQueue(const string& msgNameIn
									   , const string& msgNameOut)
{
	interprocess::message_queue::remove(msgNameIn.c_str());
	interprocess::message_queue::remove(msgNameOut.c_str());
}

void ProcessMsgManager::startListerner()
{
	listenner_->start();
}

void ProcessMsgManager::sendMsgQueue()
{
	sender_->sendMessageQueue();
}
