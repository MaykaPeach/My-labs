#define _CRT_SECURE_NO_WARNINGS

#include "CarStructure.h"


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
	sort(vect.begin(), vect.end());
	auto index = lower_bound(vect.begin(), vect.end(), find_element);

	while ((index != vect.end()) && Equal(find_element,*index)) {
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
/*
// �������� �� �������
template <class Type>
bool CarStructure<Type>::is_empty()
{
return (vect.size() == 0);
}*/