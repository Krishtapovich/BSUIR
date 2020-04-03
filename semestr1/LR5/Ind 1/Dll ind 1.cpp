//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you

#pragma hdrstop
#pragma argsused
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

extern "C" void _declspec(dllexport) _stdcall func (int n) {
	double* x = new double[n];

	for (int i = 0; i < n; i++) {
		x[i] = exp(-0.5 * i - 2 * M_PI) - atan(i + 0.1);
		cout << x[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < n; i++) {
		if (x[i] < 0) {
			x[i] += 0.5;
		}
		else {
			x[i] = 0.1;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
    delete[]x;
}

