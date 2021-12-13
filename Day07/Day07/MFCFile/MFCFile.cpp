#include <afxwin.h>
#include <iostream>
using namespace std;

void File() {
	CFile file;
	file.Open("E:/MFC/Day07/file.txt", CFile::modeCreate | CFile::modeReadWrite);
	char arg[] = "hello word";
	file.Write(arg, strlen(arg));
	file.SeekToBegin();
	int a = file.GetLength();
	char buf[256];
	LONG nlong = file.Read(buf, 255);
	cout << buf << nlong << endl;
	file.Close();
}
int main() {
	File();
	return 0;
}