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
	cout << "������� �������� ���������� d: ";
	cin >> d;
	cout << "������� �������� ���������� a: ";
	cin >> a;
znak:
	cout << "������� ���� ��������: ";
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
		cout << "������������ ����" << endl;
		cout << "������� 'Y' ��� ���������� �����: ";
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
