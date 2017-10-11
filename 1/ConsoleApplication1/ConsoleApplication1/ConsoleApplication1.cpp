// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 

// ������� ������� �� ����� � ������. ����� � ��� ����� ������� ������� ������ ������ ����� �� �����������, ��������� � ���������.
// ��������� ���� 91��.
//���� � ���������� ��� ���� ��������?
using namespace std;
int main()
{
	int matr[20][20]; //��������� ������
	int str, col, max = 0;;

	cout << "Enter the size of mass: \n";
	cout << "Enter str\n";
	cin >> str; //���-�� �����
	cout << "Enter col\n";
	cin >> col; //���-�� ��������
	cout << "Do you want use rand (answer - '0') or enter by yourself (answer -'1')?\n";
	int answer; //����� ������������ '0'/'1'
	bool ok = true; //��� ������ ����� � ����������� ������ ������������
	do
	{
		cin >> answer;
		switch (answer)
		{
			case 0:
			{
				srand(time(NULL)); //�������, ����� ������ ������� ������ �����
				for (int i = 0; i < str; i++) //���������� ������� 0 � 1
					for (int j = 0; j < col; j++)
					{
						matr[i][j] = rand() % 2;
					}
				ok = true;
				break;
			}
			case 1:
			{
				cout << "Enter elemets:\n";
				for (int i = 0; i < str; i++) //���������� ������� �������
				{
					for (int j = 0; j < col; j++)
					{
						cin >> matr[i][j];
					}
				}
				ok = true;
				break;
			}
			default:
			{
				cout << "Enter your answer again. Rand - '0', enter by yourself -'1'\n";
				break;
			}
		}
		if (answer != 1 && answer != 0) //���� ����� �� 1 � �� 0, �� ���� ������������
			ok = false;
	} while (!ok);
	cout << endl;

	for (int i = 0; i < str; i++) //������ �������
	{
		for (int j = 0; j < col; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}

	int maxgor = 0, maxver = 0, gor, ver;
	for (int i = 0; i < str; i++)//�����������. ���� ������������ ���������� 1 � ���
	{
		gor = 0;
		for (int j = 0; j < col; j++)
		{
			if (matr[i][j] == 1)
			{
				gor++;
			}
		}
		if (maxgor < gor)
		{
			maxgor = gor;
		}
	}
	max = maxgor;
	//cout << endl;
	//cout << "maxgor = " << maxgor;

	for (int j = 0; j < col; j++) //���������. ���� ������������ ���������� 1 � ���
	{
		ver = 0;
		for (int i = 0; i < str; i++)
		{
			if (matr[i][j] == 1)
			{
				ver++;
			}
		}
		if (maxver < ver)
		{
			maxver = ver;
		}
	}
	if (max < maxver)
	{
		max = maxver;
	}
	//cout << endl;
//	cout << "maxver = " << maxver;

	int diag, maxdiag = 0; //��������� right_top -> left_bottom
	for (int index_diag = 0; index_diag < (str + col - 1); index_diag++) //��������� ��� �� ������� ����������
	{
		diag = 0;
		for (int i = 0; (i < index_diag + 1) && (i < str); i++) 
		{
			for (int j = 0; (j < index_diag + 1) && (j < col); j++)
			{
				if ((i + j) == index_diag) //����� �������� i � j � ����� ��������� ����� ������� ���������
				{
					if (matr[i][j] == 1)
					{
						diag++;
					}
				}
			}
		}
		if (maxdiag < diag)
		{
			maxdiag = diag;
		}

	}

	int diag1, maxdiag1 = 0; //��������� left_top -> right_bottom
	for (int index_diag1 = -col+1; index_diag1 < str; index_diag1++) //��������� ��� �� ������� ����������
	{
		diag1 = 0;
		for (int i = 0; i < str; i++)
		{
			for (int j = col-1; j > -1; j--)
			{
				if ((i - j) == index_diag1) //�������� �������� i � j � ����� ��������� ����� ������� ���������
				{
					if (matr[i][j] == 1)
					{
						diag1++;
					}
				}
			}
		}
		if (maxdiag1 < diag1)
		{
			maxdiag1 = diag1;
		}

	}
	if (maxdiag < maxdiag1)
	{
		maxdiag = maxdiag1;
	}
	if (max < maxdiag)
	{
		max = maxdiag;
	}
	cout << endl;
	cout << "max = " << max;

	cout << endl;
	system("pause");
	return 0;
}

