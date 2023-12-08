#include <iostream>
using namespace std;

int main()
{
	int userInput, line;
	do
	{
		cout << "Enter the integer number to see the shape (1 - first, 2 - second ... 10 - tenth (111 - exit)): "; cin >> userInput;

		switch (userInput)
		{
		case 3:
		{
			cout << "How long will be your shape: ";  cin >> line;

			for (size_t q = 0, s = line * 2 - 1; q < line; q++, s -= 2)
			{
				for (size_t i = 0; i < q; i++)
				{
					cout << " ";
				}
				for (size_t i = 0; i < s; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		case 4:
		{
			cout << "How long will be your shape: "; cin >> line;
			for (size_t q = 0, s = line - (line - 1); q < line; q++, s += 2)
			{
				for (size_t i = line - 1; i > q; i--)
				{
					cout << " ";
				}
				for (size_t i = 0; i < s; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		case 1:
		{
			cout << "How long will be your shape: ";  cin >> line;

			for (size_t q = 0, s = line * 2 - 1; q < line; q++, s -= 2)
			{
				for (size_t i = 0; i < q; i++)
				{
					cout << "  ";
				}
				for (size_t i = 0; i < s; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		case 2:
		{
			cout << "How long will be your shape: "; cin >> line;
			for (size_t q = 0, s = line - (line - 1); q < line; q++, s += 2)
			{
				for (size_t i = 0; i > q; i--)
				{
					cout << " ";
				}
				for (size_t i = 0; i < s; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		case 5:
		{
			cout << "How long will be your shape: ";  cin >> line;

			for (size_t q = 0, s = line * 2 - 1; q < line; q++, s -= 2)
			{
				for (size_t i = 0; i < q; i++)
				{
					cout << " ";
				}
				for (size_t i = 0; i < s; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			for (size_t q = 0, s = line - (line - 1); q < line; q++, s += 2)
			{
				for (size_t i = line - 1; i > q; i--)
				{
					cout << " ";
				}
				for (size_t i = 0; i < s; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		case 6:
		{
			cout << "How long will be your shape: ";  cin >> line;

			for (size_t j = 1; j <= line; j++)
			{
				for (size_t i = 0; i < j; i++)
				{
					cout << "*";
				}
				for (size_t i = j * 2; i < line * 2; i++)
				{
					cout << " ";
				}
				for (size_t i = 0; i < j; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			for (size_t j = 1; j <= line; j++)
			{
				for (size_t i = j; i < line; i++)
				{
					cout << "*";
				}
				for (size_t i = 0; i < j * 2; i++)
				{
					cout << " ";
				}
				for (size_t i = j; i < line; i++)
				{
					cout << "*";
				}
				cout << endl;
			}

		}
		case 7:
		{
			cout << "How long will be your shape: ";  cin >> line;

			for (size_t j = 1; j <= line; j++)
			{
				for (size_t i = 0; i < j; i++)
				{
					cout << "*";
				}
				for (size_t i = j * 2; i < line * 2; i++)
				{
					cout << " ";
				}
				cout << endl;
			}
			for (size_t j = 1; j <= line; j++)
			{
				for (size_t i = j; i < line; i++)
				{
					cout << "*";
				}
				for (size_t i = 0; i < j * 2; i++)
				{
					cout << " ";
				}
				cout << endl;
			}
		}
		case 8:
		{
			cout << "How long will be your shape: ";  cin >> line;

			for (size_t j = 1; j <= line; j++)
			{
				for (size_t i = j; i < line; i++)
				{
					cout << " ";
				}
				for (size_t i = 0; i < j; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			for (size_t j = 1; j <= line - 1; j++)
			{
				for (size_t i = 0; i < j; i++)
				{
					cout << " ";
				}
				for (size_t i = j; i < line; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		case 9:
		{
			cout << "How long will be your shape: ";  cin >> line;

			for (size_t q = 0, s = line * 2 - 1; q < line; q++, s -= 2)
			{
				for (size_t i = line; i < q; i--)
				{
					cout << " ";
				}
				for (size_t i = 0; i < s; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		case 10:
		{
			cout << "How long will be your shape: ";  cin >> line;

			for (size_t j = 1; j < line; j++)
			{
				for (size_t i = j; i < line; i++)
				{
					cout << " ";
				}
				for (size_t i = 0; i < j; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		default:
			break;
		}
	} while (userInput != 111);
}