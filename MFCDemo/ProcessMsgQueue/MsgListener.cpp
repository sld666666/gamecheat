#include "StdAfx.h"
#define BOOST_ALL_NO_LIB
#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include "MsgListener.h"
#include "log.h"


#pragma comment(lib, "boost_thread-vc90-mt-1_43.lib")

MsgListener::MsgListener(const string& queueName)
: msgQueue_(interprocess::open_or_create
			, queueName.c_str(), 1, sizeof(int))
{
	Log::debugMsg("MsgListener");
}

MsgListener::~MsgListener(void)
{
}

void MsgListener::start()
{
	Log::debugMsg("MsgListener start");
	boost::thread lisntenThread(bind(&MsgListener::onLisnten, this));

}

void MsgListener::registerFuncitons(const vector<OperateFunction>& functions){
	msgDispatch_.registerFuncitons(functions); 
}

void MsgListener::onLisnten()
{

	while (1)
	{
		try{
			unsigned int prioity, recvd_size;

			int recvd_number;
			msgQueue_.receive(&recvd_number, sizeof(recvd_number), recvd_size, prioity);
			msgDispatch_.doOperator(static_cast<ReqMsgQueueType>(recvd_number));
			Log::debugMsg("MsgListener receive", recvd_number);
		}
		catch(interprocess::interprocess_exception &ex)
		{
			interprocess::message_queue::remove("message_queue");
			//std::cout << ex.what() <<std::endl;
		}
	}
}

