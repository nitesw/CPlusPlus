#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

enum Key
{
    RIGHT = 77, LEFT = 75, UP = 72, DOWN = 80
};

int main()
{
    srand(time(0));

    /*const int ROW = 3, COL = 4;
    int arr[ROW][COL], num, sum = 1;

    cout << "Enter num: "; cin >> num;

    sum = num;
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            sum *= 2;
            arr[j][i] = sum;
        }
    }
    cout << "--------------------------------------" << endl;
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }*/

    /*const int ROW = 3, COL = 4;
    int arr[ROW][COL], num, sum = 1;

    cout << "Enter num: "; cin >> num;

    sum = num;
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            sum += 1;
            arr[j][i] = sum;
        }
    }
    cout << "--------------------------------------" << endl;
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }*/

    const int ROW = 4, COL = 4;
    int arr[ROW][COL];

    cout << "Move an array using Up/Down/Left/Right keys (press Esc to exit)." << endl;

    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            arr[j][i] = rand() % 30 + 1;
        }
    }
    cout << "----------------------------------------------------" << endl;
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            cout << arr[j][i] << " \t ";
        }
        cout << endl;
    }
    cout << "----------------------------------------------------" << endl;
    char n;
    do
    {
        n = _getch();
        system("cls");
        switch (n)
        {
        case RIGHT:
        {
            cout << "Move an array using Up/Down/Left/Right keys (to exit press Esc)." << endl;
            cout << "----------------------------------------------------" << endl;
            for (size_t i = 0; i < ROW; i++)
            {
                int tmp = arr[i][COL - 1];
                for (size_t j = COL - 1; j > 0; j--)
                {
                    arr[i][j] = arr[i][j - 1];
                }
                arr[i][0] = tmp;
            }
            for (size_t j = 0; j < ROW; j++)
            {
                for (size_t i = 0; i < COL; i++)
                {
                    cout << arr[j][i] << " \t ";
                }
                cout << endl;
            }
            cout << "----------------------------------------------------" << endl;
            break;
        }
        case LEFT:
        {
            cout << "Move an array using Up/Down/Left/Right keys (to exit press Esc)." << endl;
            cout << "----------------------------------------------------" << endl;
            for (size_t i = 0; i < ROW; i++)
            {
                int tmp = arr[i][0];
                for (size_t j = 0; j < COL; j++)
                {
                    arr[i][j] = arr[i][j + 1];
                }
                arr[i][COL - 1] = tmp;
            }
            for (size_t j = 0; j < ROW; j++)
            {
                for (size_t i = 0; i < COL; i++)
                {
                    cout << arr[j][i] << " \t ";
                }
                cout << endl;
            }
            cout << "----------------------------------------------------" << endl;
            break;
        }
        case DOWN:
        {
            cout << "Move an array using Up/Down/Left/Right keys (to exit press Esc)." << endl;
            cout << "----------------------------------------------------" << endl;
            for (size_t i = 0; i < COL; i++)
            {
                int tmp = arr[ROW - 1][i];
                for (size_t j = ROW - 1; j > 0; j--)
                {
                    arr[j][i] = arr[j - 1][i];
                }
                arr[0][i] = tmp;
            }
            for (size_t j = 0; j < ROW; j++)
            {
                for (size_t i = 0; i < COL; i++)
                {
                    cout << arr[j][i] << " \t ";
                }
                cout << endl;
            }
            cout << "----------------------------------------------------" << endl;
            break;
        }
        case UP:
        {
            cout << "Move an array using Up/Down/Left/Right keys (to exit press Esc)." << endl;
            cout << "----------------------------------------------------" << endl;
            for (size_t i = 0; i < COL; i++)
            {
                int tmp = arr[0][i];
                for (size_t j = 0; j < ROW - 1; j++)
                {
                    arr[j][i] = arr[j + 1][i];
                }
                arr[ROW - 1][i] = tmp;
            }
            for (size_t j = 0; j < ROW; j++)
            {
                for (size_t i = 0; i < COL; i++)
                {
                    cout << arr[j][i] << " \t ";
                }
                cout << endl;
            }
            cout << "----------------------------------------------------" << endl;
            break;
        }
        default:
            break;
        }
    } while (n != 27);
    cout << "Thanks for moving an array. Bye!" << endl;
}