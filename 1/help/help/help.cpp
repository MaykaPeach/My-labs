// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 

// Матрица состоит из нулей и единиц. Найти в ней самую длинную цепочку подряд идущих нулей по горизонтали, вертикали и диагонали.
// Долматова Майя 91гр.
using namespace std;
int main()
{
	int matr[20][20]; //объявляем массив
	int str, col;
	cout << "Enter the size of mass: \n";
	cout << "Enter str\n";
	cin >> str; //кол-во строк
	cout << "Enter col\n";
	cin >> col; //кол-во столбцов
	cout << endl;
	srand(time(NULL)); //функция, чтобы рандом выдавал разные числа
	for (int i = 0; i < str; i++) //заполнение массива
		for (int j = 0; j < col; j++)
		{
			matr[i][j] = rand() % 2;
		}
	for (int i = 0; i < str; i++) //печать массива
	{
		for (int j = 0; j < col; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	int diag, maxdiag = 0; int number_diag;
	for (int index_diag = 0; index_diag < (str + col - 1); index_diag++)
	{
		diag = 0;
		for (int i = 0; (i < index_diag + 1)&&(i < str); i++)
		{
			for (int j = 0; (j < index_diag + 1)&&(j < col); j++)
			{
				if ((i + j) == index_diag)
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
			number_diag = index_diag;
			maxdiag = diag;
		}

	}
	//--------------------------------------------------------------------------
	/*int maxdiag1 = 0, maxdiag = 0, diag = 0;
	for (int i = 0; i < str; ++i)
	{
		diag = 0;
		for (int j = 0; i + j < str; ++j)
		{
			if (matr[i+j][j] == 1)
			{
				diag++;
			}
		}
		if (maxdiag < diag)
		{
			maxdiag = diag;
		}
	}
	for (int i = 1; i < col; ++i)
	{
		for (int j = 0; i + j < col; ++j)
		{
			diag = 0;
			for (int j = 0; i + j < str; ++j)
			{
				if (matr[j][i + j] == 1)
				{
					diag++;
				}
			}
			if (maxdiag1 < diag)
			{
				maxdiag1 = diag;
			}
		}
	}
	if (maxdiag1 > maxdiag)
	{
		maxdiag = maxdiag1;
	}

	/*for (int i = 1; i < M; ++i)
	{
		for (int j = 0; i + j < M; ++j)
			std::cout << A[j][i + j] << " ";
		std::cout << "\n";
	}
	int i = 0, j = col - 1;
	while (i < str)//диагональ слева сверху направо вниз
	{
		while ((j >= 0)&&(i >= 0))
		{
			int hi = i, hj = j;
			while ((i < str) && (j < col))
			{

				if (matr[i][j] == 1)
				{
					diag++;
				}
				i++; j++;
			}
			if (i == str)
			{
				j = hj;
				hi--;
				i = hi;
			}
			if (j == col)
			{
				if (hj != 0)
				{
					i = hi;
					hj--;
				}
				else
				{
					hi++;
					i = hi;
				}
				j = hj;
			}
			if (maxdiag < diag)
			{
				maxdiag = diag;
			}


		}
	}*/






	cout << endl;
	cout << "maxdiag = " << maxdiag;
	cout << endl;
	cout << "number_diag = " << number_diag+1;


	int q;
	cin >> q;
	cout << endl;
	return 0;
}

