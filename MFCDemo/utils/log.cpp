#include "stdafx.h"
#include "log.h"
#include "StringUtils.h"

#include <fstream>
#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
 using namespace boost::local_time; 
 using namespace boost::posix_time;
 
Log::Log(){

}

Log::~Log(){

}

void Log::debugMsg(const string& info){
	ofstream  file("log.txt", ios::app);
	if (file.is_open()){
		file<<getCurDataTime()<<":	"<< info <<endl;
		file.flush();
	}
	
}

void Log::debugMsg(const string& info, int number){
	string newStr = info + "----" + StringUtils::NumberToString(number);
	debugMsg(newStr);
}

string Log::getCurDataTime(){
	ptime now = second_clock::local_time();

	stringstream ss;
	ss >> now;
	string str = to_iso_extended_string(now);
	return str;
}