#include <iostream>
using namespace std;

size_t STRLEN(char* str)
{
    size_t counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

int CompareLength(char* str1, char* str2)
{
    if (STRLEN(str1) == STRLEN(str2)) return 0;
    return STRLEN(str1) > STRLEN(str2) ? 1 : -1;
}

void UpperFirstLetter(char* str)
{
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] -= 32;
    }
}

int counterVoiceLetter(char* str)
{
    char voice[] = "aeuiyoAEUIYO";
    int counter = 0;
    for (size_t i = 0; i < STRLEN(str); i++)
    {
        for (size_t j = 0; j < STRLEN(voice); j++)
        {
            if (str[i] == voice[j])
            {
                counter++;
                break;
            }
        }
    }
    return counter;
}

void truncate(char* str, int num)
{
    if (strlen(str) > num)
    {
        str[num - 3] = '.';
        str[num - 2] = '.';
        str[num - 1] = '.';
        str[num] = '\0';
    }
}

bool isPal(char* str)
{
    int length = STRLEN(str);
    int backlength = length - 1;
    bool flag = false;

    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == str[backlength])
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
        backlength--;
    }
    return flag;
}

int countWords(char* str)
{
    int counter = 0;
    int word_counter = 0;
    while (str[counter] != '\0')
    {
        if (str[counter] == ' ')
        {
            word_counter++;
        }
        counter++;
    }
    return word_counter + 1;
}

int main()
{
    /*char str[]{ 'H', 'E', 'L', 'L', 'O', '\0' };
    char str2[50] = "Hello world!";
    char* str3 = new char[20]{"test"};
    cout << "Enter word: "; cin >> str2;
    cout << "Length of " << str2 << ": " << STRLEN(str2) << endl;*/

    /*char str1[] = "abcd";
    char str2[] = "abcdef";
    cout << "Result: " << CompareLength(str1, str2) << endl;*/

    /*char line[] = "lorem Ipsum dolor";
    UpperFirstLetter(line);
    cout << "Result line: " << line << endl;
    cout << "Result line: " << counterVoiceLetter(line) << endl;*/

    /*char str[] = "Hello World!";
    truncate(str, 5);
    cout << "Result: " << str << endl;*/

    char word[] = "deed";
    cout << isPal(word) << endl;

    char line[] = "deer deed dead";
    cout << "Words in line: " << countWords(line) << endl;
}