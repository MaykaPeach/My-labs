// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*����������� ������ ������ ���������� (���������������) ������ (DoublyLinkedList<X>), �������� �������� ������������� ����.
����� ������ ���������:
- ������������� ������;
- ���������� �������� � ������ ������;
- ���������� �������� � ����� ������;
- ����� ���� ��������� ������.

b)
- ����� ������� �������� � ������;
- ����� ����������� � ����������� �������� � ������;
- �������� �������� ������ � ������ ���������;
- �������� ���� ��������� ������ � ������ ���������;
- ��������� ���� ��������� ������ � ������ ��������� �� �����;*/

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
	DoublyLinkedList();        // ����������� - �������������
	~DoublyLinkedList();         // ����������


	int get_length() const { return count; }// ���������� �����
	void add_first(const T &t);		//���������� � ������
	void add_last(const T &t);		//���������� � �����
	void print();			//������ ���� ��������� ������

	bool find_elem(const T &t);			//����� �������� �������
	bool try_find_min(T &min);		//����� ����������� ��������
	bool try_find_max(T &max);	//����� ������������ ��������
	bool delete_elem(const T &t);		//������� �������� �������
	bool delete_all_elems(const T &t);	//������� ��� �������� � �������� ���������
	void del(Node<T> *elem);
	bool change_all_elems(const T &t, const T &new_info);		 //�������� ��� �������� � �������� ��������� �� �����
};

