#include <iostream>
using namespace std;

enum Suit
{
	HEARTS, DIAMONDS, CLUBS, SPADES
};
enum Rank
{
	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

int range(int num1, int num2)
{
	int sum = 0;

	if (num1 > num2)
	{
		int tmp = num2;
		num2 = num1;
		num1 = tmp;
		for (size_t i = num1; i <= num2; i++)
		{
			sum += i;
		}
		return sum;
	}
	for (size_t i = num1; i <= num2; i++)
	{
		sum += i;
	}
	return sum;
}

void excellentNum()
{
	int num, sum = 0;

	cout << "Enter the number: "; cin >> num;

	for (size_t i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			sum += i;
		}
	}
	if (num == sum)
	{
		cout << "Your number is perfect number" << endl;
	}
	else
	{
		cout << "Your number is not perfect number" << endl;
	}
}

int luckyNum(int num)
{
	bool isLucky;

	int a = num % 10;
	num /= 10;
	int b = num % 10;
	num /= 10;
	int c = num % 10;
	num /= 10;
	int d = num % 10;
	num /= 10;
	int e = num % 10;
	num /= 10;
	int f = num % 10;
	num /= 10;

	if (a + b + c == d + e + f)
	{
		return true;
	}
	return false;
}

void printCrad()
{
	int suitNum, rankNum;
	string suitName, rankName;

	cout << "Enter the suit of the crad (0 - Hearts, 1 - Diamonds, 2 - Clubs, 3 - Spades): ";
	cin >> suitNum;
	switch (suitNum)
	{
	case HEARTS:
	{
		suitName = "hearts";
		break;
	}
	case DIAMONDS:
	{
		suitName = "diamonds";
		break;
	}
	case CLUBS:
	{
		suitName = "clubs";
		break;
	}
	case SPADES:
	{
		suitName = "spades";
		break;
	}
	default:
		cout << "Incorrect number!" << endl;
		break;
	}

	cout << "Enter the rank of the crad (0 - Ace, 1 - Two, 2 - Three, 3 - Four, 4 - Five, 5 - Six, 6 - Seven, 7 - Eight, 8- Nine, 9 - Ten, 10 - Jack, 11 - Queen, 12 - King): ";
	cin >> rankNum;
	switch (rankNum)
	{
	case ACE:
	{
		rankName = "Ace";
		break;
	}
	case TWO:
	{
		rankName = "Two";
		break;
	}
	case THREE:
	{
		rankName = "Three";
		break;
	}
	case FOUR:
	{
		rankName = "Four";
		break;
	}
	case FIVE:
	{
		rankName = "Five";
		break;
	}
	case SIX:
	{
		rankName = "Six";
		break;
	}
	case SEVEN:
	{
		rankName = "Seven";
		break;
	}
	case EIGHT:
	{
		rankName = "Eight";
		break;
	}
	case NINE:
	{
		rankName = "Nine";
		break;
	}
	case TEN:
	{
		rankName = "Ten";
		break;
	}
	case JACK:
	{
		rankName = "Jack";
		break;
	}
	case QUEEN:
	{
		rankName = "Queen";
		break;
	}
	case KING:
	{
		rankName = "King";
		break;
	}
	default:
		cout << "Incorrect number!" << endl;
		break;
		break;
	}

	cout << "\nHere is you card: " << rankName << " " << suitName << endl;
}

int main()
{
	/*int num1, num2;

	cout << "Enter two numbers to make a range: "; cin >> num1 >> num2;
	
	int res_sum = range(num1, num2);

	cout << "Sum of all numbers in range of your numbers: " << res_sum << endl;*/

	//excellentNum();

	/*int num;

	cout << "Enter the 6-digits number: ";  cin >> num;

	if (num > 99999 && num < 1000000)
	{
		int res_isLucky = luckyNum(num);
		if (res_isLucky == 1)
		{
			cout << "Your number is lucky!" << endl;
		}
		else
		{
			cout << "Your number is not lucky..." << endl;
		}
	}
	else
	{
		cout << "Sorry! Ony 6-digits number allowed!" << endl;
	}*/

	printCrad();
}