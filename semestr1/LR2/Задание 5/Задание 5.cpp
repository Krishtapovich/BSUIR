#pragma hdrstop
#pragma argsused

#include <iostream>
#include <tchar.h>
#include <conio.h>

#include <stdio.h>
using namespace std;
int _tmain()
{   float a, b, c, d, Z;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "d = ";
	cin >> d;
	if(c >= d && a < d){
		Z = a + (b / c);
		cout << "Z = " << Z;
	} else if(c < d && a >= d){
		Z = a - (b / c);
		cout << "Z = " << Z;
	} else {
		Z = 0;
		cout << "Z = " << Z;
    }
	getch();
	return 0;
}
