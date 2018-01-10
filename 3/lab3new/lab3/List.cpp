#include "stdafx.h"
#include "List.h"


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() //инициализция полей как пустых - конструктор
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}


template<typename T>								//деструктор - освобожение памяти
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node *elem = head;

	while (elem)
	{
		elem = head->next;
		delete(head);
		head = elem;
	}
}


template <typename T>
void DoublyLinkedList<T>::add_first(const T &t) // добавление элемента в начало списка
{
	Node *elem = new Node(t);	// Создаем новый узел для значения
	if (head != nullptr)   // если список не пустой
	{
		elem->next = head;
		head->prew = elem;
	}
	else 
	{
		tail = elem;
	}

	head = elem;
	count++;
}

template <typename T>
void DoublyLinkedList<T>::add_last(const T &t)		//добавление в конец
{
	Node *elem = new Node(t); // Создаем новый узел для значения

	if (tail != nullptr) {
		elem->prew = tail;
		tail->next = elem;
	}
	else {
		head = elem;
	}

	tail = elem;
	count++;
}

template <typename T>
void DoublyLinkedList<T>::print()
{
	Node* elem = head; //Временный указатель на начало списка
	while (elem != nullptr)
	{
		cout << elem->info << ' ';
		elem = elem->next;
	}
	cout << endl;
}

template <typename T>
bool DoublyLinkedList<T>::find_elem(const T &t)  //найти заданный элемент
{
	//int pos = 0;
	if (head != nullptr)
	{
		Node* elem  = head;
		while ((elem != nullptr) && (elem->info != t)) // пока не конец списка и не нашли
		{
			elem = elem->next;
			//pos++;
		}
		if (elem != nullptr)  // если элемент  нашелся 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	/*else
	{
		cout << "List is empty!" << endl;
		return false;
	}*/
}

template <typename T>
void DoublyLinkedList<T>::find_min(T &min) //найти минимум
{
	Node* elem = head;
	if (elem != nullptr)
	{
		min = elem->info;
		while (elem != nullptr) // пока не конец списка и не нашли
		{
			if (elem->info < min)
			{						// если элемент не нашелся 
				min = elem->info;
			}
			elem = elem->next;
		}
	}
	/*else
	{
		cout << "List is empty!" << endl;
	}*/
}

template <typename T>
void DoublyLinkedList<T>::find_max(T &max) //найти минимум
{
	Node* elem = head;
	if (elem != nullptr)
	{
		max = elem->info;
		while (elem != nullptr) // пока не конец списка и не нашли
		{
			if (elem->info > max)
			{						// если элемент не нашелся 
				max = elem->info;
			}
			elem = elem->next;
		}
	}
	/*else
	{
		cout << "List is empty!" << endl;
	}*/
}

template <typename T>
bool DoublyLinkedList<T>::delete_elem(const T &t)		//удалить заданный элемент 
{
	if (head == nullptr) {
		/*cout << "List is empty!" << endl;*/
		return false;
	}
	else
	{
		Node* elem = head;
		Node *prew_el, *next_el;
		while ((elem != nullptr) && (elem->info != t)) // пока не конец списка и не нашли
		{
			elem = elem->next;
		}
		if (elem != nullptr) // если элемент нашелся
		{
			if (elem->next != nullptr) //если не последний элемент
			{
					
					if (elem != head) //если не первый
					{
						next_el = elem->next;
						prew_el = elem->prew;
						prew_el->next = next_el;
						next_el->prew = prew_el;

					}
					else
					{
						head = elem->next;
						head->prew = nullptr;
						//elem->next = nullptr;
					}
					delete elem;
			}
			else
			{
				if (elem->prew != nullptr)
				{
					tail = elem->prew;
				}
				tail->next = nullptr;
				delete elem;
			}
			--count;
			return true;
		}
		else				//если не нашелся
		{
			return false;
		}
	}
}
template <typename T>
void DoublyLinkedList<T>::delete_all_elems(const T &t)	//удалить все элементы с заданным значением
{
	while (delete_elem(t));
}

template <typename T>
bool DoublyLinkedList<T>::change_all_elems(const T &t, const T &new_info)	 //изменить все элементы с заданным значением на новое
{
	if (head == nullptr) {
		/*cout << "List is empty!" << endl;*/
		return false;
	}
	else
	{
		bool ok = true; // элементы с заданным значением есть
		Node* elem = head;
		while (elem != nullptr) // пока не конец списка
		{
			while ((elem != nullptr) && (elem->info != t)) // пока не конец списка и не нашли
			{
				elem = elem->next;
			}
			if (elem != nullptr) // если элемент нашелся
			{
				elem->info = new_info;
			}
		}
	}
}