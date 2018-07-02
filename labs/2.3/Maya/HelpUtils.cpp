#define _CRT_SECURE_NO_WARNINGS

#include "HelpUtils.h"

using namespace std;

int InputNumber(int min, int max, const string &message) {
	int n;
	do {
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n') {
			cout << "Неправильный ввод!  Повторите ввод!\n";
			cin.clear();  // восстанавливает поток если он в ошибочном состоянии
			cin.sync();   // очищает поток от имеющихся символов
			cout << message;
			getchar();
			getchar();
		}
	} while ((n < min) || (n > max));
	return n;
}

// Ввод бензина
int InputPetrol(const string &message) {
	int n;
	do {
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "Неправильный ввод!  Повторите ввод!\n";
			cin.clear();  // восстанавливает поток если он в ошибочном состоянии
			cin.sync();   // очищает поток от имеющихся символов
			cout << message;
			getchar();
			getchar();
		}
	} while ((n != 92) && (n != 95) && (n != 98) && (n != 100));
	return n;
}

// ввод информации
string InputInformation(const string &message) {
	string a;
	cout << message;
	cin >> a;
	return a;
}

// проверка символа на корректность в имени файла
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


// проверка имени файла на коректность
bool CorrectName(const string &name) {
	bool goodsm = true;
	for (unsigned int i = 0; (i < name.length() && goodsm); i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

// ввод имени файла
string InputFileName() {
	string filename;
	do {
		cout << "Введите имя файла (без расширения):  ";
		cin >> filename;
		if (filename.length() > 35)
			filename.erase(filename.begin(), filename.begin() + 35);
		if (CorrectName(filename)) {
			filename = filename + ".txt";
			break;
		}
		else cout << "Неверное имя файла\n";
	} while (true);
	return filename;
}