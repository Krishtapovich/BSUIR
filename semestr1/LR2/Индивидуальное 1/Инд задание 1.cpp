#pragma hdrstop
#pragma argsused

#include <iostream>
#include <tchar.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int _tmain() {
	SetConsoleOutputCP(1251);
	float a, b, z, x, y;
	int num;
	cout << "������� a: ";
	cin >> a;
	cout << "������� b: ";
	cin >> b;
	cout << "������� z: ";
	cin >> z;
	cout << "������� ����� �� 1 �� 3 � ����������� �� ����, ����� ������� ������ ���� ������������ ��� ������� Y (2x, x^2, x/3): ";
	cin >> num;
	switch (num) {
	case 1:
		if (z <= 0) {
			x = pow(z, 2) / 2;
			y = ((b * 2 * x) / cos(x)) + (a * log(fabs(tan(x / 2))));
			cout << "Y = " << y << '\t' <<
				"��� ������� Y �������������� ������� 2x, ������� z <= 0";
		}
		else {
			x = sqrt(z);
			y = ((b * 2 * x) / cos(x)) + (a * log(fabs(tan(x / 2))));
			cout << "Y = " << y << '\t' <<
				"��� ������� Y �������������� ������� 2x, ������� z > 0";
		}
		break;
	case 2:
		if (z <= 0) {
			x = pow(z, 2) / 2;
			y = ((b * pow(x, 2)) / cos(x)) + (a * log(fabs(tan(x / 2))));
			cout << "Y = " << y << '\t' <<
				"��� ������� Y �������������� ������� x^2, ������� z <= 0";
		}
		else {
			x = sqrt(z);
			y = ((b * pow(x, 2)) / cos(x)) + (a * log(fabs(tan(x / 2))));
			cout << "Y = " << y << '\t' <<
				"��� ������� Y �������������� ������� x^2, ������� z > 0";
		}
		break;
	case 3:
		if (z <= 0) {
			x = pow(z, 2) / 2;
			y = ((b * (x / 3)) / cos(x)) + (a * log(fabs(tan(x / 2))));
			cout << "Y = " << y << '\t' <<
				"��� ������� Y �������������� ������� x/3, ������� z <= 0";
		}
		else {
			x = sqrt(z);
			y = ((b * (x / 3)) / cos(x)) + (a * log(fabs(tan(x / 2))));
			cout << "Y = " << y << '\t' <<
				"��� ������� Y �������������� ������� x/3, ������� z > 0";
		}
	default:
		cout << "������������ ����";
		break;
	}
	getch();
	return 0;
}
