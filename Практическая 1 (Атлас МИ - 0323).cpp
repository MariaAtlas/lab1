

#include <iostream>

using namespace std;

short int menu()
{
	short int x;
	cout << "Введите номер задачи:\n";
	cout << "1) Вывести, сколько памяти (в байтах) отводится под различные типы данных:\n";
	cout << "2) Вывести на экран двоичное представление в памяти целого числа\n";
	cout << "3) Вывести на экран двоичное представление в памяти типа float\n";
	cout << "4) Выход\n";
	while (1)
	{
		cin >> x;
		if (x > 0 & x < 5)
			break;
		else
			cout << "Неверный ввод\n";
	}
	cout << "\n";
	return x;
}

void size_of()
{
	cout << "int - " << sizeof(int) << "\n";
	cout << "short int - " << sizeof(short int) << "\n";
	cout << "long int - " << sizeof(long int) << "\n";
	cout << "float - " << sizeof(float) << "\n";
	cout << "double - " << sizeof(double) << "\n";
	cout << "long double - " << sizeof(long double) << "\n";
	cout << "char - " << sizeof(char) << "\n";
	cout << "bool - " << sizeof(bool) << "\n\n";
}

void int_binary() {
	int value = 0; 
	unsigned int rank = 32; //кол-во разрядов
	cout << "Введите число типа int: ";
	cin >> value;
	unsigned int mask = 1 << rank - 1; //маска побитового сравнения
	cout << "Это число в двоичном коде: \n";
	for (int i = 0; i < rank; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if ((i % rank) - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << "\n\n";
}

void float_binary() {
	union
	{
		float value;
		int floatval;
	};
	int arr[32];
	cout << "Введите число типа float: ";
	cin >> value;
	unsigned int mask = 1 << 31;
	cout << "Это число в двоичном коде: \n";
	for (int i = 0; i < 32; i++)
	{
		if (floatval & mask)
			arr[i] = 1;
		else
			arr[i] = 0;
		putchar(floatval & mask ? '1' : '0');
		floatval <<= 1;
		if (i == 0 || i == 8)
			putchar(' ');
	}
	
	cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	short int choice, exit = 0;

	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			size_of();
			break;

		case 2:
			int_binary();
			break;

		case 3:
			float_binary();
			break;

		case 4:
			exit = 1;
			break;
		}
		if (exit == 1)
			break;
	}
}

