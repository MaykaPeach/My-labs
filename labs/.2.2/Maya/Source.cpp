/*
��������� ���� 91��
7) ���������� �� ���������� ������������ ���������� � ������: �������
���������, ��� �����, ������������ �����, ��������� ����� �������, ��������
���������, ����� ����, ������� �������, ����� �����. ����� �� �����
����������, ����� �������, �������� ���������, ������� ���������.
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

// �������� ��������
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

// ���������� ��������
template <class Type>
void CarStructure<Type>::add(Type elem)
{
	vect.push_back(elem);
}
template<class Type>
vector<Type>& CarStructure<Type>::get_vect() {
	return vect;
}

// ����� � ����
// void(*f) (Car) - ��������� �� �������, ������� ���������� ���� ��������� � ����
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
		cout << endl << "���� ��������!" << endl;
		fout.close();
	}
	else
	{
		cout << "���� �� ��������!" << endl;
	}
}

// ����� �� �����
// void(*f) (Car) - ��������� �� �������, ������� ��������� ���� ��������� �� �����
template <class Type>
void CarStructure<Type>::output_screen(vector<Type> items, void(*f) (Type))
{
	int count = 1;
	for (auto pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << "-------------------------------------\n���������� �� ���������� � " << count << endl;
		f(*pos);
		++count;
	}
	cout << "-------------------------------------" << endl;
}

// ���� �� �����
// Car(*f)(ifstream&) - ��������� �� �������, ������� ��������� ���� ��������� �� ����� 
template <class Type>
bool CarStructure<Type>::read_from_file(Type(*f)(ifstream&))
{
	string newfname = InputFileName();
	ifstream input;
	input.open(newfname);
	if (!input)
	{
		cout << "�� ������� ������� ����" << endl;
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

// ���� � ������
//Car(*f)() - ��������� �� �������, ������� ������ ���� ��������� � �������
template <class Type>
void CarStructure<Type>::read_from_screen(Type(*f)())
{
	int n;
	Type elem;
	do
	{
		vect.push_back(f());
		n = InputNumber(0, 1, "�� ������ �������� �������? (1 - ��, 0 - ���)\n��� �����: ");
	} while (n != 0);
}

// �������� �����
// bool(*Equal)(Car, Car, int) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � ������� �� Car_search
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

// �������� �����
// int(*Compare)(Car, Car, int) - ��������� �� �������, ������� ���������� ������� ��-� � ������� �� Car_search 
// bool(*Equal)(Car, Car, int) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � ������� �� Car_search
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

//������ �������
template <class Type>
int CarStructure<Type>::size()
{
	return vect.size();
}

// ��������� ��������� "����������"

template <class Type>
Type CarStructure<Type>::change_Car(Type &result)
{
	if (InputNumber(0, 1, "�� ������ �������� ��� ���������?" + result.get_fio() + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		result.set_fio(InputInformation("������� ����� ���: "));
	if (InputNumber(0, 1, "�� ������ �������� ��� ����� ����������?" + to_string(result.get_code()) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		result.set_code(InputNumber(0, 10000, "������� ��� ����� ����������: "));
	if (InputNumber(0, 1, "�� ������ �������� ����� ������?" + result.get_name() + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		result.set_name(InputInformation("������� ����� ����� ������: "));
	if (InputNumber(0, 1, "�� ������ �������� ����� �������?" + to_string(result.get_petrol()) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		result.set_petrol(InputPetrol("������� ����� �������: "));
	if (InputNumber(0, 1, "�� ������ �������� �������� ���������?" + to_string(result.get_power()) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		result.set_power(InputNumber(0, 1000, "������� �������� ���������: "));
	if (InputNumber(0, 1, "�� ������ �������� ����� ����?" + to_string(result.get_volume()) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		result.set_volume(InputNumber(0, 200, "������� ����� ����: "));
	if (InputNumber(0, 1, "�� ������ �������� ������� �������?" + to_string(result.get_res()) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		result.set_res(InputNumber(0, result.get_volume(), "������� ������� �������: "));
	if (InputNumber(0, 1, "�� ������ �������� ����� �����?" + to_string(result.get_oil()) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		result.set_oil(InputNumber(0, 100, "������� ����� �����: "));

	return result;
}

int Menu()
{
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - �������� �������" << endl;
	cout << "2 - ������� �������" << endl;
	cout << "3 - �������� �������" << endl;
	cout << "4 - ����� �� �����" << endl;
	cout << "5 - ��������� � ���� " << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - �������� �����" << endl;
	cout << "8 - ������� ����������� �� �����" << endl;
	cout << "9 - ��������� ������������ � ����" << endl;
	cout << "0 - �����" << endl;
	int n = InputNumber(0, 9, "��� �����: ");
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
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - ���������� ���������� � �������" << endl;
	cout << "2 - ���������� ���������� �� ����� " << endl;
	cout << "0 - �����" << endl;
	int changemenu = InputNumber(0, 2, "��� �����: ");
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
				task.remove(InputNumber(0, task.size(), "������� ����� ���������� �������� (0 - ���� ���������� �������): "));
				break;

			case 3:
				task.output_screen(task.get_vect(), output_Car);
				numb = InputNumber(0, task.size(), "������� ����� ����������� �������� (0 - ���� ���������� ��������): ");
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
				numb = InputNumber(1, 4, "�������� ��� ������:\n 1 - �� ����� ����������\n 2 - �� ����� �������\n 3 - �� �������� ���������\n 4 - �� ��� ��������� \n��� �����: ");
				search_elem = input_Car_search(numb);
				my_search(numb, compare);
				subset = task.lineary_search(search_elem, compare);
				if (!subset.empty())
					task.output_screen(subset, output_Car);
				else
					cout << "�������� �� �������" << endl;
				break;

			case 7:
				numb = InputNumber(1, 4, "�������� ��� ������:\n 1 - �� ����� ����������\n 2 - �� ����� �������\n 3 - �� �������� ���������\n 4 - �� ��� ��������� \n��� �����: ");
				search_elem = input_Car_search(numb);
				my_search(numb, compare, sort);
				subset = task.Binary_Search(search_elem, sort, compare);
				if (!subset.empty())
					task.output_screen(subset, output_Car);
				else
					cout << "�������� �� �������" << endl;
				break;

			case 8:
				task.output_screen(subset, output_Car);
				break;

			case 9:
				task.output_file(subset, to_my_string);
				break;


			default:
				cout << "����� " << endl; exit(0);

			}
		}
	}
	else
		cout << "�� ��������!!\n";
	system("pause");
	//return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
	return 0;
}