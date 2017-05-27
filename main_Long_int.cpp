//(интерфейс)
#include "Long_int.h"

void menu(int key)
{
	switch (key)
	{
	case 1:
	{
		cout << "Enter values:" << endl;
		break;
	}
	case 2:
	{
		cout << "Select an action:" << endl;
		cout << "1 - Summand\n2 - Division\n3 - Summary\n4 - Substraction\n5 - Get number by digit\n0 - Exit" << endl;
		break;
	}
	case 3:
	{
		cout << "Enter digit and object number:" << endl;
		break;
	}
	case 4:
	{
		cout << "Total objects: ";
		break;
	}
	case 5:
	{
		cout << "= ";
		break;
	}
	default:
		cerr << "Error!" << endl;
	}
}

void main()
{
	bool flag = true;

	while (flag != !flag)
	{
		int menu_key = 0;
		menu(1);
		char *stroke = new char[100];
		cin.get(stroke, 100);
		Long_int val1(stroke);
		cin.ignore(strlen(stroke), '\n');
		cin.get(stroke, 100);
		Long_int val2(stroke);
		Long_int result;
		cin.ignore(strlen(stroke), '\n');
		delete[] stroke;
		menu(2);
		cin >> menu_key;
		cin.ignore(1, '\n');

		switch (menu_key)//вызываем функции
		{
		case 1://умножение
		{
			result = val1.summand(val2);
			break;
		}
		case 2://деление
		{
			result = val1.division(val2);
			break;
		}
		case 3://сложение
		{
			result = val1.summary(val2);
			break;
		}
		case 4://вычитание
		{
			result = val1.substraction(val2);
			break;
		}
		case 5://вывод цифры
		{
			int index = -1, key = 0;
			menu(3);
			cin >> index;
			cin.ignore(1, '\n');
			cin >> key;
			cin.ignore(1, '\n');
			switch (key)
			{
			case 1:
			{
				index = val1.get_digit(index - 1);
				break;
			}
			case 2:
			{
				index = val2.get_digit(index - 1);
				break;
			}
			default:
				index = -1;
			}
			if (index >= 0)
				cout << index << endl;
			else
				menu(0);
			break;
		}
		case 0:
		{
			menu(4);
			cout << Long_int::get_count_objects() << endl;
			exit(0);
		}
		default:
		{
			menu(0);
		}
		}
		if (menu_key > 0 && menu_key < 5)
		{
			cout << result.get_symbol();
			for (int i = 0; i < result.get_length(); i++)
			{
				cout << result.get_digit(i);
			}
			cout << endl;
			cout<<"long long "<<result.to_long()<<endl;
			cout << Long_int::get_count_objects() << endl;
		}
	}
}
