#define _CRT_SECURE_NO_WARNINGS

#include "HelpUtils.h"

using namespace std;

int InputNumber(int min, int max, const string &message) {
	int n;
	do {
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n') {
			cout << "������������ ����!  ��������� ����!\n";
			cin.clear();  // ��������������� ����� ���� �� � ��������� ���������
			cin.sync();   // ������� ����� �� ��������� ��������
			cout << message;
			getchar();
			getchar();
		}
	} while ((n < min) || (n > max));
	return n;
}

// ���� �������
int InputPetrol(const string &message) {
	int n;
	do {
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "������������ ����!  ��������� ����!\n";
			cin.clear();  // ��������������� ����� ���� �� � ��������� ���������
			cin.sync();   // ������� ����� �� ��������� ��������
			cout << message;
			getchar();
			getchar();
		}
	} while ((n != 92) && (n != 95) && (n != 98) && (n != 100));
	return n;
}

// ���� ����������
string InputInformation(const string &message) {
	string a;
	cout << message;
	cin >> a;
	return a;
}

// �������� ������� �� ������������ � ����� �����
bool CorrectSymbol(const char c) {
	switch (c) {
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}


// �������� ����� ����� �� �����������
bool CorrectName(const string &name) {
	bool goodsm = true;
	for (unsigned int i = 0; (i < name.length() && goodsm); i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

// ���� ����� �����
string InputFileName() {
	string filename;
	do {
		cout << "������� ��� ����� (��� ����������):  ";
		cin >> filename;
		if (filename.length() > 35)
			filename.erase(filename.begin(), filename.begin() + 35);
		if (CorrectName(filename)) {
			filename = filename + ".txt";
			break;
		}
		else cout << "�������� ��� �����\n";
	} while (true);
	return filename;
}