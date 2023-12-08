#include <iostream>
using namespace std;

void stats(char* line)
{
	int numCounter = 0;
	int alpCounter = 0;
	int symCounter = 0;
	for (size_t i = 0; i < strlen(line); i++)
	{
		if (isdigit(line[i]))
		{
			numCounter++;
		}
		else if (isalpha(line[i]))
		{
			alpCounter++;
		}
		else
		{
			symCounter++;
		}
	}

	cout << "Numbers in line: " << numCounter << endl;
	cout << "Letters in line: " << alpCounter << endl;
	cout << "Other symbols in line: " << symCounter << endl;
}

void change(char* line)
{
	for (size_t i = 0; i < strlen(line); i++)
	{
		if (isupper(line[i]))
		{
			line[i] = tolower(line[i]);
		}
		else if (islower(line[i]))
		{
			line[i] = toupper(line[i]);
		}
		else if (isdigit(line[i]))
		{
			line[i] = '_';
		}
	}
	for (size_t i = 0; i < strlen(line); i++)
	{
		cout << line[i];
	}
	cout << endl;
}

void abbreviation(char* line)
{
	string result;
	bool newWord = true;

	for (size_t i = 0; i < strlen(line); i++) 
	{
		if (newWord && isalpha(line[i])) 
		{
			result += toupper(line[i]);
			newWord = false;
		}
		else if (line[i] == ' ') 
		{
			newWord = true;
		}
	}

	cout << result << endl;
}

int main()
{
    char test_char1[] = "5aBv87dF.:qR";
    char test_char2[] = "national new life";

	stats(test_char1);
	cout << endl;

	cout << "Original: ";
	for (size_t i = 0; i < strlen(test_char1); i++)
	{
		cout << test_char1[i];
	}
	cout << endl;
	cout << "Changed: ";
	change(test_char1);

	abbreviation(test_char2);
}