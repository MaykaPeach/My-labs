// lab1ex8a.cpp: ���������� ����� ����� ��� ����������� ����������.
// �������� � ������� ����� ������ �������� �� ���������� �������� �����.
// ��������� ����, 91��.
#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
#include <ctime>
#include <cmath>

using namespace std;
//�������-random
int random(int m) {
	int ch = rand() % (2 * m + 1) - m;
	return ch;
}
//�������� ����� �� ��������� �������� � ������� �����
ofstream create_file_rand(string FileName, int n, int m)
{
	ofstream fs(FileName);
	srand(time(0));
	for (int i = 0; i < n; ++i) {

		int r = random(m);
		fs << r << " ";
	}
	fs.close();
	return fs;
}

//�������� ����� �� ��������� �������� � ������� generate
ofstream create_file_generate(string FileName, int n, int m)
{
	ofstream fs;
	fs.open(FileName);
	generate_n(std::ostream_iterator<int>(fs, " "), n, [m]() {int i = random(m); return i; });
	fs.close();
	return fs;
}

//�������� �� �����
vector<int> load_from_file(ifstream &fin) {
	vector<int> vec;
	if (!fin) {
		cout << "���� �� ������." << endl;
		return vec;
	}

	int a;
	if (!(fin >> a)) {
		cout << "�������� ������ ������" << endl;
		return vec;
	}
	if (fin.eof()) {
		cout << "���� ����." << endl;
	}
	else {
		while (!fin.eof()) {
			vec.push_back(a);

			if (!(fin >> a) && !fin.eof()) {
				cout << "�������� ������ ������" << endl;
				vec.clear();
				return vec;
			}
		}
	}
	return vec;
}

//�������������� ������� (�������� � ������� ����� ������ �������� �� ���������� �������� �����) � �����������
void Modify_it(vector<int>::iterator first, vector<int>::iterator last) {
	int odd = 0;
	bool ok = true;
	vector<int>::iterator i = first;
	while (i != last & ok) {
		if (abs(*i) % 2 == 1) {
			ok = false;
			odd = abs(*i);
		}
		i++;
	}
	if (odd == 0) {
		throw "�������� ����� ���.";
	}
	else {
		for (vector<int>::iterator i = first; i != last; i++) {
			*i += odd;
		}
	}
}

//�������������� ������� (�������� � ������� ����� ������ �������� �� ���������� �������� �����) � ������ for
void Modify(vector<int> &vec1) {
	Modify_it(vec1.begin(), vec1.end());
}

//�������������� ������� (�������� � ������� ����� ������ �������� �� ���������� �������� �����) � transform
void Modify_Transform(vector<int>::iterator first, vector<int>::iterator last) {
	int odd = 0;
	bool ok = true;
	transform(first, last, first, [&odd, &ok](int i) { if (abs(i) % 2 == 1 & ok) { odd = abs(i); ok = false; } return i; });
	if (odd == 0) { throw "�������� ����� ���.";; }
	else transform(first, last, first, [odd](int i) {return i+=odd; });
}

//�������������� ������� (�������� � ������� ����� ������ �������� �� ���������� �������� �����) � for_each
void Modify_For_Each(vector<int>::iterator first, vector<int>::iterator last) {
	int odd = 0;
	bool ok = true;
	for_each(first, last, [&odd, &ok](int i) { if (abs(i) % 2 == 1 & ok) { odd = abs(i); ok = false; }});
	if (odd == 0) { throw "�������� ����� ���.";; }
	else for_each(first, last, [odd](int &i) { i +=odd; });
}

//������� ����� ���������
int Sum(vector<int> vec) {
	int sum = 0;
	for_each(vec.begin(), vec.end(), [&sum](int i) {sum += i; });
	return sum;
}

//������� �������� ���������������
double mid_arith(vector<int> &vec) {
	return (double)Sum(vec) / vec.size();
}

//������ � ����
void  Print(fstream &st, vector<int> &vec) {
	for_each(vec.begin(), vec.end(), [&st](int i) {st << i << " "; });
}

//������������� �����, ������ � �������
void  Print(ostream &st, vector<int> vec) {
	for_each(vec.begin(), vec.end(), [&st](int i) {st << i << " "; });
	st << endl;
}

//���������� ����
int Menu(int flag) {
	cout << "Menu:" << endl;
	cout << 1 << " - - - " << "������� ����� ���� �� ��������� ������������������� �����." << endl;
	cout << 2 << " - - - " << "��������� ������������������ �� �����." << endl;
	if (flag > 0) {
		cout << 3 << " - - - " << "�������� � ������� ����� ������ �������� �� ���������� �������� �����." << endl;
		cout << 4 << " - - - " << "��������� ����� ������ ������������������." << endl;
		cout << 5 << " - - - " << "��������� ������� ��������������." << endl;
		cout << 6 << " - - - " << "�������� ������������������ � ����." << endl;
		cout << 7 << " - - - " << "���������� ������������������." << endl;
	}
	cout << 0 << " - - - " << "�����." << endl << endl;
	int res;
	while (!(cin >> res) || flag <= 0 && (res > 2) || (flag > 0) && (res > 7));
	return res;
}

//���� ������ ��/���
bool input_query(string question) {
	cout << question << endl;
	cout << 1 << " - - - ��" << endl;
	cout << 0 << " - - - ���" << endl;
	int res;
	while (!(cin >> res) || res != 0 && res != 1);
	return res == 1;
}

//���� ����� �����
string input_file_name() {
	string name;
	cout << "������� ��� �����" << endl;
	cin >> name;
	return name;
}

//���� �����
int input_num(string str) {
	int Num;
	cout << str << endl;
	while (!(cin >> Num) || Num <= 0);
	return Num;
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> vec;
	string FileName = "";
	int N;
	int M;
	ofstream ofs;
	ifstream ifs;
	do {
		switch (Menu(vec.size())) {
		case 1:
			N = input_num("������� ���������� ���������.");
			M = input_num("������� ������������ ������ �����.");
			FileName = input_file_name();
			//ofs=CreateFileRand(FileName,N,M);
			ofs = create_file_generate(FileName, N, M);
			break;
		case 2:
			if (FileName == "") FileName = input_file_name();
			else if (!input_query("������������ ������� ����?")) {
				FileName = input_file_name();
			}
			ifs.open(FileName);
			vec = load_from_file(ifs);
			ifs.close();
			break;
		case 3:
			Modify(vec);
			//Modify_it(vec.begin(), vec.end());
			//Modify_Transform(vec.begin(), vec.end());
			//Modify_For_Each(vec.begin(), vec.end());
			break;
		case 4:
			cout << "����� ��������� = " << Sum(vec) << endl;
			break;
		case 5:
			cout << "������� �������������� = " << mid_arith(vec) << endl;
			break;
		case 6:
			FileName = input_file_name();
			ofs.open(FileName);
			Print(ofs, vec);
			ofs.close();
			break;
		case 7:
			Print(cout, vec);
			break;
		default:
			return 0;
		}
	} while (1);

}

