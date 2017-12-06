// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
/*6. Реализовать класс Bill, представляющий собой разовый платеж за телефонный
разговор.
Класс должен включать в себя поля:
- номера телефона,
- тарифа за минуту разговора,
- скидки (в процентах),
- времени разговора (в минутах)
- суммы к оплате.
Реализовать метод вычисления суммы к оплате.
В главной программе продемонстрировать:
- создание,
- инициализацию
- обработку массива объектов типа Вill с различными исходными данными для вычисления сумм к оплате.
Вычислить общую сумму к оплате.*/

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include "Bill.h"
#include <vector>
using namespace std;

int main()
{
	vector<Bill*> bills;
	cout << "Enter the information about phone conversation" << endl;
	Bill *t = Bill::Read();
	int num;
	float total_sum = 0;
	for (;;)
		for (; ;)
		{
			cout << " Menu " << endl;
			cout << "1 - Show the information about phone conversation" << endl;
			cout << "2 - Show the infotmation in a string " << endl;
			cout << "3 - Add one more information about phone conversation" << endl;
			cout << "4 - Change the rate " << endl;
			cout << "5 - Last conversation total" << endl;
			cout << "6 - All conversations total" << endl;
			cout << "0 - Exit" << endl << endl;
			cout << "Enter your answer ----> ";
			cin >> num;

			switch (num)
			{
			case 1: t->Display(); break;
			case 2: t->ToString(); break;
			case 3:
			{
				total_sum += t->Last_Total();
				bills.push_back(t);
				t = Bill::Read();

				break;
			}
			case 4: {
				t->Change_Rate();
				break;
			}
			case 5: {
				cout << "Sum of last phone conversation: " << t->Last_Total() << " rub" << endl;
				break;
			}
			case 6: {
				cout << "TOTAL SUM: " << total_sum + t->Last_Total() << " rub" << endl;
				break;
			}
			case 0: cout << " Bye - bye! " << endl; exit(1); break;
			default: cout << "Error! Invalid input! " << endl; break;
			}
			getchar();

		}
	system("pause");
}
