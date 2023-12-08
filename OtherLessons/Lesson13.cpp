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
    int arr[ROW][COL], sum = 0, rowSum = 0, colSum = 0;
    double avg;*/

    /*arr[0][0] = rand() % 20 + 1;
    arr[0][1] = rand() % 20 + 1;
    arr[0][2] = rand() % 20 + 1;
    arr[0][3] = rand() % 20 + 1;
    arr[0][4] = rand() % 20 + 1;
    arr[0][5] = rand() % 20 + 1;

    for (size_t i = 0; i < COL; i++)
    {
        arr[0][i] = rand() % 20 + 1;
    }
    for (size_t i = 0; i < COL; i++)
    {
        arr[1][i] = rand() % 20 + 1;
    }
    for (size_t i = 0; i < COL; i++)
    {
        arr[2][i] = rand() % 20 + 1;
    }
    for (size_t i = 0; i < COL; i++)
    {
        arr[3][i] = rand() % 20 + 1;
    }
    for (size_t i = 0; i < COL; i++)
    {
        arr[4][i] = rand() % 20 + 1;
    }
    for (size_t i = 0; i < COL; i++)
    {
        arr[5][i] = rand() % 20 + 1;
    }*/

    /*for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            arr[j][i] = rand() % 20 + 1;
        }
    }
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            cout << arr[j][i] << " \t ";
        }
        cout << endl;
    }*/

    /*for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            arr[j][i] = rand() % 10 + 1;
        }
    }
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            cout << arr[j][i] << " \t ";
        }
        cout << endl;
    }

    int min = arr[0][0], max = arr[0][0];
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
           sum += arr[j][i];
           if (min > arr[j][i])
           {
               min = arr[j][i];
           }
           if (max < arr[j][i])
           {
               max = arr[j][i];
           }
        }
    }
    avg = (double)sum / (COL * ROW);
    cout << "=================================" << endl;
    cout << "Sum of all elements: " << sum << endl;
    cout << "Avarage of all elements: " << avg << endl;
    cout << "Min element: " << min << endl;
    cout << "Max element: " << max << endl;*/

    /*for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            arr[j][i] = rand() % 10 + 1;
            sum += arr[j][i];
        }
    }
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            cout << arr[j][i] << "\t";
            rowSum += arr[j][i];
        }
        cout << "|\t" << rowSum;
        rowSum = 0;
        cout << endl;
    }
    cout << "-------------------------------------------" << endl;
    for (size_t i = 0; i < COL; i++)
    {
        for (size_t j = 0; j < ROW; j++)
        {
            colSum += arr[j][i];
        }
        cout << colSum << "\t";
        colSum = 0;
    }
    cout << "|\t" << sum;*/

    /*const int ROW = 5, COL = 10, COL1 = 5;
    int arr[ROW][COL], arr1[ROW][COL1], sum = 0;

    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            arr[j][i] = rand() % 51;
        }
    }
    cout << "Original array: " << endl;
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            cout << arr[j][i] << " \t ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Summarise array: " << endl;
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL1; i++)
        {
            sum = arr[j][i * 2] + arr[j][i * 2 + 1];
            arr1[j][i] = sum;
        }
        sum = 0;
    }
    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL1; i++)
        {
            cout << arr1[j][i] << " \t ";
        }
        cout << endl;
    }*/

    const int ROW = 3, COL = 4;
    int arr[ROW][COL];

    for (size_t j = 0; j < ROW; j++)
    {
        for (size_t i = 0; i < COL; i++)
        {
            arr[j][i] = rand() % 20 + 1;
        }
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
    char n;
    do
    {
        n = _getch();
        system("cls");
        switch (n)
        {
        case RIGHT:
        {
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
        case UP:
        {
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
}