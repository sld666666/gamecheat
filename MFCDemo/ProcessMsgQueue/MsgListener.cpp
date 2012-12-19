#include "StdAfx.h"

//#define BOOST_ALL_NO_LIB
#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include "MsgListener.h"
#include "log.h"

//#pragma comment(lib, "boost_thread-vc90-mt-1_43.lib")

MsgListener::MsgListener(void)
: msgQueue_(interprocess::open_only, INTERPRCESS_MESSAGE_QUEUE_NAME)
{
}

MsgListener::~MsgListener(void)
{
}

void MsgListener::start()
{
	boost::thread lisntenThread(bind(&MsgListener::onLisnten, this));

}

void MsgListener::onLisnten()
{
	while (1)
	{
		try{
			unsigned int prioity, recvd_size;

			int recvd_number;
			msgQueue_.receive(&recvd_number, sizeof(recvd_number), recvd_size, prioity);
			doOperator(static_cast<MSG_QUEUE_TYPE>(recvd_number));
			Log::instance().debugMsg("MsgListener receive", recvd_number);
		}
		catch(interprocess::interprocess_exception &ex)
		{
			interprocess::message_queue::remove("message_queue");
			//std::cout << ex.what() <<std::endl;
		}
	}
}


void MsgListener::doOperator(MSG_QUEUE_TYPE type)
{
	switch(type)
	{
	case MQT_START:
		break;
	case MQT_PAUSE:
		break;
	default:
		break;
	}
}
