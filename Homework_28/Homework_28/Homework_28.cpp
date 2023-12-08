#include <iostream>
#include <ctime>
using namespace std;

void fill(int** matrix, const int row, const int col, int min = 1, int max = 10)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % (max - min + 1) + min;
		}
	}
}
void print(int** matrix, const int row, const int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void transMatrix(int**& matrix, const int row, const int col)
{
	int** new_matrix = new int* [col];
	for (size_t i = 0; i < col; i++)
	{
		new_matrix[i] = new int[row];
		for (size_t j = 0; j < row; j++)
		{
			new_matrix[i][j] = matrix[j][i];
		}
	}
	for (size_t i = 0; i < col; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = new_matrix;
}

void enter(string** entries, int num)
{
	for (size_t i = 0; i < num; i++)
	{
		cout << "Enter name and phone number for entry " << i + 1 << ": ";
		cin >> entries[0][i] >> entries[1][i];
	}
}
void print_enter(string** entries, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << entries[0][i] << "\t" << entries[1][i] << endl;
	}
}

void nameSearch(string** entries, int num) {
	string search_name;
	cout << "Enter a name to search for: "; cin >> search_name;
	bool found = false;
	for (int i = 0; i < num; i++) 
	{
		if (entries[0][i] == search_name) 
		{
			cout << "Phone number for " << search_name << " is " << entries[1][i] << endl;
			found = true;
			break;
		}
	}
	if (!found) 
	{
		cout << "Entry not found for " << search_name << endl;
	}
}

void phoneSearch(string** entries, int num)
{
	string search_phone;
	cout << "Enter a phone number to search for: "; cin >> search_phone;
	bool found = false;
	for (int i = 0; i < num; i++)
	{
		if (entries[1][i] == search_phone) 
		{
			cout << "Name for phone number " << search_phone << " is " << entries[0][i] << endl;
			found = true;
			break;
		}
	}
	if (!found) 
	{
		cout << "Entry not found for " << search_phone << endl;
	}
}

void entriesModify(string** entries, int num)
{
	int entry_num;
	cout << "Enter the entry number to modify (1-" << num << "): "; cin >> entry_num;
	if (entry_num < 1 || entry_num > num)
	{
		cout << "Invalid entry number" << endl;
		return;
	}
	cout << "Enter new name and phone number for entry " << entry_num << ": ";
	cin >> entries[0][entry_num - 1] >> entries[1][entry_num - 1];
}



int main()
{
	srand(time(0));

    /*int row = 3, col = 3;
    int** matrix = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	fill(matrix, row, col);
	print(matrix, row, col);
	cout << endl;
	transMatrix(matrix, row, col);
	print(matrix, row, col);*/

	int num;
	cout << "Enter the number of entries: "; cin >> num;

	string** entries = new string * [2];
	for (int i = 0; i < 2; i++) 
	{
		entries[i] = new string[num];
	}

	enter(entries, num);
	while (true) 
	{
		cout << "\nSelect an operation:\n";
		cout << "1. Search by name\n";
		cout << "2. Search by phone number\n";
		cout << "3. Modify an entry\n";
		cout << "4. Print all entries\n";
		cout << "5. Exit\n";
		int choice; 
		cout << "> "; cin >> choice;
		cout << endl;

		switch (choice) 
		{
		case 1:
			nameSearch(entries, num);
			break;
		case 2:
			phoneSearch(entries, num);
			break;
		case 3:
			entriesModify(entries, num);
			break;
		case 4:
			print_enter(entries, num);
			break;
		case 5:
			for (int i = 0; i < 2; i++) 
			{
				delete[] entries[i];
			}
			delete[] entries;
			return 0;
		default:
			cout << "Invalid choice" << endl;
		}
	}
}