#pragma once
#include <string>
#include <fstream>
#include <cmath>
#include "HelpUtils.h"

using namespace std;

class Car {
private:
	string _fio; // владелец
	int _brand_code;  // код марки машины
	string _brand_name; 	// марка машины
	int _petrol; //марка бензина
	int _engine_power; //мощность двигателя
	int _tank_volume; //объем бака бензина
	int _residue_petrol; //остаток бензина
	int _oil_volume; //объем масла
	int _action; //требуемое действие
	bool _complete; //выполнение заказа
public:
	Car();
	Car& operator=(Car const&); // перегруженный оператор равенства для структуры "автомобиль"

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

//методы
Car input_Car(); // функция ввода структуры "автомобиль" с консоли
void output_Car(Car); // функция вывода структуры "автомобиль" на консольYe
string to_my_string(Car, int); //перевод структуры "автомобиль" в строку
Car from_my_string(ifstream&); // считывание структуры "автомобиль" из строки
Car input_Car_search(int); // ввод критерия поиска в зависимости от выбранного типа

						   // поиск равного элемента по выбранному критерию
bool search_element_name(Car, Car);
bool search_element_petrol(Car, Car);
bool search_element_power(Car, Car);
bool search_element_fio(Car, Car);

// сравнения структур в зависимости от выбранного поля для сортировки
bool mysort_element_name(Car, Car);
bool mysort_element_petrol(Car, Car);
bool mysort_element_power(Car, Car);
bool mysort_element_fio(Car, Car);

