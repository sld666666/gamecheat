#include "StdAfx.h"
#include "GameManager.h"
#include "log.h"

GameManager::GameManager(void)
:processMsgManager_(new ProcessMsgManager(INTERPRCESS_MESSAGE_QUEUE_NAME_OUT
					, INTERPRCESS_MESSAGE_QUEUE_NAME_IN))
{
	Log::debugMsg("gameManager");
}

GameManager::~GameManager(void)
{
}


