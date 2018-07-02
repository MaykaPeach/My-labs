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

// ¬вод числа
int InputNumber(int min, int max, const string &message);

// ¬вод бензина
int InputPetrol(const string &message);

// ввод информации
string InputInformation(const string &message);

// проверка символа на корректность в имени файла
bool CorrectSymbol(const char c);


// проверка имени файла на коректность
bool CorrectName(const string &name);

// ввод имени файла
string InputFileName();