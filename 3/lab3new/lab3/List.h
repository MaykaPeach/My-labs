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

template <typename T>
class DoublyLinkedList
{
private:
		
		Node<T> *head, *tail;
		int count;
		Node < T>* find(Node<T>* elem, const T &e);
public:
	DoublyLinkedList();        // конструктор - инициализация
	~DoublyLinkedList();         // деструктор


	int get_length() const { return count; }// вычисление длины
	void add_first(const T &t);		//добавление в начало
	void add_last(const T &t);		//добавление в конец
	void print();			//печать всех элементов списка

	bool find_elem(const T &t);			//найти заданный элемент
	bool try_find_min(T &min);		//найти минимальное значение
	bool try_find_max(T &max);	//найти максимальное значение
	bool delete_elem(const T &t);		//удалить заданный элемент
	bool delete_all_elems(const T &t);	//удалить все элементы с заданным значением
	void del(Node<T> *elem);
	bool change_all_elems(const T &t, const T &new_info);		 //изменить все элементы с заданным значением на новое
};

