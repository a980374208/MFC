#include <afxwin.h>
#include <iostream>

using namespace std;
class CMyDoc : public CDocument {
	DECLARE_SERIAL(CMyDoc)
	virtual void Serialize(CArchive& ar);
	CMyDoc(int s_a, long s_b, CString s_c) :a(s_a), b(s_b), c(s_c){}
	CMyDoc(){}
public:
	int a;
	long b;
	CString c ;
};
IMPLEMENT_SERIAL(CMyDoc,CDocument,1)
void CMyDoc::Serialize(CArchive& ar) {
	if (ar.IsStoring()) {
		ar << a << b << c;
	}
	else {
		ar >> a >> b >> c;
	}
}
void Store() {
	CFile file;
	file.Open("E:/MFC/Day07/test.txt", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file,0,4096);
	long age = 18;
	CString str = "hello word";
	int bb = 88;
	ar << age << str << bb ;
	ar.Close();
	file.Close();
}

void CStore() {
	CFile file;
	file.Open("E:/MFC/Day07/test.txt", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, 0, 4096);
	CMyDoc doc(18, 99, "asdasdada");
	ar << &doc;
	ar.Close();
	file.Close();
}




void Load() {
	CFile file;
	file.Open("E:/MFC/Day07/test.txt", CFile::modeRead);
	CArchive ar(&file, CArchive::load, 4096);
	CMyDoc* pdoc;
	ar >> pdoc;
	ar.Close();
	file.Close();
	cout << pdoc->a << pdoc->b<< pdoc->c;
}

int main() {
	//Store();
	//Load();
	CStore();
	Load();
	return 0;
}