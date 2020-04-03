#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

int _tmain()

{
	const int size = 7;
	int arr[7];
	for (int i = 0; i < 7; i++) {
		cout << "Array[" << i << "] = ";
		cin >> arr[i];
	}
	int count = 0;
	for (int i = 0; i < size / 2; i++) {
		if (arr[i] == arr[6 - i])   // проверка равенства первого и соответствующего ему с конца элемента
		{
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == size / 2) {
		cout << "The array is symmetrical";
	}
	else {
		cout << "The array isn't symmetrical";
	}

	getch();
	return 0;
}
