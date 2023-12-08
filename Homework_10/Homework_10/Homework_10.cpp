#include <iostream>
using namespace std;

int main() {
	/*int lenght, width, col;
	char symbol;
	cout << "Choose a color of the console." << endl;
	cout << "1 - Blue, 2 - Green, 3 - Aqua, 4 - Red, 5 - Purple, 6 - Yellow." << endl;
	cout << "Enter your choice: "; cin >> col;
	cout << "\nEnter lenght of the shape: "; cin >> lenght;
	cout << "Enter width of the shape: "; cin >> width;
	cout << "Enter symbol of the shape: "; cin >> symbol;
	cout << "\n";
	switch (col)
	{
	case 1: {
		system("color 01");
		break;
	}
	case 2: {
		system("color 02");
		break;
	}
	case 3: {
		system("color 03");
		break;
	}
	case 4: {
		system("color 04");
		break;
	}
	case 5: {
		system("color 05");
		break;
	}
	case 6: {
		system("color 06");
		break;
	}
	default:
		break;
	}
	if (lenght > 2 and width > 2) {
		for (int i = 1; i <= lenght; i++)
		{
			if (i == 1 or i == lenght) {
				for (int j = 1; j <= width; j++) {
					cout << symbol;
				}
			}
			else if (i < width) {
				for (int k = 1; k <= width; k++) {
						if (k == 1) {
							cout << symbol;
						}
						else if (k == width) {
							cout << symbol;
						}
						else {
							cout << " ";
						}
				}
			}
			else {
					for (int j = 1; j <= width; j++) {
						cout << " ";
					}

			}
			cout << endl;
		}
	}
	else {
		cout << "Error!" << endl;
	}*/
	
	char symbol;
	int col;
	cout << "Choose a color of the console." << endl;
	cout << "1 - Blue, 2 - Green, 3 - Aqua, 4 - Red, 5 - Purple, 6 - Yellow." << endl;
	cout << "Enter your choice: "; cin >> col;
	cout << "\nEnter symbol of the shape: "; cin >> symbol;
	cout << "\n";

	switch (col)
	{
	case 1: {
		system("color 01");
		break;
	}
	case 2: {
		system("color 02");
		break;
	}
	case 3: {
		system("color 03");
		break;
	}
	case 4: {
		system("color 04");
		break;
	}
	case 5: {
		system("color 05");
		break;
	}
	case 6: {
		system("color 06");
		break;
	}
	default:
		break;
	}

	for (size_t j = 1; j < 10; j++)
	{
		for (size_t i = 0; i < j; i++)
		{
			if (j - i == 1) {
				cout << symbol;
			}
			else {
				cout << " ";
			}
		}
		for (size_t i = j * 2; i < 10 * 2; i++)
		{
			cout << " ";
		}
		for (size_t i = 0; i < j; i++)
		{
			if (i == 0) {
				cout << symbol;
			}
		}
		cout << endl;
	}

	for (int rows = 0; rows < 18; ++rows)
	{
		for (int column = 0; column < 18; ++column)
		{
			if ((column == 18 / 2))
			{
				cout << symbol;
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

}