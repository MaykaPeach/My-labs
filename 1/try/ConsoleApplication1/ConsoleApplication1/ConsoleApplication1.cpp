// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <algorithm>

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
		gor = 1;
		for (int j = 0; j < col - 1; j++)
		{
			if ((matr[i][j] == 0)&(matr[i][j + 1] == 0))
			{
				gor++;
				if (maxgor < gor)
				{
					maxgor = gor;
				}
			}
			else
			{
				gor = 1;
			}
		}
		if (maxgor < gor)
		{
			maxgor = gor;
		}
	}
	max = maxgor;

	for (int j = 0; j < col; j++) //���������. ���� ������������ ���������� 1 � ���
	{
		ver = 1;
		for (int i = 0; i < str - 1; i++)
		{
			if ((matr[i][j] == 0)&(matr[i + 1][j] == 0))
			{
				ver++;
				if (maxver < ver)
				{
					maxver = ver;
				}
			}
			else
			{
				ver = 1;
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

	int diag, maxdiag = 0; //��������� right_top -> left_bottom
	for (int index_diag = 1; index_diag < (str + col - 1); index_diag++) //��������� ��� �� ������� ����������
	{
		diag = 1;
		for (int i = 0, j = min(index_diag, col - 1); (i < str) && (j > -1); i++, j--) //!
		{

			if ((matr[i][j] == 0) && (matr[i + 1][j - 1] == 0))
			{
				diag++;
				if (maxdiag < diag)
				{
					maxdiag = diag;
				}
			}
			else
			{
				diag = 1;
			}
		}
		if (maxdiag < diag)
		{
			maxdiag = diag;
		}
	}


	int diag1, maxdiag1 = 0; //��������� left_top -> right_bottom
	for (int index_diag1 = -col + 2; index_diag1 < str; index_diag1++) //��������� ��� �� ������� ����������
	{
		diag1 = 1;
		for (int i = 0, j = -index_diag1; (i < str) && (j < col - 1); i++, j++)
		{
			if ((matr[i][j] == 0) && (matr[i + 1][j + 1] == 0))
			{
				diag1++;
				if (maxdiag1 < diag1)
				{
					maxdiag1 = diag1;
				}
			}
			else
			{
				diag1 = 1;
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
	if (max == 1)
	{
		cout << "We have not a chain more than one elemet" << endl;
	}
	else
	{
		cout << "max = " << max;
	}

	cout << endl;
	system("pause");
	return 0;
}


