/** 
* @file         RoleInfo.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-21
*/

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
};