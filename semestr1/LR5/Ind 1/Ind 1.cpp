#pragma hdrstop
#pragma argsused

#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {

	HINSTANCE load;
	load = LoadLibrary("Dll.dll");

	typedef void (_stdcall *pfunc) (int);
	pfunc func;

	func = (pfunc)GetProcAddress(load, "func");

	int n;
	cout << "Enter number of elements of the array: ";
	cin >> n;
	func(n);

	FreeLibrary(load);

	getch();
	return 0;
}
