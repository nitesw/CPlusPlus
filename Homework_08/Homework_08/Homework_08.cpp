#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));

	int j = 0;
	int botGames = 0, userGames = 0;
	int timeStart = time(0);
	char userInput;
	do
	{
		j++;
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
				cout << "\t\t r - ROCK; \n\t\t p - PAPER; \n\t\t s - SCISSOR; \n\t\t l - LIZZARD; \n\t\t v - SPOCK; \n\t\t e - EXIT; \n\t\tEnter your choice: ";
				cin >> user;
				if (user == 'r' || user == 's' || user == 'p' || user == 'e' || user == 'l' || user == 'v') break;
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
			case 5: bot = 'v'; break;
			}


			if (user == 'r' && bot == 's' || user == 's' && bot == 'p' || user == 'p' && bot == 'r' || user == 'r' && bot == 'l' || user == 'v' && bot == 's' || user == 'l' && bot == 'v' || user == 'p' && bot == 'v' || user == 'l' && bot == 'p' || user == 'v' && bot == 'r') userScore++;
			else if (bot == 'r' && user == 's' || bot == 's' && user == 'p' || bot == 'p' && user == 'r' || bot == 'r' && user == 'l' || bot == 'v' && user == 's' || bot == 'l' && user == 'v' || bot == 'p' && user == 'v' || bot == 'l' && user == 'p' || bot == 'v' && user == 'r') botScore++;



			cout << "\n\t\tBot chose: " << bot << endl;
			cout << "\n\t\tBot score: " << botScore << "\t\tUser score: " << userScore << endl;
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
				userGames++;
			}
			else if (userScore < botScore)
			{
				cout << "\n\t\t   ======== You lost! You are loser! ========" << endl;
				botGames++;
			}
			else
			{
				cout << "\n\t\t   ================ Draw! ================" << endl;
			}
		}
		for (;;)
		{
			cout << "\n\t\t\t\tTime you spent: " << time(0) - timeStart << endl;
			cout << "\n\t\t\t\tYou played " << j << " games" << endl;
			cout << "\n\t\t   User won " << userGames << " games\t";
			cout << "\tBot won " << botGames << " games" << endl;
			cout << "\n\t\t\t\t[y] - yes; [n] - no: "; cin >> userInput;
			if (userInput == 'y' || userInput == 'n')
			{
				break;
			}
		}
	} while (userInput != 'n');
}
