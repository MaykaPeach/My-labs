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
	DoublyLinkedList();        // ����������� - �������������
	~DoublyLinkedList();         // ����������


	int get_length() const { return count; }// ���������� �����
	void add_first(const T &t);		//���������� � ������
	void add_last(const T &t);		//���������� � �����
	void print();			//������ ���� ��������� ������

	bool find_elem(const T &t);			//����� �������� �������
	void find_min(T &min);		//����� ����������� ��������
	void find_max(T &max);	//����� ������������ ��������
	bool delete_elem(const T &t);		//������� �������� �������
	void delete_all_elems(const T &t);	//������� ��� �������� � �������� ���������
	bool change_all_elems(const T &t, const T &new_info);		 //�������� ��� �������� � �������� ��������� �� �����
};

