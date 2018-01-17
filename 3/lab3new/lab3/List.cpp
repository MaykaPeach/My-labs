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
	Node<T> *elem = head;

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
	Node<T> *elem = new Node<T>(t);	// Создаем новый узел для значения
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
	Node<T> *elem = new Node<T>(t); // Создаем новый узел для значения

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
	Node<T>* elem = head; //Временный указатель на начало списка
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
		Node<T>* elem = head;
		while ((elem != nullptr) && (elem->info != t)) // пока не конец списка и не нашли
		{
			elem = elem->next;
		}
		return (elem != nullptr);  // если элемент  нашелся 

}

template <typename T>
bool DoublyLinkedList<T>::try_find_min(T &min) //найти минимум bool
{
	Node<T>* elem = head;
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
		return true;
	}
	return false;
}

template <typename T>
bool DoublyLinkedList<T>::try_find_max(T &max) //найти минимум
{
	Node<T>* elem = head;
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
		return true;
	}
	return false;
}

template <typename T>
bool DoublyLinkedList<T>::delete_elem(const T &t)		//удалить заданный элемент 
{
	
	Node<T>* elem = head;
	if (elem = find(elem, t))
	{
		del(elem);
		return true;
	}
	else				//если не нашелся
	{
		return false;
	}

}

template <typename T>
void DoublyLinkedList<T>::del(Node<T> *elem)	//удаление
{
	Node<T> *prew_el, *next_el;
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
		}
		delete elem;
	}
	else //last
	{
		if (elem->prew != nullptr)
		{
			tail = elem->prew;
			tail->next = nullptr;
		}
		else {
			head = tail = nullptr;
		}

		delete elem;
	}
	--count;
}

template <typename T>
bool DoublyLinkedList<T>::delete_all_elems(const T &t)	//удалить все элементы с заданным значением
{
	Node<T> *elem = head;
	Node<T> *tmp = head;
	bool deleted = false;
	while (elem = find(elem, t) && (elem != nullptr))
	{
		tmp = elem;
		elem = tmp->next;
		del(tmp);
		deleted = true;
	}
	return deleted;
}

template <typename T>
bool DoublyLinkedList<T>::change_all_elems(const T &t, const T &new_info)	 //изменить все элементы с заданным значением на новое
{
	bool changed = false;
	Node<T> *elem= head;
	while (elem = find(elem,t))
	{
		elem->info = new_info;
		elem = elem->next;
		changed = true;
	}
	return changed;
}

template<typename T>
Node <T>* DoublyLinkedList<T>::find(Node<T>* elem, const T &e)
{
	while (elem != nullptr) // пока не конец списка
		if (elem->info == e) // если элемент нашелся
			return elem;
		else  //если нет
			elem = elem->next;
	return nullptr;
}