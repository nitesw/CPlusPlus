#include <iostream>
using namespace std;

int letterSearch(char* arr, char letter) {
    int counter = 0;
    for (size_t i = 0; i < strlen(arr); i++)
    {
        if (letter == arr[i]) counter++;
    }
    return counter;
}

int main()
{
    /*char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    cout << str << endl;
    char word;
    char replacement;
    cout << "What word do you want to replace and which one?: "; cin >> word >> replacement;*/

    /*char arr[] = "hello world!";
    cout << "Array: " << arr <<endl;
    cout << "Result: ";
    if (islower(arr[0]) == 2) 
    {
        arr[0] -= 32;
        cout << arr;
    }
    else cout << arr;*/

    /*char arr[] = "Hello World!";
    int i = 0;
    cout << "Array: " << arr << endl;
    while (arr[i] != '\0')
    {
        char letter = arr[i];
        cout << "Letter(" << arr[i] << ") = " << letterSearch(arr, letter) << endl;
        i++;
    }*/

    //4
    char arr[] = "5 4 3 2 1... BOOM! The bomb is exploded!";
    int counter = 0;
    int i = 0;
    cout << "Array: " << arr << endl;
    while (arr[i] != '\0')
    {
        if (isdigit(arr[i]) == 4) counter++;
        i++;
    }
    cout << "Number = " << counter;
}