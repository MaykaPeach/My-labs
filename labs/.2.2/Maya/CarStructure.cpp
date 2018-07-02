#define _CRT_SECURE_NO_WARNINGS

#include "CarStructure.h"


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
	sort(vect.begin(), vect.end());
	auto index = lower_bound(vect.begin(), vect.end(), find_element);

	while ((index != vect.end()) && Equal(find_element,*index)) {
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
/*
// проверка на пустоту
template <class Type>
bool CarStructure<Type>::is_empty()
{
return (vect.size() == 0);
}*/