#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif
#include <conio.h>
#include <stdio.h>
#include "integrals.h"

int _tmain(int argc, _TCHAR* argv[]) {
	integral1(*f1);
	integral2(*f2);
	integral3(*f3);
	integral4(*f4);
	getch();
	return 0;
}
