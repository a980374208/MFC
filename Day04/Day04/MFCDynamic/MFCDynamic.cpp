#include <afxwin.h>
#include <iostream>

using namespace std;
class CAnimal : public  CObject {
	DECLARE_DYNAMIC(CAnimal)
};
IMPLEMENT_DYNAMIC(CAnimal,CObject)

class CDog : public CAnimal {
	//DECLARE_DYNAMIC(CDog)
protected: 
	static CRuntimeClass* PASCAL _GetBaseClass(); 
public: 
	static const CRuntimeClass classCDog;
	static CRuntimeClass* PASCAL GetThisClass(); 
	virtual CRuntimeClass* GetRuntimeClass() const; 

};


//IMPLEMENT_DYNAMIC(CDog, CAnimal)
CRuntimeClass* PASCAL CDog::_GetBaseClass()
{ return RUNTIME_CLASS(CAnimal); }
AFX_COMDAT const CRuntimeClass CDog::classCDog = {
	"CDog", sizeof(class CDog), 0xFFFF, nullptr,
		& CDog::_GetBaseClass, NULL, nullptr };
	CRuntimeClass* PASCAL CDog::GetThisClass()
{ return _RUNTIME_CLASS(CDog); }
CRuntimeClass* CDog::GetRuntimeClass() const
{ return _RUNTIME_CLASS(CDog); }



int main() {
	CDog yellowDog;
	if (yellowDog.IsKindOf(RUNTIME_CLASS(CAnimal))) {
		cout << "yellowDog is CDog" << endl;
	}
	else {
		cout << "yellowDog isn't CDog" << endl;
	}
	return 0;
}