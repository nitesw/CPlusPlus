#include <iostream>
using namespace std;

int main()
{
    /*int entNum, sum = 0;

	cout << "Enter number: "; cin >> entNum;

	if (entNum <= 500)
	{
		while (entNum <= 500)
		{
			sum = sum + entNum;
			entNum++;
		}
		cout << "Sum of numbers is: " << sum << endl;
	}
	else
	{
		cout << "Error!";
	}*/
	
	/*int x, y, i = 1;

	cout << "Enter the two numbers (x y):"; cin >> x >> y;

	if (y > 0)
	{
		int tmp = x;
		while (i < y)
		{
			x = tmp * x;
			i++;
		}
		cout << "Here is your number " << x;
	}
	else
	{
		cout << "Error!";
	}*/
	
	/*int i = 0, sum = 0;

	while (i < 1000)
	{
		sum = sum + i;
		i++;
	}
	cout << "The sum of all numbers from 1 to 1000 eqaul to: " << sum << endl;
	cout << "So the arithmetic mean is: " << sum / 1000;*/

	/*long num;

	cout << "Enter the number: "; cin >> num;

	long sum = 1;
	if (num < 20 && num > 0)
	{
		while (num <= 20)
		{
			sum = sum * num;
			num++;
		}
		cout << "The multiplied number is: " << sum;
	}
	else
	{
		cout << "Error!";
	}*/

	int num, sum = 0;

	cout << "Enter a number to see its multiplication table: "; cin >> num;

	int i = 1;
	switch (num)
	{
	case 1:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	case 2:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	case 3:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	case 4:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	case 5:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	case 6:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	case 7:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	case 8:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	case 9:
	{
		while (i <= 10)
		{
			sum = num * i;
			cout << num << " x " << i << " = " << sum << endl;
			i++;
		}
		break;
	}
	default:
		cout << "Error!";
		break;
	}
}