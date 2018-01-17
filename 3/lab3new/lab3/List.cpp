#include "stdafx.h"
#include "List.h"


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() //������������ ����� ��� ������ - �����������
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}


template<typename T>								//���������� - ����������� ������
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
void DoublyLinkedList<T>::add_first(const T &t) // ���������� �������� � ������ ������
{
	Node<T> *elem = new Node<T>(t);	// ������� ����� ���� ��� ��������
	if (head != nullptr)   // ���� ������ �� ������
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
void DoublyLinkedList<T>::add_last(const T &t)		//���������� � �����
{
	Node<T> *elem = new Node<T>(t); // ������� ����� ���� ��� ��������

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
	Node<T>* elem = head; //��������� ��������� �� ������ ������
	while (elem != nullptr)
	{
		cout << elem->info << ' ';
		elem = elem->next;
	}
	cout << endl;
}

template <typename T>
bool DoublyLinkedList<T>::find_elem(const T &t)  //����� �������� �������
{
		Node<T>* elem = head;
		while ((elem != nullptr) && (elem->info != t)) // ���� �� ����� ������ � �� �����
		{
			elem = elem->next;
		}
		return (elem != nullptr);  // ���� �������  ������� 

}

template <typename T>
bool DoublyLinkedList<T>::try_find_min(T &min) //����� ������� bool
{
	Node<T>* elem = head;
	if (elem != nullptr)
	{
		min = elem->info;
		while (elem != nullptr) // ���� �� ����� ������ � �� �����
		{
			if (elem->info < min)
			{						// ���� ������� �� ������� 
				min = elem->info;
			}
			elem = elem->next;
		}
		return true;
	}
	return false;
}

template <typename T>
bool DoublyLinkedList<T>::try_find_max(T &max) //����� �������
{
	Node<T>* elem = head;
	if (elem != nullptr)
	{
		max = elem->info;
		while (elem != nullptr) // ���� �� ����� ������ � �� �����
		{
			if (elem->info > max)
			{						// ���� ������� �� ������� 
				max = elem->info;
			}
			elem = elem->next;
		}
		return true;
	}
	return false;
}

template <typename T>
bool DoublyLinkedList<T>::delete_elem(const T &t)		//������� �������� ������� 
{
	
	Node<T>* elem = head;
	if (elem = find(elem, t))
	{
		del(elem);
		return true;
	}
	else				//���� �� �������
	{
		return false;
	}

}

template <typename T>
void DoublyLinkedList<T>::del(Node<T> *elem)	//��������
{
	Node<T> *prew_el, *next_el;
	if (elem->next != nullptr) //���� �� ��������� �������
	{

		if (elem != head) //���� �� ������
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
bool DoublyLinkedList<T>::delete_all_elems(const T &t)	//������� ��� �������� � �������� ���������
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
bool DoublyLinkedList<T>::change_all_elems(const T &t, const T &new_info)	 //�������� ��� �������� � �������� ��������� �� �����
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
	while (elem != nullptr) // ���� �� ����� ������
		if (elem->info == e) // ���� ������� �������
			return elem;
		else  //���� ���
			elem = elem->next;
	return nullptr;
}