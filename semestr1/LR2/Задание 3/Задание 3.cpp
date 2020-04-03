#pragma hdrstop
#pragma argsused

#include <iostream>
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
int _tmain()
{
    SetConsoleOutputCP(1251);
	float a, b;
	cout << "Введите a = ";
	cin >> a;
	cout << "Введите b = ";
	cin >> b;
	bool A = a > b;
    A ? cout << "Максимальное число: " << a : cout << "Максимальное число: " << b;
	getch();
	return 0;
}
