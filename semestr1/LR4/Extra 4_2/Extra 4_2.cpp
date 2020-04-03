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
// Зaдана матрица A = (aij), i = 1..n, j = 1..m, (n, m <= 100).Упорядочить элементы верхнего левого  треугольника  матрицы включая диагональ, по возрастанию.
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

	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10 - 5;
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl << endl;

	if (n < m) {
		bool exit = false;
		while (!exit) {
			exit = true;
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - 1 - i; j++) {
					if (j + i <= n - 1) {
						if (arr[i][j] > arr[i + 1][j]) {
							int k = arr[i][j];
							arr[i][j] = arr[i + 1][j];
							// сортировка, если число строк меньше числа столбцов
							arr[i + 1][j] = k;
						}
						if (arr[i][j] > arr[i][j + 1]) {
							int temp = arr[i][j];
							arr[i][j] = arr[i][j + 1];
							arr[i][j + 1] = temp;
							exit = false;
						}
					}
				}
			}
		}
	}
	else if (n > m) {
		bool exit = false;
		while (!exit) {
			exit = true;
			for (int i = 0; i < m - 1; i++) {
				for (int j = 0; j < m - 1 - i; j++) {
					if (j + i <= m - 1) {
						if (arr[i][j] > arr[i + 1][j])
							// сортировка, если число строк больше числа столбцов
						{
							int k = arr[i][j];
							arr[i][j] = arr[i + 1][j];
							arr[i + 1][j] = k;
						}
						if (arr[i][j] > arr[i][j + 1]) {
							int temp = arr[i][j];
							arr[i][j] = arr[i][j + 1];
							arr[i][j + 1] = temp;
							exit = false;
						}
					}
				}
			}
		}
	}
	else {
		bool exit = false;
		while (!exit) {
			exit = true;
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < m - 1 - i; j++) {
					if (j + i <= n - 1 && j + i <= m - 1) {
						if (arr[i][j] > arr[i + 1][j])
							// сортировка, если число строк равно числу столбцов
						{
							int k = arr[i][j];
							arr[i][j] = arr[i + 1][j];
							arr[i + 1][j] = k;
						}
						if (arr[i][j] > arr[i][j + 1]) {
							int temp = arr[i][j];
							arr[i][j] = arr[i][j + 1];
							arr[i][j + 1] = temp;
							exit = false;
						}
					}
				}
			}
		}
	}
    cout << "Sotred array:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << "\t"; // вывод отсортированного массива
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
