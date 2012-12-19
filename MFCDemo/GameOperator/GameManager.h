/** 
* @file         GameManager.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-19
*/
#pragma once
#include "commonInclude.h"
#include "ProcessMsgManager.h"


class GameManager
{
public:
	GameManager(void);
	~GameManager(void);
private:
	shared_ptr<ProcessMsgManager> processMsgManager_;

};
