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
using namespace std;
class Bill
{
private:
	string tel;
	float rate;
	float sale;
	float talk_time;
	float sum;
	float allsum;
public:
	Bill() { tel = "0";  rate = 0; sale = 0; talk_time = 0;  sum = 0; allsum = 0; };
	void Read(); // ввод телефонного номера, тарифа, скидки.
	void Display(); // печать телефонного номера, тарифа, скидки
	string ToString(); //перевод данных в строку
	void Add_PhConv(); //добававление телефонного разговора
	void Change_Rate();  //изменить тариф
	float Last_Total(); // подсчет суммы оплаты последнего телефонного разговора
	float All_Total(); //подсчет общей суммы
};

void Bill::Read()
{
	cout << "Enter the telephone number: " << endl;
	cin >> tel;
	cout << "Enter the rate of one minute of talking: " << endl;
	cin >> rate;
	cout << "Enter the sale(%) of rate: " << endl;
	cin >> sale;
	cout << "Enter the talk time (minutes): " << endl;
	cin >> talk_time;
	sum = (1 - sale / 100)*rate*talk_time;
	allsum = sum;
}

void Bill::Display()
{
	cout << "The information about phone conversation" << endl;
	cout << "The telephone number: " << tel << endl;
	cout << "The rate of one minute of talking: " << rate << " rub" << endl;
	cout << "The sale of rate: " << sale << "%" << endl;
	cout << "The talk time: " << talk_time << "min" << endl;
	cout << "The sum of last conversation: " << Bill::Last_Total() << " rub" << endl;
	cout << "The sum of all conversations: " << Bill::All_Total() <<  " rub" << endl;

}

string Bill::ToString()
{
	string str = "For this number of telephone " + tel + " rate is " + to_string(rate) + " rub for one minute. Sale is " + to_string(sale) + "%. Talk time is " + to_string(talk_time) + " minutes.";
	cout << str <<endl;
	return str;
}

void Bill::Add_PhConv()
{
	cout << "Enter the talk time (minutes): " << endl;
	cin >> talk_time;
	allsum += (1 - sale / 100)*rate*talk_time;
}

void Bill::Change_Rate()
{
	cout << "Enter the rate of one minute of talking: " << endl;
	cin >> rate;
	cout << "Enter the sale for rate: " << endl;
	cin >> sale;
}

float Bill::Last_Total()
{
	sum = (1 - sale / 100)*rate*talk_time;
	return sum;
}
float Bill::All_Total()
{
	return allsum;
}

int main()
{
	Bill t;
	int num;
	for (;;)
		for (; ;)
		{
			cout << " Menu " << endl;
			cout << "1 - Enter the information about phone conversation" << endl;
			cout << "2 - Show the information about phone conversation" << endl;
			cout << "3 - Show the infotmation in a string " << endl;
			cout << "4 - Add one more phone conversation" << endl;
			cout << "5 - Change the rate " << endl;
			cout << "6 - Last conversation total" << endl;
			cout << "7 - All conversations total" << endl;
			cout << "0 - Exit" << endl << endl;
			cout << "Enter your answer ----> ";
			cin >> num;

			switch (num)
			{
			case 1: t.Read(); break;
			case 2: t.Display(); break;
			case 3: t.ToString(); break;
			case 4: t.Add_PhConv(); break;
			case 5: t.Change_Rate(); break;
			case 6: {
						cout << "Sum of last phone conversation: " << t.Last_Total() << " rub" << endl;
						break;
					}
			case 7: {
						cout << "Sum of last phone conversation: " << t.All_Total() << " rub" << endl;
						break;
					}
			case 0: cout << " Bye - bye! " << endl; exit(1); break;
			default: cout << "Error! Invalid input! " << endl; break;
			}
			getchar();

		}
	system("pause");
}
