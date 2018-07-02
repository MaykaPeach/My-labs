#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <string>
#include <fstream>
#include <istream>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

// ���� �����
int InputNumber(int min, int max, const string &message);

// ���� �������
int InputPetrol(const string &message);

// ���� ����������
string InputInformation(const string &message);

// �������� ������� �� ������������ � ����� �����
bool CorrectSymbol(const char c);


// �������� ����� ����� �� �����������
bool CorrectName(const string &name);

// ���� ����� �����
string InputFileName();