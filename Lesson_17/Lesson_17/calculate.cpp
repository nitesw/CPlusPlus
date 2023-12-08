#include "calculate.h"

int sum(int a, int b)
{
	return a + b;
}

double sum(double a, double b)
{
	double sum = a + b;
	cout << sum << endl;
	return sum;
}

// A, D
char sum(char a, int offset)
{
	return a + offset;
}

string sum(string str1, string str2)
{
	return str1 + str2;
}

int sub(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a * b;
}

double divid(int a, int b)
{
	return b == 0 ? 0 : (double)a / b;
}

double calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
	{
		return sum(a, b);
	}
	case '-':
	{
		return sub(a, b);
	}
	case '*':
	{
		return mult(a, b);
	}
	case '/':
	{
		return divid(a, b);
	}
	}
}
