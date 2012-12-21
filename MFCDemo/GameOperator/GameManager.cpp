#include "StdAfx.h"
#include "GameManager.h"
#include "commonInclude.h"
#include "log.h"

GameManager::GameManager(void)
:processMsgManager_(new ProcessMsgManager(INTERPRCESS_MESSAGE_QUEUE_NAME_OUT
					, INTERPRCESS_MESSAGE_QUEUE_NAME_IN))
{
	Log::debugMsg("gameManager");
	registerFucntion();
}

GameManager::~GameManager(void)
{
}

void GameManager::registerFucntion(){
	vector<OperateFunction> vecs;
	vecs.push_back(bind(&GameManager::getRoleInfo, this));

	processMsgManager_->registerFuncitons(vecs);
}

void GameManager::getRoleInfo(){
	Log::debugMsg("getRoleInfo");

	processMsgManager_->doResponse(RESP_MQT_SOURCE_ROLEINFO);
}


