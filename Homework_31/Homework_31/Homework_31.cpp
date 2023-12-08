#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string secretText(string text, int num) 
{
	string secret = text;
	char s;
	for (size_t i = 0; i < text.size(); i++)
	{
		secret[i] = secret[i] + num;
		if (secret[i] > 'Z' && secret[i] < 'a' || secret[i] > 'z') {
			secret[i] = secret[i] - 26;
		}
	}
	return secret;
}

int main() 
{
	ifstream file1("file1.txt");
	ifstream file2("file2.txt");
	if (!file1.is_open()) {
		cout << "ERROR(file1)" << endl;
		return 0;
	}
	if (!file2.is_open()) {
		cout << "ERROR(file2)" << endl;
		return 0;
	}
	string line1, line2;
	int n = 0;
	bool fl1 = false, fl2 = false;
	while (!file1.eof() || !file2.eof()) 
	{
	cout <<"\t#" << ++n <<"\n\n";
	if (getline(file1, line1)) 
	{
		fl1 = true;
	}
	if (getline(file2, line2)) 
	{
		fl2 = true;
	}
	if (fl1 && fl2) {
		if (line1 != line2) 
		{
		cout << " File1 :: " << line1 << endl;
		cout << " File2 :: " << line2 <<"\n" << endl;
		}
		continue;
	}
	if (fl1) 
	{
		cout << " File1 :: " << line1 << endl;
	}
	if (fl2) 
	{
		cout << " File2 :: " << line2<<"\n" << endl;
	}
	cout << "====================================" << endl;
	}

	file1.close();
	file2.close();

	/*ifstream file("secreet.txt");
	if (!file.is_open()) {
		cout << "ERROR" << endl;
		return 0;
	}
	string text;
	int num;
	cout << "Enter number :: "; cin >> num;
	while (!file.eof())
	{
	getline(file, text);
	cout << secretText(text, num)<<endl;
	}
	file.close();*/

	/*ifstream file("file1.txt");
	if (!file.is_open()) {
		cout << "ERROR" << endl;
		return 0;
	}
	int symbols = 0;
	int lines = 0;
	int vowels = 0;
	int consonants = 0;
	int number = 0;
	string text;
	while (!file.eof())
	{
		getline(file, text);
		for (size_t i = 0; i < text.size(); i++)
		{
			if (isdigit(text[i])) { number++; }
			if (isgraph(text[i])) { symbols++; }
			if (tolower(text[i]) == 'a' or tolower(text[i]) == 'e' or tolower(text[i]) == 'i' or tolower(text[i]) == 'o' or tolower(text[i]) == 'u' or tolower(text[i]) == 'y') { vowels++; }
			if (tolower(text[i]) == 'b' or tolower(text[i]) == 'c' or tolower(text[i]) == 'd' or tolower(text[i]) == 'f' or tolower(text[i]) == 'g' or tolower(text[i]) == 'h' or tolower(text[i]) == 'j' or tolower(text[i]) == 'k' or tolower(text[i]) == 'l' or tolower(text[i]) == 'm' or tolower(text[i]) == 'n' or tolower(text[i]) == 'p' or tolower(text[i]) == 'q' or tolower(text[i]) == 'r' or tolower(text[i]) == 's' or tolower(text[i]) == 't' or tolower(text[i]) == 'v' or tolower(text[i]) == 'w' or tolower(text[i]) == 'x' or tolower(text[i]) == 'z') { consonants++; }
		}
		lines++;
	}
	lines--;
	cout << "Number  :: " << number << endl;
	cout << "Symbols :: " << symbols << endl;
	cout << "Lines   :: " << lines << endl;
	cout << "Vowels  :: " << vowels << endl;
	cout << "Consonants  :: " << consonants << endl;
	file.close();*/
}