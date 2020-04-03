#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int _tmain()
{   float x, p, z, K, C, D, A, B, Y;
	cout << "x = ";
	cin >> x;
	cout << "p = ";
	cin >> p;
	cout << "z = ";
	cin >> z;
	cout << "K = ";
	cin >> K;
	cout << "C = ";
	cin >> C;
	cout << "D = ";
	cin >> D;
	A = sin(x * M_PI / 180) - z;
	B = fabs(p - x);
	Y = pow((A + B), 2) - (K / (C * D));
	cout << "Y = " << Y;
	getch();
	return 0;
}
