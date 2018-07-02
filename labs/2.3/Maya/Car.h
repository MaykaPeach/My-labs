#pragma once
#include <string>
#include <fstream>
#include <cmath>
#include "HelpUtils.h"

using namespace std;

class Car {
private:
	string _fio; // ��������
	int _brand_code;  // ��� ����� ������
	string _brand_name; 	// ����� ������
	int _petrol; //����� �������
	int _engine_power; //�������� ���������
	int _tank_volume; //����� ���� �������
	int _residue_petrol; //������� �������
	int _oil_volume; //����� �����
	int _action; //��������� ��������
	bool _complete; //���������� ������
public:
	Car();
	Car& operator=(Car const&); // ������������� �������� ��������� ��� ��������� "����������"

	//get
	string get_fio() const;
	int get_code() const;
	string get_name() const;
	int get_petrol() const;
	int get_power() const;
	int get_volume() const;
	int get_res() const;
	int get_oil() const;
	int get_action() const;
	bool get_complete() const;

	//set
	void set_fio(const string&);
	void set_code(int);
	void set_name(const string&);
	void set_petrol(int);
	void set_power(int);
	void set_volume(int);
	void set_res(int);
	void set_oil(int);
	void set_action(int);
	void set_complete(bool);
};

//������
Car input_Car(); // ������� ����� ��������� "����������" � �������
void output_Car(Car); // ������� ������ ��������� "����������" �� �������Ye
string to_my_string(Car, int); //������� ��������� "����������" � ������
Car from_my_string(ifstream&); // ���������� ��������� "����������" �� ������
Car input_Car_search(int); // ���� �������� ������ � ����������� �� ���������� ����

						   // ����� ������� �������� �� ���������� ��������
bool search_element_name(Car, Car);
bool search_element_petrol(Car, Car);
bool search_element_power(Car, Car);
bool search_element_fio(Car, Car);

// ��������� �������� � ����������� �� ���������� ���� ��� ����������
bool mysort_element_name(Car, Car);
bool mysort_element_petrol(Car, Car);
bool mysort_element_power(Car, Car);
bool mysort_element_fio(Car, Car);

