#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Worker
{
private:
	string surname;
	string name;
	string patronymic;
	int department = 0;
	string position;
	int experience = 0;
public:
	Worker* change_worker(Worker* list, int amount)
	{
		int num;
		cout << "Введите номер сотрудника в списке: ";
		cin >> num;
		SetData(list, num - 1);
		system("cls");
		return list;
	}
	
	void GetData(Worker* list, int amount)
	{
		cout << "№  " << "ФАМИЛИЯ\t\t" << "ИМЯ\t\t" << "ОТЧЕСТВО\t" << "НОМЕР ОТДЕЛА\t" << "ДОЛЖНОСТЬ\t\t" << "ОПЫТ РАБОТЫ" << endl;
		for (int i = 0; i < amount; i++)
		{
			cout << i + 1 << "  " << list[i].surname << "\t\t" << list[i].name << "\t\t" << list[i].patronymic << '\t' << list[i].department << "\t\t" << list[i].position << "\t\t" << list[i].experience << endl;
		}
		cout << endl << endl;
	}
	
	Worker* list_of_workers(int& amount)
	{
		int yes_or_not = 1;
		Worker* list = 0;
		while (yes_or_not == 1)
		{
			list = add_new(list, amount);
			SetData(list, amount);
			system("cls");
			amount++;
			cout << "Продолжить ввод(1 - да, 0 - нет): ";
			cin >> yes_or_not;
			system("cls");
		}
		return list;
	}
	
	Worker* add_new(Worker* list, int amount)
	{
		if (amount == 0)
		{
			list = new Worker[amount + 1];
			return list;
		}
		else
		{
			Worker* templist = new Worker[amount + 1];
			for (int i = 0; i < amount; i++)
			{
				templist[i] = list[i];
			}
			delete[]list;
			return templist;
		}
	}

	Worker* add_new_worker(Worker* list, int& amount)
	{
		list = add_new(list, amount);
		SetData(list, amount);
		amount++;
		system("cls");
		return list;
	}
	
	void show_worker(Worker* list, int amount)
	{
		string charact, text;
		int num;
		cout << "Введите характеристику(Фамилия, Имя, Отчество, Номер отдела, Должность, Опыт работы): ";
		cin.get();
		getline(cin, charact);
		if (charact == "Фамилия" || charact == "Имя" || charact == "Отчество" || charact == "Должность")
		{
			cout << "Введите значение: ";
			getline(cin, text);
			system("cls");
			cout << "№  " << "ФАМИЛИЯ\t\t" << "ИМЯ\t\t" << "ОТЧЕСТВО\t" << "НОМЕР ОТДЕЛА\t" << "ДОЛЖНОСТЬ\t\t" << "ОПЫТ РАБОТЫ" << endl;
			for (int i = 0, j = 0; i < amount; i++)
			{
				if (text == list[i].surname || text == list[i].name || text == list[i].patronymic || text == list[i].position)
				{
					cout << j + 1 << "  " << list[i].surname << "\t\t" << list[i].name << "\t\t" << list[i].patronymic << '\t' << list[i].department << "\t\t" << list[i].position << "\t\t" << list[i].experience << endl;
					j++;
				}
			}
		}
		else if (charact == "Номер отдела" || charact == "Опыт работы")
		{
			cout << "Введите значение: ";
			cin >> num;
			system("cls");
			cout << "№  " << "ФАМИЛИЯ\t\t" << "ИМЯ\t\t" << "ОТЧЕСТВО\t" << "НОМЕР ОТДЕЛА\t" << "ДОЛЖНОСТЬ\t\t" << "ОПЫТ РАБОТЫ" << endl;
			for (int i = 0, j = 0; i < amount; i++)
			{
				if (num == list[i].department || num == list[i].experience)
				{
					cout << j + 1 << "  " << list[i].surname << "\t\t" << list[i].name << "\t\t" << list[i].patronymic << '\t' << list[i].department << "\t\t" << list[i].position << "\t\t" << list[i].experience << endl;
					j++;
				}
			}
		}
		cout << endl << endl;
	}

	Worker* SetData(Worker* list, int amount)
	{
		cout << "Фамилия: ";
		cin >> list[amount].surname;
		cout << "Имя: ";
		cin >> list[amount].name;
		cout << "Отчество: ";
		cin >> list[amount].patronymic;
		cout << "Номер отдела: ";
		cin >> list[amount].department;
		cout << "Должность: ";
		cin.get();
		getline(cin, list[amount].position);
		cout << "Опыт работы: ";
		cin >> list[amount].experience;
		return list;
	}

	Worker* delete_worker(Worker* list, int& amount)
	{
		int num;
		Worker* new_list = new Worker[amount - 1];
		cout << "Введите номер сотрудника, которого хотите удалить из списка: ";
		cin >> num;
		for (int i = 0, j = 0; i < amount; i++)
		{
			if (i == num - 1)
			{
				continue;
			}
			else
			{
				new_list[j] = list[i];
				j++;
			}
		}
		amount--;
		delete[]list;
		system("cls");
		return new_list;
	}

	void ShakerSort(Worker* list, int amount)
	{
		int left = 0, right = amount - 1, flag = 1;
		while ((left < right) && flag > 0)
		{
			flag = 0;
			for (int i = left; i < right; i++)
			{
				if (list[i].experience > list[i + 1].experience)
				{
					Worker temp = list[i];
					list[i] = list[i + 1];
					list[i + 1] = temp;
					flag = 1;
				}
			}
			right--;
			for (int i = right; i > left; i--)
			{
				if (list[i - 1].experience > list[i].experience)
				{
					Worker temp = list[i];
					list[i] = list[i - 1];
					list[i - 1] = temp;
					flag = 1;
				}
			}
			left++;
		}
		GetData(list, amount);
	}

	void main_task(Worker* list, int amount)
	{
		cout << "№  " << "ФАМИЛИЯ\t\t" << "ИМЯ\t\t" << "ОТЧЕСТВО\t" << "НОМЕР ОТДЕЛА\t" << "ДОЛЖНОСТЬ\t\t" << "ОПЫТ РАБОТЫ" << endl;
		for (int i = 0, j = 0; i < amount; i++)
		{
			if (list[i].experience > 20)
			{
				cout << j + 1 << "  " << list[i].surname << "\t\t" << list[i].name << "\t\t" << list[i].patronymic << '\t' << list[i].department << "\t\t" << list[i].position << "\t\t" << list[i].experience << endl;
				j++;
			}
		}
		cout << endl << endl;
	}
};

void menu(int& amount);

int main()
{
	int amount = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu(amount);
	return 0;
}

void menu(int& amount)
{
	int n;
	Worker* list = 0;
	list = list->list_of_workers(amount);
	do {
		cout << "1 - Просмотреть список сотрудников" << endl;
		cout << "2 - Добавить сотрудников в список" << endl;
		cout << "3 - Показать сотрудника с заданным параметром" << endl;
		cout << "4 - Изменить данные о сотруднике с заданным параметром" << endl;
		cout << "5 - Удалить сотрудника из списка" << endl;
		cout << "6 - Отсортировать список сотрудников по опыту работы" << endl;
		cout << "7 - Вывести сотрудников, чей опыт работы превышает 20 лет" << endl;
		cout << "Введите команду: ";
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
			list->GetData(list, amount);
			break;
		case 2:
			list = list->add_new_worker(list, amount);
			list->GetData(list, amount);
			break;
		case 3:
			list->show_worker(list, amount);
			break;
		case 4:
			list->GetData(list, amount);
			list = list->change_worker(list, amount);
			list->GetData(list, amount);
			break;
		case 5:
			list->GetData(list, amount);
			list = list->delete_worker(list, amount);
			list->GetData(list, amount);
			break;
		case 6:
			list->ShakerSort(list, amount);
			break;
		case 7:
			list->main_task(list, amount);
			break;
		default: break;
		}
	} while (n >= 1 && n <= 7);
	delete[]list;
}