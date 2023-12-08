#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));

	const int ROW = 3, COL = 3;
	char game[ROW][COL]{};
	int help[ROW][COL]{};
	char choice;

	do
	{
		for (size_t i = 0; i < ROW; i++)
		{
			for (size_t j = 0; j < COL; j++)
			{
				game[i][j] = ' ';
			}
		}
		for (size_t i = 0, q = 1; i < ROW; i++)
		{
			for (size_t j = 0; j < COL; j++)
			{
				help[i][j] = q++;
			}
		}

		int counter = 0;
		char user = 'X', bot = 'O';
		int user_row, user_col, bot_row, bot_col;
		int user_choice, bot_choice;
		char win = '*';
		char step = 'X';

		// Print
		cout << "\n\n";
		for (size_t i = 0; i < ROW; i++)
		{
			// Print game field
			cout << " \t \t ";
			for (size_t j = 0; j < COL; j++)
			{
				cout << " " << game[i][j] << " ";
				if (j != COL - 1) cout << char(179);
			}
			// Print help field
			cout << " \t \t ";
			for (size_t j = 0; j < COL; j++)
			{
				cout << " " << help[i][j] << " ";
				if (j != COL - 1) cout << char(179);
			}
			cout << endl;
			// Print bottom lines
			for (size_t q = 0; q < 2; q++)
			{
				cout << " \t \t ";
				for (size_t j = 0; j < COL * 4; j++)
				{
					if (j != 0 && (j + 1) % 4 == 0 && j != COL * 4 - 1 && i != ROW - 1)
					{
						cout << char(197);
						continue;
					}
					if (i != ROW - 1 && j != COL * 4 - 1)
					{
						cout << char(196);
					}
				}
			}
			cout << endl;
		}

		while (counter < 9)
		{

			counter++;

			if (step == user)
			{
				while (true)
				{
					cout << "Enter your choice [1-9]: ";
					cin >> user_choice;
					if (user_choice < 1 || user_choice > 9)
					{
						continue;
					}
					switch (user_choice)
					{
					case 1:
					{
						user_row = 0;
						user_col = 0;
						break;
					}
					case 2:
					{
						user_row = 0;
						user_col = 1;
						break;
					}
					case 3:
					{
						user_row = 0;
						user_col = 2;
						break;
					}
					case 4:
					{
						user_row = 1;
						user_col = 0;
						break;
					}
					case 5:
					{
						user_row = 1;
						user_col = 1;
						break;
					}
					case 6:
					{
						user_row = 1;
						user_col = 2;
						break;
					}
					case 7:
					{
						user_row = 2;
						user_col = 0;
						break;
					}
					case 8:
					{
						user_row = 2;
						user_col = 1;
						break;
					}
					case 9:
					{
						user_row = 2;
						user_col = 2;
						break;
					}
					}
					if (game[user_row][user_col] == ' ')
					{
						game[user_row][user_col] = user;
						break;
					}
				}
				step = bot;
			}

			else {
				while (true)
				{
					if (game[0][0] == 'O' and game[0][1] == 'O' and game[0][2] == ' ') {
						bot_choice = 3;
					}
					else if (game[0][1] == 'O' and game[0][2] == 'O' and game[0][0] == ' ') {
						bot_choice = 1;
					}
					else if (game[0][0] == 'O' and game[0][2] == 'O' and game[0][1] == ' ') {
						bot_choice = 2;
					}

					else if (game[1][0] == 'O' and game[1][1] == 'O' and game[1][2] == ' ') {
						bot_choice = 6;
					}
					else if (game[1][1] == 'O' and game[1][2] == 'O' and game[1][0] == ' ') {
						bot_choice = 4;
					}
					else if (game[1][0] == 'O' and game[1][2] == 'O' and game[1][1] == ' ') {
						bot_choice = 5;
					}

					else if (game[2][0] == 'O' and game[2][1] == 'O' and game[2][2] == ' ') {
						bot_choice = 9;
					}
					else if (game[2][1] == 'O' and game[2][2] == 'O' and game[2][0] == ' ') {
						bot_choice = 7;
					}
					else if (game[2][0] == 'O' and game[2][2] == 'O' and game[2][1] == ' ') {
						bot_choice = 8;
					}

					else if (game[0][0] == 'O' and game[1][0] == 'O' and game[2][0] == ' ') {
						bot_choice = 7;
					}
					else if (game[0][0] == 'O' and game[2][0] == 'O' and game[1][0] == ' ') {
						bot_choice = 4;
					}
					else if (game[1][0] == 'O' and game[2][0] == 'O' and game[0][0] == ' ') {
						bot_choice = 1;
					}

					else if (game[0][1] == 'O' and game[1][1] == 'O' and game[2][1] == ' ') {
						bot_choice = 8;
					}
					else if (game[0][1] == 'O' and game[2][1] == 'O' and game[1][1] == ' ') {
						bot_choice = 5;
					}
					else if (game[1][1] == 'O' and game[2][1] == 'O' and game[0][1] == ' ') {
						bot_choice = 2;
					}

					else if (game[0][2] == 'O' and game[1][2] == 'O' and game[2][2] == ' ') {
						bot_choice = 9;
					}
					else if (game[0][2] == 'O' and game[2][2] == 'O' and game[1][2] == ' ') {
						bot_choice = 6;
					}
					else if (game[1][2] == 'O' and game[2][2] == 'O' and game[0][2] == ' ') {
						bot_choice = 3;
					}

					else if (game[0][0] == 'O' and game[1][1] == 'O' and game[2][2] == ' ') {
						bot_choice = 9;
					}
					else if (game[1][1] == 'O' and game[2][2] == 'O' and game[0][0] == ' ') {
						bot_choice = 1;
					}
					else if (game[0][0] == 'O' and game[2][2] == 'O' and game[1][1] == ' ') {
						bot_choice = 5;
					}

					else if (game[0][2] == 'O' and game[1][1] == 'O' and game[2][0] == ' ') {
						bot_choice = 7;
					}
					else if (game[0][2] == 'O' and game[2][0] == 'O' and game[1][1] == ' ') {
						bot_choice = 5;
					}
					else if (game[1][1] == 'O' and game[2][0] == 'O' and game[0][2] == ' ') {
						bot_choice = 3;
					}

					else if (game[0][0] == 'X' and game[0][1] == 'X' and game[0][2] == ' ') {
						bot_choice = 3;
					}
					else if (game[0][1] == 'X' and game[0][2] == 'X' and game[0][0] == ' ') {
						bot_choice = 1;
					}
					else if (game[0][0] == 'X' and game[0][2] == 'X' and game[0][1] == ' ') {
						bot_choice = 2;
					}

					else if (game[1][0] == 'X' and game[1][1] == 'X' and game[1][2] == ' ') {
						bot_choice = 6;
					}
					else if (game[1][1] == 'X' and game[1][2] == 'X' and game[1][0] == ' ') {
						bot_choice = 4;
					}
					else if (game[1][0] == 'X' and game[1][2] == 'X' and game[1][1] == ' ') {
						bot_choice = 5;
					}

					else if (game[2][0] == 'X' and game[2][1] == 'X' and game[2][2] == ' ') {
						bot_choice = 9;
					}
					else if (game[2][1] == 'X' and game[2][2] == 'X' and game[2][0] == ' ') {
						bot_choice = 7;
					}
					else if (game[2][0] == 'X' and game[2][2] == 'X' and game[2][1] == ' ') {
						bot_choice = 8;
					}

					else if (game[0][0] == 'X' and game[1][0] == 'X' and game[2][0] == ' ') {
						bot_choice = 7;
					}
					else if (game[0][0] == 'X' and game[2][0] == 'X' and game[1][0] == ' ') {
						bot_choice = 4;
					}
					else if (game[1][0] == 'X' and game[2][0] == 'X' and game[0][0] == ' ') {
						bot_choice = 1;
					}

					else if (game[0][1] == 'X' and game[1][1] == 'X' and game[2][1] == ' ') {
						bot_choice = 8;
					}
					else if (game[0][1] == 'X' and game[2][1] == 'X' and game[1][1] == ' ') {
						bot_choice = 5;
					}
					else if (game[1][1] == 'X' and game[2][1] == 'X' and game[0][1] == ' ') {
						bot_choice = 2;
					}

					else if (game[0][2] == 'X' and game[1][2] == 'X' and game[2][2] == ' ') {
						bot_choice = 9;
					}
					else if (game[0][2] == 'X' and game[2][2] == 'X' and game[1][2] == ' ') {
						bot_choice = 6;
					}
					else if (game[1][2] == 'X' and game[2][2] == 'X' and game[0][2] == ' ') {
						bot_choice = 3;
					}

					else if (game[0][0] == 'X' and game[1][1] == 'X' and game[2][2] == ' ') {
						bot_choice = 9;
					}
					else if (game[1][1] == 'X' and game[2][2] == 'X' and game[0][0] == ' ') {
						bot_choice = 1;
					}
					else if (game[0][0] == 'X' and game[2][2] == 'X' and game[1][1] == ' ') {
						bot_choice = 5;
					}

					else if (game[0][2] == 'X' and game[1][1] == 'X' and game[2][0] == ' ') {
						bot_choice = 7;
					}
					else if (game[0][2] == 'X' and game[2][0] == 'X' and game[1][1] == ' ') {
						bot_choice = 5;
					}
					else if (game[1][1] == 'X' and game[2][0] == 'X' and game[0][2] == ' ') {
						bot_choice = 3;
					}

					else {
						bot_choice = rand() % 9 + 1;
					}
					switch (bot_choice)
					{
					case 1: {
						bot_row = 0;
						bot_col = 0;
						break;
					}
					case 2: {
						bot_row = 0;
						bot_col = 1;
						break;
					}
					case 3: {
						bot_row = 0;
						bot_col = 2;
						break;
					}
					case 4: {
						bot_row = 1;
						bot_col = 0;
						break;
					}
					case 5: {
						bot_row = 1;
						bot_col = 1;
						break;
					}
					case 6: {
						bot_row = 1;
						bot_col = 2;
						break;
					}
					case 7: {
						bot_row = 2;
						bot_col = 0;
						break;
					}
					case 8: {
						bot_row = 2;
						bot_col = 1;
						break;
					}
					case 9: {
						bot_row = 2;
						bot_col = 2;
						break;
					}
					}
					if (game[bot_row][bot_col] == ' ') {
						game[bot_row][bot_col] = bot;
						break;
					}
				}
				step = user;
			}
			// Print
			cout << "\n\n";
			for (size_t i = 0; i < ROW; i++)
			{
				// Print game field
				cout << " \t \t ";
				for (size_t j = 0; j < COL; j++)
				{
					cout << " " << game[i][j] << " ";
					if (j != COL - 1) cout << char(179);
				}
				// Print help field
				cout << " \t \t ";
				for (size_t j = 0; j < COL; j++)
				{
					cout << " " << help[i][j] << " ";
					if (j != COL - 1) cout << char(179);
				}
				cout << endl;
				// Print bottom lines
				for (size_t q = 0; q < 2; q++)
				{
					cout << " \t \t ";
					for (size_t j = 0; j < COL * 4; j++)
					{
						if (j != 0 && (j + 1) % 4 == 0 && j != COL * 4 - 1 && i != ROW - 1)
						{
							cout << char(197);
							continue;
						}
						if (i != ROW - 1 && j != COL * 4 - 1)
						{
							cout << char(196);
						}
					}
				}
				cout << endl;
			}

			bool flag = false, stop = false;
			// Check if win (horizontal)
			for (size_t i = 0; i < ROW; i++)
			{
				for (size_t j = 0; j < COL - 1; j++)
				{
					if (game[i][j] == game[i][j + 1] && game[i][j] != ' ')
					{
						flag = true;
					}
					else
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					win = game[i][0];
					stop = true;
					break;
				}
			}

			// Check if win (vertical)
			for (size_t i = 0; i < COL && !flag; i++)
			{
				for (size_t j = 0; j < ROW - 1; j++)
				{
					if (game[j][i] == game[j + 1][i] && game[j][i] != ' ')
					{
						flag = true;
					}
					else
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					win = game[0][i];
					stop = true;
					break;
				}
			}

			for (size_t i = 0; i < ROW - 1 && !stop; i++)
			{
				if (game[i][i] == game[i + 1][i + 1] && game[i][i] != ' ')
				{
					flag = true;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag && !stop)
			{
				win = game[1][1];
				stop = true;
			}
			for (size_t i = 0; i < ROW - 1 && !stop; i++)
			{
				if (game[i][ROW - i - 1] == game[i + 1][ROW - i - 2] && game[i][ROW - i - 1] != ' ')
				{
					flag = true;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag && !stop)
			{
				win = game[1][1];
			}

			if (win != '*')
			{
				break;
			}
		}
		if (win == '*')
		{
			cout << "\n\n\t\t ====== Draw ======\n\n";
		}
		else
		{
			cout << "\n\n\t\t ====== " << win << "'s won ======\n\n";
		}

		for (;;)
		{
			cout << "\n \t \t Would like to play again? [y]/[n]: "; cin >> choice;

			if (choice == 'y')
			{
				break;
			}
			else if (choice == 'n')
			{
				break;
			}
		}
	} while (choice != 'n');
	
}