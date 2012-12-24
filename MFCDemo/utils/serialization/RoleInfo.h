/** 
* @file         RoleInfo.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-21
*/

#include "SerializationInclude.h"


struct RoleInfo{
	long	maxHp;
	long	curHp;
	long	maxMp;
	long	curMp;
	wstring	roleName;

	RoleInfo(){
		maxHp = 0;
		curHp = 0;
		maxMp = 0;
		curMp = 0;
		roleName = _T("");
	}

private:
	friend class serialization::access;

	template<typename T>
	void serialize(T& ar, const unsigned int version)
	{
		ar & maxHp;
		ar & curHp;
		ar & maxMp;
		ar & curMp;
		ar & roleName;
	}
};