#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int sum(int a, int b);
double sum(double a, double b);
char sum(char a, int offset);
string sum(string str1, string str2);
int sub(int a, int b);
int mult(int a, int b);
double divid(int a, int b);
double calculate(int a, int b, char op = '+');