#pragma hdrstop
#pragma argsused
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
int _tmain()
{   SetConsoleOutputCP(1251);
	int n, k, sum, end_digit, pre_end_digit, z;
	cout << "Введите сумму в рублях: ";
	cin >> n;
	cout << "Введите дополнительную сумму: ";
	cin >> k;
	sum = n + k;
	end_digit = sum % 10;
	pre_end_digit = sum % 100;
	z = pre_end_digit * 10 + end_digit;
	if(pre_end_digit >= 11 && pre_end_digit <= 19 || pre_end_digit == 11){
	switch(pre_end_digit){
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:  cout << "Вся сумма равна: " << sum << " рублей"; break;
	}
	} else {
	switch(end_digit){
		case 1: cout << "Вся сумма равна: " << sum << " рубль"; break;
		case 2:
		case 3:
		case 4: cout << "Вся сумма равна: " << sum << " рубля"; break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 0: cout << "Вся сумма равна: " << sum << " рублей"; break;
	}
	}
	getch();
	return 0;
}
