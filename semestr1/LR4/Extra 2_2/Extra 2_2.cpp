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
using namespace std;

int _tmain() {
	int n;
	cout << "Enter odd dimension of the magic square: ";
	cin >> n;
	cout << endl << endl;

	cout << "Magic square " << n << "X" << n << ":" << endl << endl;
	int** square = new int* [n];
	for (int i = 0; i < n; i++) {
		square[i] = new int[n];
	}

	int razm = n * n;
	int i = 0, j = n / 2;   // j/2 нужно, чтобы написать 1 в середине первой строки

	for (int k = 1; k <= razm; k++) {
		square[i][j] = k;
		i--;     // смещение по диагонали
		j++;     //  вверх и вправо
		if (k % n == 0) {   //если элемент кратен размерности, то следующий элемент пишем под ним
			i += 2;
			j--;
		}
		else {
			if (j == n) {    //если на 1 вышли за предел справа, то возвращаемся в начало данной строки
				j -= n;
			}
			else if (i < 0) {    //если на 1 вышли за предел сверху, то возвращаемся в начало данного стобца
				i += n;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << square[i][j] << '\t';
		}
		cout << endl << endl;
	}

	for (i = 0; i < n; i++) {
		delete[]square[i];
	}
    delete []square;
	getch();
	return 0;
}
