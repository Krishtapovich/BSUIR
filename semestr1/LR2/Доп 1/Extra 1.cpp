#pragma hdrstop
#pragma argsused

#include <iostream>
#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int _tmain() {
	SetConsoleOutputCP(1251);
	float a, y;
	cout << "������� a: ";
	cin >> a;
	if (a <= -1) {
		y = -1 / a;
		cout << "f(a) = " << y;
	}
	else if (a > -1 && a <= 2) {
		y = pow(a, 2);
		cout << "f(a) = " << y;
	}
	else if (a > 2) {
		y = 4;
		cout << "f(a) = " << y;
	}
	getch();
	return 0;
}
