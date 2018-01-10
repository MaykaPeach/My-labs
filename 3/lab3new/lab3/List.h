// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
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

#include "stdafx.h"
#include <iostream> 

using namespace std;


template <typename T>
class DoublyLinkedList
{
private:
		struct Node {
			T info;
			Node* next;
			Node* prew;
			Node(const T& el)
			{
				info = el;
				prew = next = nullptr;
			}
		};
		Node *head, *tail;
		int count;
public:
	DoublyLinkedList();        // конструктор - инициализация
	~DoublyLinkedList();         // деструктор


	int get_length() const { return count; }// вычисление длины
	void add_first(const T &t);		//добавление в начало
	void add_last(const T &t);		//добавление в конец
	void print();			//печать всех элементов списка

	bool find_elem(const T &t);			//найти заданный элемент
	void find_min(T &min);		//найти минимальное значение
	void find_max(T &max);	//найти максимальное значение
	bool delete_elem(const T &t);		//удалить заданный элемент
	void delete_all_elems(const T &t);	//удалить все элементы с заданным значением
	bool change_all_elems(const T &t, const T &new_info);		 //изменить все элементы с заданным значением на новое
};

