#pragma hdrstop
#pragma argsused
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

int _tmain() {
	SetConsoleOutputCP(1251);
	float d, a;
	char zn;
	cout << "Введите значение переменной d: ";
	cin >> d;
	cout << "Введите значение переменной a: ";
	cin >> a;
znak:
	cout << "Введите знак операции: ";
	cin >> zn;
	switch (zn) {
	case '+':
		d += a;
		cout << "d + a = " << d << endl;
		break;
	case '-':
		d -= a;
		cout << "d - a = " << d << endl;
		break;
	case '/':
		d /= a;
		cout << "d / a =  " << d << endl;
		break;
	case '*':
		d *= a;
		cout << "d * a = " << d << endl;
		break;
	default:
		cout << "Неправильный ввод" << endl;
		cout << "Нажмите 'Y' для повторного ввода: ";
		cin >> zn;
		if (zn == 'y' || zn == 'Y') {
			goto znak;
		}
		else {
			break;
		}

	}
	getch();
	return 0;
}
