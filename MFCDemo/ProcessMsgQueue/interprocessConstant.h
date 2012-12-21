/** 
* @file         interprocessConstant.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-19
*/
#pragma  once

#include <boost/interprocess/shared_memory_object.hpp> 
#include <boost/interprocess/mapped_region.hpp> 
#include <boost/interprocess/ipc/message_queue.hpp>  
#include "commonInclude.h"
#include <string>

using namespace boost;
using namespace std;

static const string  INTERPRCESS_MESSAGE_QUEUE_NAME_IN		= "huapi2_message_queue_in";
static const string	INTERPRCESS_MESSAGE_QUEUE_NAME_OUT		= "huapi2_message_queue_out";

