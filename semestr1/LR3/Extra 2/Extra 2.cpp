#pragma hdrstop
#pragma argsused

#include <iostream>
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int _tmain() {
	int num, sum = 0;
	cout << "Enter a number: ";
	cin >> num;
	for (int i = 1; i < num; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	if (sum == num) {
		cout << "Perfect number";
	}
	else {
		cout << "Imperfect number";
	}
	getch();
	return 0;
}
