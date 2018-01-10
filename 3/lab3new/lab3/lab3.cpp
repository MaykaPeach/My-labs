// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//Долматова Майя, 91гр

/*Реализовать шаблон класса двусвязный (двунаправленный) список (DoublyLinkedList<X>), хранящий элементы произвольного типа.
Класс должен содержать:
- Инициализация списка;
- Добавление элемента в начало списка;
- Добавление элемента в конец списка;
- Показ всех элементов списка.

b)
- Поиск данного значения в списке;
- Поиск наибольшего и наименьшего значений в списке;
- Удаление элемента списка с данным значением;
- Удаление всех элементов списка с данным значением;
- Изменение всех элементов списка с данным значением на новое;*/

#include <iostream>
#include "stdafx.h"
#include <string>
#include "List.cpp"

template <typename T>
void Program(DoublyLinkedList<T> L)
{
	int n;
	do {
		cout << "Menu:\n"
			<< "1 - Get size of the list\n"
			<< "2 - Add an element to the beginning of list\n"
			<< "3 - Add an element to the end of list\n"
			<< "4 - Find the element with needed value\n"
			<< "5 - Find minimum and maximum in the list\n"
			<< "6 - Delete the element with needed value\n"
			<< "7 - Delete all elements with needed value\n"
			<< "8 - Change all elements with needed value\n"
			<< "9 - Print the list\n"
			<< "0 - Exit\n"
			<< "Answer --->  ";
		cin >> n;
		switch (n)
		{
		case 1: cout << L.get_length() << endl; 
				break;
		case 2: {
					T el;
					cout << "Enter new element: " << endl;
					cin >> el;
					L.add_first(el);
				} 
				break;
		case 3: {
					T el;
					cout << "Enter new element: " << endl;
					cin >> el;
					L.add_last(el);
				} 
				break;
		case 4: {
					if (L.get_length() == 0) 
					{ 
						cout << "the list is empty" << endl; 
						break; 
					}
					T el;
					cout << "Enter the element which you find: " << endl;
					cin >> el;
					if (L.find_elem(el))
						cout << "\nElement was found!" << endl << endl;
					else cout << "\nElement wasn't found!" << endl << endl;
				} 
				break;
		case 5: {
					if (L.get_length() == 0)
					{
						cout << "the list is empty" << endl;
						break;
					}
					T min, max;
					L.find_min(min); 
					L.find_max(max);
					cout << "\nMinimum = " << min << endl;
					cout << "\nMaximum = " << max << endl << endl;
				}
				break;
		case 6: {
					if (L.get_length() == 0)
					{
						cout << "the list is empty" << endl;
						break;
					}
					T el;
					cout << "Enter the value of element which you would delete: " << endl;
					cin >> el;
					if (L.delete_elem(el))
						cout << "\nElement was deleted!" << endl << endl;
					else cout << "\nElement wasn't deleted!" << endl << endl;
				}
				break;
		case 7: {
					if (L.get_length() == 0)
					{
						cout << "the list is empty" << endl;
						break;
					}
					T el;
					cout << "Enter the value of elements which you would delete: " << endl;
					cin >> el;
					if (L.find_elem(el))
					{
						L.delete_all_elems(el);
						cout << "\nDone!" << endl << endl;
					}
					else cout << "\nElement weren't found!" << endl << endl;
				}
				break;
		case 8: {
					if (L.get_length() == 0)
					{
						cout << "the list is empty" << endl;
						break;
					}
					T el, new_el;
					cout << "Enter the value of elements which you would change: " << endl;
					cin >> el;
					if (L.find_elem(el))
					{
						cout << "Enter new value of elements: " << endl;
						cin >> new_el;
						if (L.change_all_elems(el, new_el))
						cout << "\nDone!" << endl << endl;
					}
					else cout << "\nElement weren't found!" << endl << endl;
				}
				break;
		case 9: {
					if (L.get_length() == 0)
					{ 
						cout << "the list is empty" << endl; 
						break; 
					}
					L.print(); break;
				}
		case 0: cout << "Bye-Bye!"; break;
		default: cout << "Error! Invalid input!" << endl;
		}
	} while (n != 0);
}

void Test(DoublyLinkedList<int> I, DoublyLinkedList<string> S)
{

	int arr_int[] = { 1, 2, 3, 4, 97, 3, 4, 78 };
	for (int i = 0; i < 8; ++i) {
		I.add_last(arr_int[i]);
	}
	cout << "\nList: " << endl;
	I.print();

	int i_el;
	cout << "Enter the element which you find: " << endl;
	cin >> i_el;
	if (I.find_elem(i_el))
		cout << "\nElement was found!" << endl << endl;
	else cout << "\nElement wasn't found!" << endl << endl;

	cout << "Enter the value of element which you would delete: " << endl;
	cin >> i_el;
	if (I.delete_elem(i_el))
		cout << "\nElements was deleted!" << endl << endl;
	else cout << "\nElement wasn't deleted!" << endl << endl;
	I.print();

	int i_min, i_max;
	I.find_min(i_min);
	I.find_max(i_max);
	cout << "\nMinimum = " << i_min << endl;
	cout << "\nMaximum = " << i_max << endl << endl;
	I.print();

	cout << "Enter the value of elements which you would delete: " << endl;
	cin >> i_el;
	if (I.find_elem(i_el))
	{
		I.delete_all_elems(i_el);
		cout << "\nDone!" << endl << endl;
		I.print();
	}
	else cout << "\nElement weren't found!" << endl << endl;
	

	int i_new_el;
	cout << "Enter the value of elements which you would change: " << endl;
	cin >> i_el;
	if (I.find_elem(i_el))
	{
		cout << "Enter new value of elements: " << endl;
		cin >> i_new_el;
		if (I.change_all_elems(i_el, i_new_el))
			cout << "\nDone!" << endl << endl;
		I.print();
	}
		else cout << "\nElement weren't found!" << endl << endl;


	string arr_str[] = { "a", "b", "c", "bb", "b", "cc", "c", "def" };
	for (int i = 0; i < 8; ++i) {
		S.add_last(arr_str[i]);
	}
	cout << "\nList:" << endl;
	S.print();

	string s_el;
	cout << "Enter the element which you find: " << endl;
	cin >> s_el;
	if (S.find_elem(s_el))
		cout << "\nElement was found!" << endl << endl;
	else cout << "\nElement wasn't found!" << endl << endl;

	cout << "Enter the value of element which you would delete: " << endl;
	cin >> s_el;
	if (S.delete_elem(s_el))
		cout << "\nElements was deleted!" << endl << endl;
	else cout << "\nElement wasn't deleted!" << endl << endl;
	S.print();

	string s_min, s_max;
	S.find_min(s_min);
	S.find_max(s_max);
	cout << "\nMinimum = " << s_min << endl;
	cout << "\nMaximum = " << s_max << endl << endl;
	S.print();

	cout << "Enter the value of elements which you would delete: " << endl;
	cin >> s_el;
	if (S.find_elem(s_el))
	{
		S.delete_all_elems(s_el);
		cout << "\nDone!" << endl << endl;
		S.print();
	}
	else cout << "\nElement weren't found!" << endl << endl;

	string s_new_el;
	cout << "Enter the value of elements which you would change: " << endl;
	cin >> s_el;
	if (S.find_elem(s_el))
	{
		cout << "Enter new value of elements: " << endl;
		cin >> s_new_el;
		if (S.change_all_elems(s_el, s_new_el))
			cout << "\nDone!" << endl << endl;
		S.print();
	}
	else cout << "\nElement weren't found!" << endl << endl;
}


int main()
{
	DoublyLinkedList<int> I;
	DoublyLinkedList<string> S;

	int ans;
	cout << "Choose the action: \n1 - See result of tests,\n2 - Check the program yourself" << endl;
	cin >> ans;
	switch (ans)
	{
		case 1: Test(I, S); break;

		case 2: {
					int n;
					cout << "Choose data type: \n1 - integer, 2 - string" << endl;
					cin >> n;
					if (n == 1) Program(I);
					else if (n == 2) Program(S);
				} 
				break;
	}
	system("pause");
	return 0;
}
