#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

class Participant
{
private:
	string country;
	string team;
	string surname;
	string name;
	string patronymic;
	int number = 0;
	int age = 0;
	int height = 0;
	int weight = 0;
public:
	Participant* Reading(Participant* object, string input, int amount)
	{
		ifstream fin(input);
		for (int i = 0; i < amount; i++)
		{
			fin >> object[i].country >> object[i].team >> object[i].surname >> object[i].name >> object[i].patronymic >> object[i].number >> object[i].age >> object[i].height >> object[i].weight;
		}
		fin.close();
		return object;
	}

	Participant* SetData(Participant* object, int num)
	{
		cout << "Страна: ";
		cin >> object[num].country;
		cout << "Команда: ";
		cin >> object[num].team;
		cout << "Фамилия: ";
		cin >> object[num].surname;
		cout << "Имя: ";
		cin >> object[num].name;
		cout << "Отчество: ";
		cin >> object[num].patronymic;
		cout << "Номер: ";
		cin >> object[num].number;
		cout << "Возраст: ";
		cin >> object[num].age;
		cout << "Рост: ";
		cin >> object[num].height;
		cout << "Вес: ";
		cin >> object[num].weight;
		return object;
	}

	void GetData(Participant* object, int amount)
	{
		system("cls");
		cout << '№' << "  " << "Страна\t" << "Команда\t\t" << "Фамилия\t\t" << "Имя\t" << "Отчество\t" << "Номер\t" << "Возраст\t" << "Рост\t" << "Вес" << endl;
		for (int i = 0; i < amount; i++)
		{
			cout << i + 1 << "  " << object[i].country << '\t' << object[i].team << "\t\t" << object[i].surname << "\t\t" << object[i].name << '\t' << object[i].patronymic << '\t' << object[i].number << '\t' << object[i].age << '\t' << object[i].height << '\t' << object[i].weight << endl;
		}
		cout << endl << endl;
	}

	Participant* add_new(Participant* list, int& amount)
	{
		system("cls");
		Participant* new_list = new Participant[amount + 1];
		for (int i = 0; i < amount; i++)
		{
			new_list[i] = list[i];
		}
		new_list->SetData(new_list, amount);
		delete[]list;
		amount++;
		return new_list;
	}

	Participant* change(Participant* list, int amount)
	{
		GetData(list, amount);
		cout << "Выберите номер спортсмена, о котором хотите изменить данные: ";
		int num;
		cin >> num;
		SetData(list, num - 1);
		return list;
	}

	void Writing(Participant* list, int amount, string output)
	{
		string* temp = new string[amount];
		for (int i = 0; i < amount; i++) temp[i] = list[i].team;
		for (int i = 0; i < amount; i++)
		{
			for (int j = i + 1; j < amount; j++)
			{
				if (temp[i] == temp[j])temp[j] = "#";
			}
		}
		int num = 0;
		for (int i = 0; i < amount; i++)
		{
			if (temp[i] != "#")num++;
		}

		string* arr = new string[num];
		for (int i = 0, j = 0; i < amount; i++)
		{
			if (temp[i] != "#")
			{
				arr[j] = temp[i];
				j++;
			}
		}
		delete[]temp;

		int* sp_in_team = new int[num];
		for (int i = 0; i < num; i++)sp_in_team[i] = 0;
		for (int i = 0; i < amount; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (list[i].team == arr[j])
				{
					sp_in_team[j]++;
				}
			}
		}
		int* sum_age = new int[num];
		for (int i = 0; i < num; i++)sum_age[i] = 0;
		for (int i = 0; i < amount; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (list[i].team == arr[j])sum_age[j] += list[i].age;
			}
		}
		int* av_age = new int[num];
		for (int i = 0; i < num; i++) av_age[i] = sum_age[i] / sp_in_team[i];
		int min = 200, index;
		for (int i = 0; i < num; i++)
		{
			if (av_age[i] < min)
			{
				min = av_age[i];
				index = i;
			}
		}
		delete[]sp_in_team;
		delete[]sum_age;
		delete[]av_age;
		ofstream fout(output, ofstream::app);
		cout << '№' << "  " << "Страна\t" << "Команда\t\t" << "Фамилия\t\t" << "Имя\t" << "Отчество\t" << "Номер\t" << "Возраст\t" << "Рост\t" << "Вес" << endl;
		for (int i = 0,j =1; i < amount; i++)
		{
			if (list[i].team == arr[index])
			{
				fout << list[i].country << " " << list[i].team << " " << list[i].surname << " " << list[i].name << " " << list[i].patronymic << " " << list[i].number << " " << list[i].age << " " << list[i].height << " " << list[i].weight << endl;
				cout << j << "  " << list[i].country << '\t' << list[i].team << "\t\t" << list[i].surname << "\t\t" << list[i].name << '\t' << list[i].patronymic << '\t' << list[i].number << '\t' << list[i].age << '\t' << list[i].height << '\t' << list[i].weight << endl;
				j++;
			}
		}
		fout << endl;
		fout.close();
		cout << endl << endl;
		delete[]arr;
	}

	Participant* delete_sportsman(Participant* list, int& amount)
	{
		GetData(list, amount);
		int num;
		cout << "Введите номер спортсмена, которого хотите удалить: ";
		cin >> num;
		Participant* new_list = new Participant[amount - 1];
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
		return new_list;
	}
};

int count(string input)
{
	string s;
	ifstream fin("input.txt");
	int count = 0;
	while (getline(fin, s))
	{
		count++;
	}
	return count;
}

void menu(int& amount, string input, string output);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string input = "input.txt", output = "output.txt";
	int amount = count(input);
	menu(amount, input, output);
	return 0;
}

void menu(int& amount, string input, string output)
{
	int n;
	Participant* list = new Participant[amount];
	list = list->Reading(list, input, amount);
	do {
		cout << "1 - Добавить спортсмена" << endl;
		cout << "2 - Удалить спортсмена" << endl;
		cout << "3 - Изменить данные о спортсмене" << endl;
		cout << "4 - Просмотр списка спортсменов" << endl;
		cout << "5 - Вывод самой молодой команды" << endl;
		cout << "Введите номер функции: ";
		cin >> n;
		switch (n)
		{
		case 1:
			list = list->add_new(list, amount);
			system("cls");
			break;
		case 2:
			system("cls");
			list = list->delete_sportsman(list, amount);
			list->GetData(list, amount);
			break;
		case 3:
			list->change(list, amount);
			system("cls");
			break;
		case 4:
			list->GetData(list, amount);
			break;
		case 5:
			system("cls");
			list->Writing(list, amount, output);
			break;
		default: break;
		}
	} while (n >= 1 && n <= 5);
	delete[]list;
}