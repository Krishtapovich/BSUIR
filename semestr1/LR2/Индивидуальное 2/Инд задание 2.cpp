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
	float x, y, s;
	cout << "������� y: ";
	cin >> y;
	cout << "������� x: ";
	cin >> x;
	if (x > fabs(y)) {
		s = (2 * pow(x, 3)) + (3 * pow(y, 2));
		cout << "S = " << s << '\t' <<
			"���������� ����������� �� ������� 2x^3 + 3y^2, ��� ������� ��� x > |y|";

	}
	else if (x > 3 && x < fabs(y)) {
		s = fabs(x - y);
		cout << "S = " << s << '\t' <<
			"���������� ����������� �� ������� |x - y|, ��� ������� ��� 3 < x < |y|";
	}
	else {
		s = pow(fabs(x - y), (1.0 / 3));
		cout << "S = " << s << '\t' <<
			"���������� ����������� �� ������� |x - y|^(1/3), ��� ������� ��� x < 3";

	}
	getch();
	return 0;
}
