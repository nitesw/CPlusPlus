#include <iostream>
using namespace std;

size_t mystrlen(char* str)
{
    size_t counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

char* mystrcpy(char* str1, const char* str2) 
{
    char* p = str1;
    while (*str2 != '\0') {
        *p++ = *str2++;
    }
    *p = '\0';
    return str1;
}

char* mystrcat(char* str1, const char* str2) 
{
    char* res = str1;
    while (*str1) 
    {
        str1++;
    }
    while (*str2) 
    {
        *str1 = *str2;
        *str1++;
        *str2++;
    }
    *str1 = '\0';
    return res;
}

char* mystrchr(char* str, char s)
{
    char* tmp = str;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (s == *tmp)
        {
            return tmp;
        }
        tmp++;
    }
}

int main()
{
    /*char str1[50];
    const char* str2 = "Hello world!";

    cout << str1 << endl;
    mystrcpy(str1, str2);
    cout << str1 << endl;*/

    /*char str1[50] = "Hello ";
    char str2[50] = "World";
    cout << mystrcat(str1, str2) << endl;*/

    /*cout << mystrchr(str1, 'e');*/

    //char str[50] = "C++";
    //char str2[] = "JavaScript";

    //cout << "Str 1: " << str << endl;
    //cout << "Str 2: " << str2 << endl << endl;

    ////strcpy_s(str, str2);
    //strcpy_s(str, "C#"); // copy str2 in str

    //cout << "Str 1: " << str << endl;
    //cout << "Str 2: " << str2 << endl << endl;

    //strcat_s(str, ", "); // units str and str2
    //strcat_s(str, str2);

    //cout << "Str 1: " << str << endl;
    //cout << "Str 2: " << str2 << endl << endl;

    //strncpy_s(str, str2, 4); // copy n-symbols of str2 in str

    //cout << "Str 1: " << str << endl;
    //cout << "Str 2: " << str2 << endl << endl;

    //strncat_s(str, str2, 4); // units str and n-symbols of str2 

    //cout << "Str 1: " << str << endl;
    //cout << "Str 2: " << str2 << endl << endl;

    //cout << "Length str1: " << strlen(str) << endl << endl;

    //cout << "Str 1: " << str << endl;
    //cout << "Str 2: " << str2 << endl << endl;

    //char line1[] = "Abdcfn";
    //char line2[] = "Abdrtd";

    ///*
    //line1 > line2 => 1
    //line1 < line2 => -1
    //line1 == line2 => 0
    //*/

    //cout << "Line 1: " << line1 << endl;
    //cout << "Line 2: " << line2 << endl;
    //cout << "line1 < line2 => " << strcmp(line1, line2) << endl;
    //strcpy_s(line1, "Abdz");

    //cout << "Line 1: " << line1 << endl;
    //cout << "Line 2: " << line2 << endl;
    //cout << "line1 > line2 => " << strcmp(line1, line2) << endl;

    //strcpy_s(line1, "Abdrtd");
    //cout << "Line 1: " << line1 << endl;
    //cout << "Line 2: " << line2 << endl;
    //cout << "line1 == line2 => " << strcmp(line1, line2) << endl;

    //// boolean function for char
    /*char test_char[] = "5& bgAj28";*/
    //cout << "\n\n============= isalpha =============\n\n";
    //for (size_t i = 0; i < strlen(test_char); i++)
    //{
    //    cout << "\t " << test_char[i] << " ---> " << isalpha(test_char[i]) << endl;
    //}
    //cout << "\n\n===================================\n\n";

    /*cout << "\n\n============= isdigit =============\n\n";
    for (size_t i = 0; i < strlen(test_char); i++)
    {
        cout << "\t " << test_char[i] << " ---> " << isdigit(test_char[i]) << endl;
    }
    cout << "\n\n===================================\n\n";*/

    //cout << "\n\n============= isalnum =============\n\n";
    //for (size_t i = 0; i < strlen(test_char); i++)
    //{
    //    cout << "\t " << test_char[i] << " ---> " << isalnum(test_char[i]) << endl;
    //}
    //cout << "\n\n===================================\n\n";

    //cout << "\n\n============= isspace =============\n\n";
    //for (size_t i = 0; i < strlen(test_char); i++)
    //{
    //    cout << "\t " << test_char[i] << " ---> " << isspace(test_char[i]) << endl;
    //}
    //cout << "\n\n===================================\n\n";

    //cout << "\n\n============= islower =============\n\n";
    //for (size_t i = 0; i < strlen(test_char); i++)
    //{
    //    cout << "\t " << test_char[i] << " ---> " << islower(test_char[i]) << endl;
    //}
    //cout << "\n\n===================================\n\n";

    //cout << "\n\n============= isupper =============\n\n";
    //for (size_t i = 0; i < strlen(test_char); i++)
    //{
    //    cout << "\t " << test_char[i] << " ---> " << isupper(test_char[i]) << endl;
    //}
    //cout << "\n\n===================================\n\n";


    //char arr[] = "hyper text markup language";
    //cout << "Line: " << arr << endl;
    //for (size_t i = 0; i < strlen(arr); i++)
    //{
    //    arr[i] = toupper(arr[i]);
    //}
    //cout << "Line after toupper: " << arr << endl;
    //for (size_t i = 0; i < strlen(arr); i++)
    //{
    //    arr[i] = tolower(arr[i]);
    //}
    //cout << "Line after tolower: " << arr << endl;

    char str[50];
    cout << "Enter text: ";
    //cin >> str;
    cin.getline(str, 50);
    cout << "\n\nResult: " << str << endl;
}