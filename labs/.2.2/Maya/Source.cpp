/*
Долматова Майя 91гр
7) Информация об автомобиле представлена структурой с полями: фамилия
владельца, код марки, наименование марки, требуемая марка бензина, мощность
двигателя, объем бака, остаток бензина, объем масла. Поиск по марке
автомобиля, марке бензина, мощности двигателя, фамилии владельца.
*/

#include "Car.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "HelpUtils.h"
using namespace std;

template <class Type>
class CarStructure {
private:
	vector<Type> vect;
public:
	CarStructure();
	int size();
	void remove(int);
	void add(Type);
	Type change_Car(Type&);
	vector<Type>& get_vect();
	//bool is_empty();
	void output_file(vector<Type> items, string(*f)(Type, int));
	void output_screen(vector<Type> items, void(*f) (Type));
	bool read_from_file(Type(*f)(ifstream&));
	void read_from_screen(Type(*f)());
	vector<Type> lineary_search(Type search_elem, bool(*Equal)(Type, Type));
	vector<Type> Binary_Search(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type));
	~CarStructure();
};

// удаление элемента
template <class Type>
void CarStructure<Type>::remove(int numb)
{
	if (numb != 0)
		vect.erase(vect.begin() + numb - 1);
}

template <class Type>
CarStructure<Type>::CarStructure() {
	vect.reserve(100);
}

template <class Type>
CarStructure<Type>::~CarStructure() {}

// добавление элемента
template <class Type>
void CarStructure<Type>::add(Type elem)
{
	vect.push_back(elem);
}
template<class Type>
vector<Type>& CarStructure<Type>::get_vect() {
	return vect;
}

// вывод в файл
// void(*f) (Car) - указатель на функцию, которая записывает одну структуру в файл
template <class Type>
void CarStructure<Type>::output_file(vector<Type> items, string(*f)(Type, int))
{
	string newfname = InputFileName();
	ofstream fout(newfname);
	if (fout)
	{
		int count = 1;
		for (auto pos = items.begin(); pos != items.end(); ++pos)
		{
			fout << f(*pos, count) << ' ';
			count++;
		}
		cout << endl << "Файл заполнен!" << endl;
		fout.close();
	}
	else
	{
		cout << "Файл не заполнен!" << endl;
	}
}

// вывод на экран
// void(*f) (Car) - указатель на функцию, которая считывает одну структуру на экран
template <class Type>
void CarStructure<Type>::output_screen(vector<Type> items, void(*f) (Type))
{
	int count = 1;
	for (auto pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << "-------------------------------------\nИнформация об автомобиле № " << count << endl;
		f(*pos);
		++count;
	}
	cout << "-------------------------------------" << endl;
}

// ввод из файла
// Car(*f)(ifstream&) - указатель на функцию, которая считывает одну структуру из файла 
template <class Type>
bool CarStructure<Type>::read_from_file(Type(*f)(ifstream&))
{
	string newfname = InputFileName();
	ifstream input;
	input.open(newfname);
	if (!input)
	{
		cout << "Не удалось открыть файл" << endl;
		return false;
	}
	else
	{
		while (!input.eof())
		{
			vect.push_back(f(input));
		}
		vect.erase(vect.begin() + vect.size() - 1);
		input.close();
		return true;
	}
}

// ввод с экрана
//Car(*f)() - указатель на функцию, которая вводит одну структуру с консоли
template <class Type>
void CarStructure<Type>::read_from_screen(Type(*f)())
{
	int n;
	Type elem;
	do
	{
		vect.push_back(f());
		n = InputNumber(0, 1, "Вы хотите добавить элемент? (1 - да, 0 - нет)\nВаш выбор: ");
	} while (n != 0);
}

// линейный поиск
// bool(*Equal)(Car, Car, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по Car_search
template <class Type>
vector<Type> CarStructure<Type>::lineary_search(Type search_elem, bool(*Equal)(Type, Type))
{
	vector<Type> NewVect;
	for (Type tmp : vect) {
		if (Equal(search_elem, tmp))
			NewVect.push_back(tmp);
	}
	return NewVect;
}

// бинарный поиск
// int(*Compare)(Car, Car, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по Car_search 
// bool(*Equal)(Car, Car, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по Car_search
template <class Type>
vector<Type> CarStructure<Type>::Binary_Search(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type))
{
	vector<Type> NewVect;
	sort(vect.begin(), vect.end(), Compare);
	auto index = lower_bound(vect.begin(), vect.end(), find_element, Compare);

	while ((index != vect.end()) && Equal(find_element, *index)) {
		NewVect.push_back(*index);
		++index;
	}
	return NewVect;
}

//размер вектора
template <class Type>
int CarStructure<Type>::size()
{
	return vect.size();
}

// изменение структуры "автомобиль"

template <class Type>
Type CarStructure<Type>::change_Car(Type &result)
{
	if (InputNumber(0, 1, "Вы хотите изменить ФИО владельца?" + result.get_fio() + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.set_fio(InputInformation("Введите новое ФИО: "));
	if (InputNumber(0, 1, "Вы хотите изменить код марки автомобиля?" + to_string(result.get_code()) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.set_code(InputNumber(0, 10000, "Введите код марки автомобиля: "));
	if (InputNumber(0, 1, "Вы хотите изменить марку машины?" + result.get_name() + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.set_name(InputInformation("Введите новую марку машины: "));
	if (InputNumber(0, 1, "Вы хотите изменить марку бензина?" + to_string(result.get_petrol()) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.set_petrol(InputPetrol("Введите марку бензина: "));
	if (InputNumber(0, 1, "Вы хотите изменить мощность двигателя?" + to_string(result.get_power()) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.set_power(InputNumber(0, 1000, "Введите мощность двигателя: "));
	if (InputNumber(0, 1, "Вы хотите изменить объем бака?" + to_string(result.get_volume()) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.set_volume(InputNumber(0, 200, "Введите объем бака: "));
	if (InputNumber(0, 1, "Вы хотите изменить остаток бензина?" + to_string(result.get_res()) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.set_res(InputNumber(0, result.get_volume(), "Введите остаток бензина: "));
	if (InputNumber(0, 1, "Вы хотите изменить объем масла?" + to_string(result.get_oil()) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		result.set_oil(InputNumber(0, 100, "Введите объем масла: "));

	return result;
}

int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Изменить элемент" << endl;
	cout << "4 - Вывод на экран" << endl;
	cout << "5 - Сохранить в файл " << endl;
	cout << "6 - Линейный поиск" << endl;
	cout << "7 - Двоичный поиск" << endl;
	cout << "8 - Вывести подможество на экран" << endl;
	cout << "9 - Сохранить подмножество в файл" << endl;
	cout << "0 - Выход" << endl;
	int n = InputNumber(0, 9, "Ваш выбор: ");
	cout << "\n";
	return n;
}

void my_search(int numb, bool(*&compare)(Car, Car))
{

	switch (numb)
	{
	case 1:
		compare = search_element_name;
		break;
	case 2:
		compare = search_element_petrol;
		break;
	case 3:
		compare = search_element_power;
		break;
	case 4:
		compare = search_element_fio;
		break;
	}
}

void my_search(int numb, bool(*&compare)(Car, Car), bool(*&sort)(Car, Car))
{
	switch (numb)
	{
	case 1:
		compare = search_element_name;
		sort = mysort_element_name;
		break;
	case 2:
		compare = search_element_petrol;
		sort = mysort_element_petrol;
		break;
	case 3:
		compare = search_element_power;
		sort = mysort_element_power;
		break;
	case 4:
		compare = search_element_fio;
		sort = mysort_element_fio;
		break;
	}
}

void ChangeInputData()
{
	CarStructure<Car> task;
	bool change = true;
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Заполнение контейнера с консоли" << endl;
	cout << "2 - Заполнение контейнера из файла " << endl;
	cout << "0 - Выход" << endl;
	int changemenu = InputNumber(0, 2, "Ваш выбор: ");
	switch (changemenu)
	{
	case 1:
		task.read_from_screen(input_Car);
		break;

	case 2:
		change = task.read_from_file(from_my_string);
		break;

	default:
		change = false;
		break;
	}
	if (change)
	{
		bool(*compare)(Car, Car) = nullptr;
		bool(*sort)(Car, Car) = nullptr;
		Car elem;
		vector<Car> subset;
		Car search_elem;
		int numb;
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				task.add(input_Car());
				break;

			case 2:
				task.output_screen(task.get_vect(), output_Car);
				task.remove(InputNumber(0, task.size(), "Введите номер удаляемого элемента (0 - если передумали удалять): "));
				break;

			case 3:
				task.output_screen(task.get_vect(), output_Car);
				numb = InputNumber(0, task.size(), "Введите номер изменяемого элемента (0 - если передумали изменять): ");
				if (numb != 0)
					((task.get_vect())[numb - 1]) = task.change_Car(task.get_vect()[numb - 1]);
				break;

			case 4:
				task.output_screen(task.get_vect(), output_Car);
				break;

			case 5:
				task.output_file(task.get_vect(), to_my_string);
				break;

			case 6:
				numb = InputNumber(1, 4, "Выберите тип поиска:\n 1 - по марке автомобиля\n 2 - по марке бензина\n 3 - по мощности двигателя\n 4 - по ФИО владельца \nВаш выбор: ");
				search_elem = input_Car_search(numb);
				my_search(numb, compare);
				subset = task.lineary_search(search_elem, compare);
				if (!subset.empty())
					task.output_screen(subset, output_Car);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 7:
				numb = InputNumber(1, 4, "Выберите тип поиска:\n 1 - по марке автомобиля\n 2 - по марке бензина\n 3 - по мощности двигателя\n 4 - по ФИО владельца \nВаш выбор: ");
				search_elem = input_Car_search(numb);
				my_search(numb, compare, sort);
				subset = task.Binary_Search(search_elem, sort, compare);
				if (!subset.empty())
					task.output_screen(subset, output_Car);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 8:
				task.output_screen(subset, output_Car);
				break;

			case 9:
				task.output_file(subset, to_my_string);
				break;


			default:
				cout << "Выход " << endl; exit(0);

			}
		}
	}
	else
		cout << "До свидания!!\n";
	system("pause");
	//return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
	return 0;
}