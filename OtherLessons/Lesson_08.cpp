#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	/*size_t i = 1;
	for (; i <= 10;)
	{
		i++;
		cout << i << endl;
	}

	cout << "End value: " << i << endl;*/

	/*int num;

	for (; ;)
	{
		cout << "Enter the number: "; cin >> num;
		if (num == 99) break;
	}*/

	/*srand(time(0));
	for (size_t i = 0; i < 10; i++)
	{
		int number = rand() % 299 + 1;

		int counter = 0;
		int tmp = number;
		while (tmp > 0)
		{
			tmp /= 10;
			counter++;
		}

		if (counter == 2) continue;

		cout << "Number is: " << number << endl;
	}*/

	/*int number;
	cout << "Enter a number: ";
	cin >> number;

	int temp = number;
	int result = 0;
	int place = 1;

	for (; temp > 0;) {
		int digit = temp % 10;
		if (digit != 3 && digit != 6) {
			result += digit * place;
			place *= 10;
		}
		temp /= 10;
	}

	cout << "New number: " << result;*/

	srand(time(0));

	char userInput;
	do
	{
		cout << "\n\t\t================== START GAME ==================" << endl;
		cout << "\n\t\t============== ROCK PAPER SCISSOR ==============" << endl;

		int i = 0;
		int userScore = 0, botScore = 0;
		char user, bot;

		while (i < 5)
		{
			i++;
			cout << "\n\t\t   ================ Round #" << i << " ================" << endl << endl;

			while (true)
			{
				cout << "\t\t r - ROCK; \n\t\t p - PAPER; \n\t\t s - SCISSOR; \n\t\t l - LIZZARD; \n\t\t w - SPOCK; \n\t\t e - EXIT; \n\t\tEnter your choice: ";
				cin >> user;
				if (user == 'r' || user == 's' || user == 'p' || user == 'e' || user == 'l' || user == 'w') break;
				cout << "\n\t\t==================== ERORR ====================" << endl;
			}
			if (user == 'e') break;

			int random = rand() % 5 + 1;

			switch (random)
			{
			case 1: bot = 'r'; break;
			case 2: bot = 'p'; break;
			case 3: bot = 's'; break;
			case 4: bot = 'l'; break;
			case 5: bot = 'w'; break;
			}

			if (user == 'r' && bot == 's' || user == 's' && bot == 'p' || user == 'p' && bot == 'r') userScore++;
			else if (bot == 'r' && user == 's' || bot == 's' && user == 'p' || bot == 'p' && user == 'r') botScore++;

			cout << "\n\t\tBot chose: " << bot << endl;
		}
		if (user == 'e')
		{
			cout << "\n\t\t   ======== You are run out of the game! =======";
		}
		else
		{
			if (userScore > botScore)
			{
				cout << "\n\t\t   ======== Congratulations! You won! ========" << endl;
			}
			else if (userScore < botScore)
			{
				cout << "\n\t\t   ======== You lost! You are loser! ========" << endl;
			}
			else
			{
				cout << "\n\t\t   ================ Draw! ================" << endl;
			}
		}
		for (;;)
		{
			cout << "[y] - yes; [n] - no"; cin >> userInput;
			if (userInput == 'y' || userInput == 'n')
			{
				break;
			}
		}
	} while (userInput != 'n');
}