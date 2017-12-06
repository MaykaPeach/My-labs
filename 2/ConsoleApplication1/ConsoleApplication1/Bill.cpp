
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Bill.h"

using namespace std;

Bill::Bill() 
{
	tel = "";  rate = 0; sale = 0; talk_time = 0;  sum = 0; 
};

Bill* Bill::Read()
{
	Bill *conv = nullptr;
	conv = new Bill;
	cout << "Enter the telephone number: " << endl;
	cin >> conv->tel;
	cout << "Enter the rate of one minute of talking: " << endl;
	cin >> conv->rate;
	do
	{
		cout << "Enter the sale(%) of rate: " << endl;
		cin >> conv->sale;
	} while (conv->sale < 0 || conv->sale > 100);
	cout << "Enter the talk time (minutes): " << endl;
	cin >> conv->talk_time;
	conv->sum = (1 - conv->sale / 100)*conv->rate*conv->talk_time;
	return conv;
}

void Bill::Display()
{
	cout << "The information about phone conversation" << endl;
	cout << "The telephone number: " << tel << endl;
	cout << "The rate of one minute of talking: " << rate << " rub" << endl;
	cout << "The sale of rate: " << sale << "%" << endl;
	cout << "The talk time: " << talk_time << "min" << endl;
	cout << "The sum of conversation: " << Bill::Last_Total() << " rub" << endl;

}

string Bill::ToString()
{
	string str = "For this number of telephone " + tel + " rate is " + to_string(rate) + " rub for one minute. Sale is " + to_string(sale) + "%. Talk time is " + to_string(talk_time) + " minutes.";
	cout << str << endl;
	return str;
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