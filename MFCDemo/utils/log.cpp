#include "stdafx.h"
#include "log.h"
#include "StringUtils.h"

#include <fstream>

Log::Log(){

}

Log::~Log(){

}

void Log::debugMsg(const string& info){
	ofstream  file("log.txt", ios::app);
	if (file.is_open()){
		file<< info <<endl;
		file.flush();
	}
	
}

void Log::debugMsg(const string& info, int number){
	string newStr = info + "----" + StringUtils::NumberToString(number);
	debugMsg(newStr);
}