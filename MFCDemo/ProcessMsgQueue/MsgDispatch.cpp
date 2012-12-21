#include "StdAfx.h"
#include "MsgDispatch.h"

MsgDispatch::MsgDispatch(void)
{
}

MsgDispatch::~MsgDispatch(void){
}

void MsgDispatch::doOperator(ReqMsgQueueType type){
	 OperateFunction fun = functons_[type];
	 fun();
}

void MsgDispatch::registerFuncitons(const vector<OperateFunction>& functions){
	functons_ = functions;
}