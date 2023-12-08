#include <iostream>
using namespace std;

int main()
{
    int selery, lines, delays, num, sel1;

	cout << "\t\tEnter the number (1, 2, 3): " << endl;
    cout << "1 - The desired income and the number of delays.";
	cout << "\n2 - Enter the number of lines of code and the desired income.";
	cout << "\n3 - Enter the number of lines of code and the number of delays." << endl;
	cout << "> ";  cin >> num;

	switch (num)
	{
	case 1:
	{
		cout << "Enter the desired income: "; cin >> selery;
		cout << "Enter the number of delays: "; cin >> delays;
		cout << "You must write " << (selery / 50 * 100) + (delays / 3 * 40) << " lines of code";
		break;
	}
	case 2:
	{
		cout << "Enter the number of lines of code: "; cin >> lines;
		cout << "Enter the desired income: "; cin >> selery;
		if (lines / 2 <= selery)
		{
			cout << "You can't be late";
		}
		else
		{
			delays = (lines / 2 - selery) / 20;
			cout << "You can be late " << delays << (delays == 1 ? " time" : " times");
		}
		break;
	}
	case 3:
	{
		cout << "Enter the number of lines of code: "; cin >> lines;
		cout << "Enter the number of delays: "; cin >> delays;
		sel1 = ((lines / 2) - (delays / 3 * 20));
		
		if (sel1 / 20 > 0)
		{
			cout << "You will be paid " << sel1 << " USD";
		}
		else
		{
			cout << "You won't be paid";
		}
		break;
	}
	default:
		cout << "Oops... You entered wrong number";
		break;
	}
}