#pragma once

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