#include "StdAfx.h"
#include "ProcessMsgManager.h"
#include "log.h"

ProcessMsgManager::ProcessMsgManager(const string& msgNameIn
									 , const string& msgNameOut)
{
	Log::debugMsg("ProcessMsgManager");
	sender_ = (shared_ptr<MsgSender>(new MsgSender(msgNameIn)));
	listenner_ = (shared_ptr<MsgListener>(new MsgListener(msgNameOut)));
	startListerner();
}

ProcessMsgManager::~ProcessMsgManager(void){
}

void ProcessMsgManager::registerFuncitons(const vector<OperateFunction>& functions){
	if (listenner_)
		listenner_->registerFuncitons(functions);
}

void ProcessMsgManager::removeMsgQueue(const string& msgNameIn
									   , const string& msgNameOut){
	interprocess::message_queue::remove(msgNameIn.c_str());
	interprocess::message_queue::remove(msgNameOut.c_str());
}

void ProcessMsgManager::startListerner(){
	listenner_->start();
}

void ProcessMsgManager::sendMsgQueue(ReqMsgQueueType type){
	sender_->sendMessageQueue(type);
}

void ProcessMsgManager::doResponse(RESPMsgQueueType respType){
	sender_->sendMessageQueue(respType);
}

SIGCONECTION ProcessMsgManager::connectMsgType( const MsgTypeSlot& slot )
{
	return listenner_->connectMsgType(slot);
}


