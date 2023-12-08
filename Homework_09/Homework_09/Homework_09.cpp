#include <iostream>
using namespace std;

int main()
{
	/*int firstNum, secondNum, enterNum;

	cout << "Enter two numbers to set a range of numbers: "; cin >> firstNum >> secondNum;

	do
	{
		if (firstNum > secondNum)
		{
			int tmp = firstNum;
			firstNum = secondNum;
			firstNum = tmp;
		}

		cout << "Enter a number which fit into this range of numbers: "; cin >> enterNum;
	} while (enterNum < firstNum || enterNum > secondNum);

	cout << "\nCongrats! You successfully entered your own loop!" << endl;*/

	int enterProd, enterAmou, full_sum = 0, enterDiscount;
	int ging = 54, soda = 67, mand = 50, hat = 100;

	char choice, choiceDiscount;
	do
	{
		cout << "\t\t----------The cash register----------" << endl;
		cout << "\n\t\t1. Ginger bread - " << ging << " per one" << endl;
		cout << "\t\t2. Soda - " << soda << " per one" << endl;
		cout << "\t\t3. Mandarins - " << mand << " per one" << endl;
		cout << "\t\t4. Santa Claus hat - " << hat << " per one" << endl;
		cout << "\n\t\tEnter product's number: "; cin >> enterProd;

		if (enterProd > 0 && enterProd < 5)
		{
			switch (enterProd)
			{
			case 1:
			{
				for (;;)
				{
					cout << "\n\t\t-------------------------------------" << endl;
					cout << "\n\t\tEnter the amount of the product: "; cin >> enterAmou;
					cout << "\n\t\tDoes any discounts for this product? ([y] or [n]): "; cin >> choiceDiscount;
					if (choiceDiscount == 'y')
					{
						cout << "\n\t\tEnter product's discount: "; cin >> enterDiscount;
						if (enterDiscount > 0 && enterDiscount < 100)
						{
							float ging_sum = ging * enterAmou;
							float ging_discount = ging_sum - (static_cast<double>(ging_sum) / 100 * enterDiscount);
							full_sum = full_sum + ging_discount;
							break;
						}
					}
					else if (choiceDiscount == 'n')
					{
						int ging_sum = ging * enterAmou;
						full_sum = full_sum + ging_sum;
						break;
					}
				}
				break;
			}
			case 2:
			{
				for (;;)
				{
					cout << "\n\t\t-------------------------------------" << endl;
					cout << "\n\t\tEnter the amount of the product: "; cin >> enterAmou;
					cout << "\n\t\tDoes any discounts for this product? ([y] or [n]): "; cin >> choiceDiscount;
					if (choiceDiscount == 'y')
					{
						cout << "\n\t\tEnter product's discount: "; cin >> enterDiscount;
						if (enterDiscount > 0 && enterDiscount < 100)
						{
							float soda_sum = soda * enterAmou;
							float soda_discount = soda_sum - (static_cast<double>(soda_sum) / 100 * enterDiscount);
							full_sum = full_sum + soda_discount;
							break;
						}
					}
					else if (choiceDiscount == 'n')
					{
						int soda_sum = soda * enterAmou;
						full_sum = full_sum + soda_sum;
						break;
					}
				}
				break;
			}
			case 3:
			{
				for (;;)
				{
					cout << "\n\t\t-------------------------------------" << endl;
					cout << "\n\t\tEnter the amount of the product: "; cin >> enterAmou;
					cout << "\n\t\tDoes any discounts for this product? ([y] or [n]): "; cin >> choiceDiscount;
					if (choiceDiscount == 'y')
					{
						cout << "\n\t\tEnter product's discount: "; cin >> enterDiscount;
						if (enterDiscount > 0 && enterDiscount < 100)
						{
							float mand_sum = mand * enterAmou;
							float mand_discount = mand_sum - (static_cast<double>(mand_sum) / 100 * enterDiscount);
							full_sum = full_sum + mand_discount;
							break;
						}
					}
					else if (choiceDiscount == 'n')
					{
						int mand_sum = mand * enterAmou;
						full_sum = full_sum + mand_sum;
						break;
					}
				}
				break;
			}
			case 4:
			{
				for (;;)
				{
					cout << "\n\t\t-------------------------------------" << endl;
					cout << "\n\t\tEnter the amount of the product: "; cin >> enterAmou;
					cout << "\n\t\tDoes any discounts for this product? ([y] or [n]): "; cin >> choiceDiscount;
					if (choiceDiscount == 'y')
					{
						cout << "\n\t\tEnter product's discount: "; cin >> enterDiscount;
						if (enterDiscount > 0 && enterDiscount < 100)
						{
							float hat_sum = hat * enterAmou;
							float hat_discount = hat_sum - (static_cast<double>(hat_sum) / 100 * enterDiscount);
							full_sum = full_sum + hat_discount;
							break;
						}
					}
					else if (choiceDiscount == 'n')
					{
						int hat_sum = hat * enterAmou;
						full_sum = full_sum + hat_sum;
						break;
					}
				}
				break;
			}
			default:
				break;
			}

			for (;;)
			{
				cout << "\n\t\t-------------------------------------" << endl;
				cout << "\n\t\tWould you like to continue? yes or no ([y] or [n]): "; cin >> choice;
				cout << "\n\t\t-------------------------------------" << endl;
				if (choice == 'y' || choice == 'n')
				{
					break;
				}
			}
		}
		else
		{
		cout << "\n\t\t-------------------------------------" << endl;
		cout << "\t\t\t\tError!";
		cout << "\n\t\t-------------------------------------" << endl;
		break;
		}
	} while (choice != 'n');
	
	cout << "\n\t\tAmount due: " << full_sum << " UAH" << endl;
	cout << "\n\t\t-------------------------------------" << endl;
}