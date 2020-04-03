#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int sum(int n) {
	if (n == 1) return 1;
	else return pow((n + 1) / 2, 2) + sum(n/2);
}

int _tmain(){
	int n, k;
	cout << "How many times do you want to perform tests: ";
	cin >> k;
	cout << "Enter n: " << endl;

	int* arr = new int[k];
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		if (n == 0)break;
		arr[i] = sum(n);
	}
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		if (arr[i] > 0)cout << arr[i] << endl;
	}
	delete[]arr;
	getch();
	return 0;
}
