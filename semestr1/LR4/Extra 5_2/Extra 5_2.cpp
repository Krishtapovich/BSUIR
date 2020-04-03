#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

int _tmain() {
	srand(time(0));
	int n, m;
	cout << "Enter number of rows of the array: ";
	cin >> n;
	cout << "Enter number of columns of the array: ";
	cin >> m;

	int** arr = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = new int[m + 1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10 - 5;
			cout << arr[i][j] << '\t';
		}
		cout << endl << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > arr[i][j + 1]) {
				arr[i][j + 1] = arr[i][j];     //если элемент слева больше, то меняем их местами
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > arr[i + 1][j]) {
				arr[i + 1][j] = arr[i][j];      //если элемент сверху больше, то меняем их местами
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[]arr[i];
	}
	delete[]arr;
	getch();
	return 0;
}
