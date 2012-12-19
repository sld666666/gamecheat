/** 
* @file         ProcessMsgManager.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-19
*/
#pragma once

#include "MsgListener.h"
#include "MsgSender.h"

class AFX_EXT_CLASS ProcessMsgManager
{
public:
	ProcessMsgManager(const string& msgNameIn, const string& msgNameOut);
	~ProcessMsgManager(void);

public:
	static void	removeMsgQueue(const string& msgNameIn, const string& msgNameOut);

public:
	void		sendMsgQueue();

private:
	void		startListerner();

private:
	shared_ptr<MsgSender>	sender_;
	shared_ptr<MsgListener> listenner_;
};
