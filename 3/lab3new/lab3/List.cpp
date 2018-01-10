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
	Node *elem = head;

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
	Node *elem = new Node(t);	// ������� ����� ���� ��� ��������
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
	Node *elem = new Node(t); // ������� ����� ���� ��� ��������

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
	Node* elem = head; //��������� ��������� �� ������ ������
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
	//int pos = 0;
	if (head != nullptr)
	{
		Node* elem  = head;
		while ((elem != nullptr) && (elem->info != t)) // ���� �� ����� ������ � �� �����
		{
			elem = elem->next;
			//pos++;
		}
		if (elem != nullptr)  // ���� �������  ������� 
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
void DoublyLinkedList<T>::find_min(T &min) //����� �������
{
	Node* elem = head;
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
	}
	/*else
	{
		cout << "List is empty!" << endl;
	}*/
}

template <typename T>
void DoublyLinkedList<T>::find_max(T &max) //����� �������
{
	Node* elem = head;
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
	}
	/*else
	{
		cout << "List is empty!" << endl;
	}*/
}

template <typename T>
bool DoublyLinkedList<T>::delete_elem(const T &t)		//������� �������� ������� 
{
	if (head == nullptr) {
		/*cout << "List is empty!" << endl;*/
		return false;
	}
	else
	{
		Node* elem = head;
		Node *prew_el, *next_el;
		while ((elem != nullptr) && (elem->info != t)) // ���� �� ����� ������ � �� �����
		{
			elem = elem->next;
		}
		if (elem != nullptr) // ���� ������� �������
		{
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
		else				//���� �� �������
		{
			return false;
		}
	}
}
template <typename T>
void DoublyLinkedList<T>::delete_all_elems(const T &t)	//������� ��� �������� � �������� ���������
{
	while (delete_elem(t));
}

template <typename T>
bool DoublyLinkedList<T>::change_all_elems(const T &t, const T &new_info)	 //�������� ��� �������� � �������� ��������� �� �����
{
	if (head == nullptr) {
		/*cout << "List is empty!" << endl;*/
		return false;
	}
	else
	{
		bool ok = true; // �������� � �������� ��������� ����
		Node* elem = head;
		while (elem != nullptr) // ���� �� ����� ������
		{
			while ((elem != nullptr) && (elem->info != t)) // ���� �� ����� ������ � �� �����
			{
				elem = elem->next;
			}
			if (elem != nullptr) // ���� ������� �������
			{
				elem->info = new_info;
			}
		}
	}
}