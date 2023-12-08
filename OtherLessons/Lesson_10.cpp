#include <iostream>
using namespace std;

int main()
{
	/*int start, end, i, j;

	cout << "Enter the number of the range (first num, second num): "; cin >> start >> end;
	
	for (i = start; i <= end; i++)
	{
		cout << i << ": ";
		for (j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}*/

	/*int end = 1000;

	for (int i = 3; i <= end; i++)
	{
		for (int j = 2; j <= end; j++)
		{
			if (i % j == 0)
			{
				if (i != j)
				{
					break;
				}
				cout << "Number: " << i << "\n";
			}
		}
	}*/

	/*int width;
	int height;
	cout << "Enter width of the shape (only odd number): ";
	cin >> width;
	cout << "Enter height of the shape (only odd number): ";
	cin >> height;
	if (width > 0 && (width % 2) != 0 and height > 0 && (height % 2) != 0) {
		for (int rows = 0; rows < width or rows < height; ++rows)
		{
			for (int column = 0; column < width or column > height; ++column)
			{
				if ((rows == column + ((height - width) / 2)) or (rows == height / 2) or (column == width / 2) or (rows + column == width - 1 + ((height - width)) / 2))
				{
					cout << " * ";
				}
				else cout << "   ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Error! Only odds numbers!";
	}*/

	/*int time = 0;

	for (int i = 100; i <= 999; i++) {
		int a = i / 100;
		int b = i / 10 % 10;
		int c = i % 10;
		if (a != b && a != c && b != c) {
			cout << i << endl;
		}
		time += 3;
	}
	time = time / 60;
	cout << "You'll spent " << time << " minutes, if your one try would be about 3 sec.";*/

	/*int enteredSal, sumSal = 0, salCvartal = 0, i = 1;

	cout << "\t----------Salary Calculator----------" << endl;

	for (; i <= 12; i++)
	{
		cout << "\n\t----------------March----------------" << endl;
		cout << "\tEnter salalry of " << i << " employee: "; cin >> enteredSal;
		if (enteredSal > 0)
		{
			sumSal = sumSal + enteredSal;
			salCvartal = salCvartal + enteredSal;
			for (; i <= 12; i++)
			{
				cout << "\n\t----------------April----------------" << endl;
				cout << "\tEnter salalry of " << i << " employee: "; cin >> enteredSal;
				sumSal = sumSal + enteredSal;
				salCvartal = salCvartal + enteredSal;
				for (; i <= 12; i++)
				{
					cout << "\n\t-----------------May-----------------" << endl;
					cout << "\tEnter salalry of " << i << " employee: "; cin >> enteredSal;
					sumSal = sumSal + enteredSal;
					salCvartal = salCvartal + enteredSal;
					cout << "\n\tCvartal salary of " << i << " worker is: " << salCvartal << endl;
					break;
				}
				break;
			}
		}
		else
		{
			cout << "\n\tError!" << endl;
			break;
		}
		salCvartal = 0;
	}

	cout << "\n\tSum salary of all workers is: " << sumSal << endl;*/

	/*int days = 0, weekends = 0, month = 0;
		cout << "Input a month number (1-12) -> ";
		cin >> month;
		cout << "Input a number day of week (1-7) when that month started -> ";
		cin >> days;
		switch (month)
		{
		case 1:cout << "\t\t\t\tJanuary\n"; month = 31; break;
		case 2:cout << "\t\t\t\tFebruary\n"; month = 28; break;
		case 3:cout << "\t\t\t\tMarch\n"; month = 31; break;
		case 4:cout << "\t\t\t\tApril\n"; month = 30; break;
		case 5:cout << "\t\t\t\tMay\n"; month = 31; break;
		case 6:cout << "\t\t\t\tJune\n"; month = 30; break;
		case 7:cout << "\t\t\t\tJJuly\n"; month = 31; break;
		case 8:cout << "\t\t\t\tAugust\n"; month = 31; break;
		case 9:cout << "\t\t\t\tSeptember\n"; month = 30; break;
		case 10:cout << "\t\t\t\tOctober\n"; month = 31; break;
		case 11:cout << "\t\t\t\tNoveber\n"; month = 30; break;
		case 12:cout << "\t\t\t\tDecember\n"; month = 31; break;
		}
		for (int i = 1; i < days; i++) cout << "\t";
		for (int i = 1; i <= month; i++)
		{
			cout << i << "\t";
			if ((i + days - 1) % 7 == 0) {
				cout << endl;
				weekends++;
			}
			if ((i + days - 3) % 6 == 0)
			{
				weekends++;
			}
		}
		cout << "\n That month weekends = " << weekends;*/

	/*int num, retNum = 0;

	cout << "Enter the num bigger than 0: "; cin >> num;
	if (num > 0)
	{
		while (num > 0)
		{
			retNum = num % 10 + retNum * 10;
			num /= 10;
		}
		cout << "Here is your number: " << retNum << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}*/
	
	/*int num, sum = 0;

	cout << "Enter the number: "; cin >> num;
	if (num > 0)
	{
		for (;num > 0;)
		{
			sum = num % 10 + sum;
			num /= 10;
		}
		cout << "Sum of your number: " << sum << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}*/
}