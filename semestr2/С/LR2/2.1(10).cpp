#include <stdio.h>
#include <windows.h>

void menu();
int check();
void commands();
void calc(int, int, int, int);

int main()
{
	SetConsoleOutputCP(1251);
	menu();
	return 0;
}

void menu()
{
	int euro_price = 0, year = 0, engine = 0, dist = 0;
	int n;
	do
	{
		commands();
		n = check();
		switch (n)
		{
		case 1:
			printf("Стоимость в Европе(€): ");
			euro_price = check();
			break;
		case 2:
			printf("Год выпуска: ");
			year = check();
			break;
		case 3:
			printf("Объем двигателя(см.куб.): ");
			engine = check();
			break;
		case 4:
			printf("Расстояние прогона(км): ");
			dist = check();
			break;
		case 5:
			calc(euro_price, 2020 - year, engine, dist);
			system("pause");
			break;
		case 6:
			printf("GrossTransport v2.2.8, Mikhail Kryshtapovich\n");
			system("pause");
			break;
		default:
			printf("Выход");
			break;
		}
	} while (n >= 1 && n <= 6);
}

int check()
{
	int a = 1;
	rewind(stdin);
	while (!scanf_s("%d", &a) || (a < 0))
	{
		rewind(stdin);
		printf("Неправильный ввод, введите корректные данные: ");
	}
	return a;
}

void commands()
{
	system("cls");
	printf("1 - Ввод стоимости автомобиля в Европе\n");
	printf("2 - Ввод года выпуска автомобиля\n");
	printf("3 - Ввод объема двигателя\n");
	printf("4 - Ввод расстояния прогона\n");
	printf("5 - Рассчет стоимости услуги\n");
	printf("6 - Информация о версии программы и о авторе\n");
	printf("Введите команду: ");
}

void calc(int euro, int year, int engine, int dist)
{
	if (euro == 0 || year < 0 || engine == 0 || dist == 0)
		printf("Вы не ввели некоторые параметры или ввели не корректно\n");
	else {
		float rast;
		if (year < 3)
		{
			rast = engine * 0.6;
		}
		else if (year > 3 && year <= 10)
		{
			if (engine < 2500)
			{
				rast = engine * 0.35;
			}
			else
			{
				rast = engine * 0.6;
			}
		}
		else if (year > 10 && year <= 14)
		{
			rast = engine * 0.6;
		}
		else
		{
			rast = engine * 2;
		}
		float total = euro + rast + 0.5 * dist;
		printf("Итого(€): %d\n", (int)total);
	}
}