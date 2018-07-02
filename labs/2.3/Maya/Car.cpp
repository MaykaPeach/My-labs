#include "Car.h"

//�����������
Car::Car()
{
	string _fio;
	string _brand_name;
	int _brand_code = 0;
	int _petrol = 92;
	int _engine_power = 0;
	int _tank_volume = 0;
	int _residue_petrol = 0;
	int _oil_volume = 0;
	int _action = 0;
	bool _complete = false;
}

//get
string Car::get_fio() const { return _fio; }
int Car::get_code() const { return _brand_code; }
string Car::get_name() const { return _brand_name; }
int Car::get_petrol() const { return _petrol; }
int Car::get_power() const { return _engine_power; }
int Car::get_volume() const { return _tank_volume; }
int Car::get_res() const { return _residue_petrol; }
int Car::get_oil() const { return _oil_volume; }
int Car::get_action() const { return _action; }
bool Car::get_complete() const { return _complete; }

//set
void Car::set_fio(const string &fio) { _fio = fio; }
void Car::set_code(const int brand_code) { _brand_code = brand_code; }
void Car::set_name(const string &brand_name) { _brand_name = brand_name; }
void Car::set_petrol(const int petrol) { _petrol = petrol; }
void Car::set_power(const int engine_power) { _engine_power = engine_power; }
void Car::set_volume(const int tank_volume) { _tank_volume = tank_volume; }
void Car::set_res(const int residue_petrol) { _residue_petrol = residue_petrol; }
void Car::set_oil(const int oil_volume) { _oil_volume = oil_volume; }
void Car::set_action(const int action) { _action = action; }
void Car::set_complete(const bool complete) { _complete = complete;  }

// ������������� �������� ��������� ��� ��������� "����������"
Car& Car::operator = (Car const& a) = default;

// ������� ����� ��������� "����������" � �������
Car input_Car()
{
	Car a;
	string fio = InputInformation("������� ��� ���������: ");
	a.set_fio(fio);
	int brand_code = InputNumber(0, 10000, "������� ��� ����� ����������: ");
	a.set_code(brand_code);
	string brand_name = (InputInformation("������� ����� ����������: "));
	a.set_name(brand_name);
	int petrol = (InputPetrol("������� ����� �������: "));
	a.set_petrol(petrol);
	int engine_power = (InputNumber(0, 1000, "������� �������� ���������: "));;
	a.set_power(engine_power);
	int tank_volume = (InputNumber(0, 200, "������� ����� ����: "));
	a.set_volume(tank_volume);
	int residue_petrol = (InputNumber(0, a.get_volume(), "������� ������� �������: "));
	a.set_res(residue_petrol);
	int oil_volume = (InputNumber(0, 3, "������� ����� �����: "));
	a.set_oil(oil_volume);
	int action = (InputNumber(0, 4, "������� 1 - ��������� ������, 2 - ������ �����, 3 - ����������� ������������: "));
	a.set_action(action);
	a.set_complete(false);
	return a;
}


// ������� ������ ��������� "����������" �� �������
void output_Car(Car a)
{
	cout << "��� ���������: " << a.get_fio() << endl;
	cout << "��� ����� ����������: " << to_string(a.get_code()) << endl;
	cout << "����� ����������: " << a.get_name() << endl;
	cout << "����� �������: " << to_string(a.get_petrol()) << endl;
	cout << "�������� ���������: " << to_string(a.get_power()) << endl;
	cout << "����� ����: " << to_string(a.get_volume()) << endl;
	cout << "������� �������: " << to_string(a.get_res()) << endl;
	cout << "����� �����: " << to_string(a.get_oil()) << endl;
	cout << "��������: ";
	switch (a.get_action())
	{
	case 1:
		cout << "������" << endl;
		break;
	case 2:
		cout << "�����" << endl;
		break;
	case 3:
		cout << "��" << endl;
		break;
	default:
		break;
	}
	cout << "������ ������: " << to_string(a.get_complete()) << endl;
}

//������� ��������� "����������" � ������
string to_my_string(Car a, int i)
{
	string c;
	switch (a.get_action())
	{
	case 1:
		c = "������\n";
		break;
	case 2:
		c = "�����\n";
		break;
	case 3:
		c = "��\n";
		break;
	default:
		break;
	}
	string result = "���������� �� ���������� � " + to_string(i) + "\n"
		+ "��� ���������: " + a.get_fio() + "\n"
		+ "��� ����� ����������: " + to_string(a.get_code()) + "\n"
		+ "����� ����������: " + a.get_name() + "\n"
		+ "����� �������: " + to_string(a.get_petrol()) + "\n"
		+ "�������� ���������: " + to_string(a.get_power()) + "\n"
		+ "����� ����: " + to_string(a.get_volume()) + "\n"
		+ "������� �������: " + to_string(a.get_res()) + "\n"
		+ "����� �����: " + to_string(a.get_volume()) + "\n"
		+ "��������: " + c
		+ "������ ������: " + to_string(a.get_complete()) + "\n";
	return result;
}

//���������� ��������� "����������" �� ������
Car from_my_string(ifstream& input)
{
	Car result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ���������: ";
			result.set_fio(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ����� ����������: ";
			result.set_code(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ����������: ";
			result.set_name(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� �������: ";
			result.set_petrol(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "�������� ���������: ";
			result.set_power(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ����: ";
			result.set_volume(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� �������: ";
			result.set_res(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� �����: ";
			result.set_oil(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��������: ";
			result.set_action(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������ ������: ";
			result.set_complete(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}

// ���� �������� ������ � ����������� �� ���������� ���� 
// Car_search - ��� ������
//1 - �� ����� ����������
//2 - ����� �������
//3 - �������� ���������
//4 - ������� ���������;
Car input_Car_search(int Car_search)
{
	Car result;
	switch (Car_search)
	{
	case 1:
		result.set_name(InputInformation("������� ����� ����������: "));
		return result;
		break;
	case 2:
		result.set_petrol(InputPetrol("������� ����� �������: "));
		return result;
		break;
	case 3:
		result.set_power(InputNumber(0, 1000, "������� �������� ���������: "));
		return result;
		break;
	case 4:
		result.set_fio(InputInformation("������� ��� ���������: "));
		return result;
		break;
	default:
		return result;
	}
}
// ����� ������� �������� �� ���������� ��������
// Car_search - ��� ������
//1 - �� ����� ����������
//2 - ����� �������
//3 - �������� ���������
//4 - ������� ���������;
bool search_element_name(Car m, Car n)
{
	return (m.get_name() == n.get_name());
}

bool search_element_petrol(Car m, Car n)
{
	return m.get_petrol() == n.get_petrol();
}

bool search_element_power(Car m, Car n)
{
	return m.get_power() == n.get_power();
}

bool search_element_fio(Car m, Car n)
{
	return m.get_fio() == n.get_fio();
}

// ��������� �������� � ����������� �� ���������� ���� ��� ����������
// Car_search - ��� ������
//1 - �� ����� ����������
//2 - ����� �������
//3 - �������� ���������
//4 - ������� ���������;
bool mysort_element_name(Car m, Car n)
{
	string a = m.get_name(), b = n.get_name();
	return a > b;
}
bool mysort_element_petrol(Car m, Car n)
{
	int a = m.get_petrol(), b = n.get_petrol();
	return a > b;
}
bool mysort_element_power(Car m, Car n)
{
	int a = m.get_power(), b = n.get_power();
	return a > b;
}
bool mysort_element_fio(Car m, Car n)
{
	string a = m.get_fio(), b = n.get_fio();
	return a > b;
}
