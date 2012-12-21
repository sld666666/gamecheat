#include "StdAfx.h"
#include "StringUtils.h"

#include <sstream>

StringUtils::StringUtils(void){
}

StringUtils::~StringUtils(void){
}

string	StringUtils::NumberToString(int number){
	stringstream ss;
	ss<<number;
	return ss.str();
}
