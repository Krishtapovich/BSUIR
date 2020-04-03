#pragma hdrstop
#pragma argsused
#include <windows.h>
#include <math.h>
#include <iostream>
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
int _tmain()
{   SetConsoleOutputCP(1251);
	float k, m, x1, x2, L;
	cout << "¬ведите x1: ";
	cin >> x1;
	cout << "¬ведите x2: ";
	cin >> x2;
	cout << "¬ведите m: ";
	cin >> m;
	k = pow(cos(pow(x1, 2)), 3) + pow(sin(pow(x2, 2)), 3);
	if(k >= 1){
		L = pow(k, 3) + pow(m, 0.2);
		cout << "L = " << L;
	} else if(k <= 1){
		L = pow(k, 2) - exp(m);
		cout << "L = " << L;
	}
	getch();
	return 0;
}
