#pragma hdrstop
#pragma argsused

#include <iostream>
#include <tchar.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

int _tmain() {
	int G, now, raz, t;
	SetConsoleOutputCP(1251);
	cout << "Введите год рождения: ";
	cin >> G;
	cout << "Введите текущий год: ";
	cin >> now;
	raz = now - G;
	t = raz % 10;
	if(raz >= 10 && raz <= 20){
	switch(t){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 0: cout << "Возраст человека: " << raz << " лет"; break;
	}
	} else {
        switch(t){
		case 1: cout << "Возраст человека: " << raz << " год"; break;
		case 2:
		case 3:
		case 4: cout << "Возраст человека: " << raz << " года"; break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 0: cout << "Возраст человека: " << raz << " лет"; break;
	}
    }
	getch();
	return 0;
}
