#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
using namespace std;

int _tmain() {
	SetConsoleOutputCP(1251);
	float a, x, b, c;
	cout << "������� x ��� ������� a = sin(x), b = cos(x), c = log(x): ";
	cin >> x;
	a = sin(x);
	b = cos(x);
	c = log(x);
	if (a < b && a < c) {
		cout << "����������� �������� ��������� a: " << a;
	}
	else if (b < a && b < c) {
		cout << "����������� �������� ��������� b: " << b;
	}
	else if (c < a && c < b) {
		if (x == 0) {
			cout << "���������� ����������� �������� ��� c";
		}
		else {
			cout << "����������� �������� ��������� c: " << c;
		}
	}
	else if (a == b && b == c) {
		cout << "��� �������� �����: " << a;
	}
	getch();
	return 0;
}
