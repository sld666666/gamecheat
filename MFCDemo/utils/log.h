/** 
* @file         log.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-21
*/
#pragma once
#include "commonInclude.h"
#include <string>
using namespace std;



class AFX_EXT_CLASS Log 
{
public:
	Log();
	~Log();

	static void debugMsg(const string& info);
	static void debugMsg(const string& info, int number);
	static string getCurDataTime();
};


