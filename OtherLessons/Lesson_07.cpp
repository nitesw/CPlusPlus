#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    /*int i = 0;
    while (i < 10)
    {
        cout << ++i << ". dude" << endl;
    }*/

    /*int i = 10;
    while (i > 0)
    {
        cout << i-- << endl;
    }*/

    /*int i = 1;
    while (i <= 50)
    {
        cout << i << endl;
        i += 3;
    }*/

    /*int i = 0, num;

    cout << "Enter the number: "; cin >> num;

    while (i < num || i > num)
    {
        cout << (num > 0 ? i++ : i--) << endl;
    }*/

    /*int answer;

    do
    {
        cout << "2 + 2 = ?: "; cin >> answer;
    } while (answer != 4);*/

    /*int start, end;
    cout << "Enter start & end: "; cin >> start >> end;

    if (start > end)
    {
        int tmp = start;
        start = end;
        end = tmp;
    }
    int i = start;
    cout << "All numbers: ";
    while (start <= end)
    {
        cout << start++ << "\t ";
    }
    cout << endl;

    start = i;
    cout << "All even numbers: ";
    while (start <= end)
    {
        if (start % 2 == 0)
        {
            cout << start << "\t ";
        }
        start++;
    }
    cout << endl;

    start = i;
    cout << "All odd numbers: ";
    while (start <= end)
    {
        if (start % 3 == 0)
        {
            cout << start << "\t ";
        }
        start++;
    }
    cout << endl;
    
    start = i;
    cout << "All odd numbers: ";
    while (start <= end)
    {
        if (start % 3 == 0)
        {
            cout << start << "\t ";
        }
        start++;
    }
    cout << endl;
    
    start = i;
    cout << "All numbers are multiples of 7: ";
    while (start <= end)
    {
        if (start % 7 == 0)
        {
            cout << start << "\t ";
        }
        start++;
    }
    cout << endl;*/

    /*int start, end, all = 0;

    cout << "Enter start & end: "; cin >> start >> end;

    if (start > end)
    {
        int tmp = start;
        start = end;
        end = tmp;
    }

    while (start <= end)
    {
        all = all + start;
        start++;
    }

    cout << all;*/

    /*int num, sum = 0;
    
    do
    {
        cout << "Enter any number which you want to sum (0 to stop): ";
        cin >> num;
        sum = sum + num;
    } while (num != 0);
    cout << sum;*/

    /*int startNum = 100, endNum = 999, counter = 0, counter1 = 0, a, b, c;

    
    do {
        startNum++;
        a = startNum / 100;
        b = startNum % 100 / 10;
        c = startNum % 10;
        if ( a == b || b == c || c == a ) {
            counter++;
        }
        if (a != b && b != c && c != a) {
            counter1++;
        }
    } while (startNum <= endNum);
    cout << "A quantity with two identical numbers: " << counter << endl;
    cout << "Quantity with different numbers: " << counter1 << endl;*/

    srand(time(0));
    // min + rand() % (max - min + 1)
    int number = rand() % 500 + 1;
    int counter = 0; 
    int timeStart = time(0);
    int user_number;

    cout << "Game has been started!" << endl;
    do
    {
        cout << "Enter number: ";
        cin >> user_number;
        if (user_number > number)
        {
            cout << "Your number bigger" << endl;
        }
        else if (user_number < number)
        {
            cout << "Your number smaller" << endl;
        }
        counter++;
    } while (user_number != number && user_number != 0);

    cout << "You spent " << counter << " attemps" << endl;
    cout << "Time you spent: " << time(0) - timeStart << endl;
}