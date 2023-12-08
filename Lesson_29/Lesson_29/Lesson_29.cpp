#include <iostream>
using namespace std;

struct BirthDate
{
    int day;
    int month;
    int year;
};

struct Student
{
    //char lastName[30];
    char name[30];
    double rating;
    //char group[30];
    BirthDate date;
    //char phone[13];
    //char email[30];
    int marks[10];
};

struct Rectangle
{
    int x, y;
    int height, width;
};

char* numberInStr(int number)
{
    int i = 0;
    int tmp = number;
    while (number != 0)
    {
        i++;
        number /= 10;
    }
    char* numberStr = new char[i + 1];
    number = tmp;
    for (size_t j = 0; j < i; j++)
    {
        int n = number % 10;
        number /= 10;
        numberStr[i - 1 - j] = (n + 48);
    }
    numberStr[i] = '\0';
    return numberStr;
}
char* printDate(BirthDate date)
{
    char str[30] = "";
    if (date.day < 10)
    {
        strcat_s(str, "0");
    }
    strcat_s(str, numberInStr(date.day));
    strcat_s(str, ".");

    if (date.month < 10)
    {
        strcat_s(str, "0");
    }
    strcat_s(str, numberInStr(date.month));
    strcat_s(str, ".");
    strcat_s(str, numberInStr(date.year));
    char* tmp = new char[strlen(str)];
    tmp[strlen(str)] = '\0';
    for (size_t i = 0; i < strlen(str); i++)
    {
        tmp[i] = str[i];
    }
    return tmp;
}

void printStudent(Student stud)
{
    static int number = 1;
    cout << "\n =============== Student #" << number++ << " ===============\n";
    cout << "\t Name: " << stud.name << endl;
    cout << "\t Rating: " << stud.rating << endl;
    cout << "\t BirthDate: " << printDate(stud.date) << endl;
    cout << "\t Marks: ";
    for (size_t i = 0; i < sizeof(stud.marks) / sizeof(stud.marks[0]); i++)
    {
        cout << stud.marks[i] << "\t";
    }
    cout << endl;
}
void fillStudent(Student& stud)
{
    int number = 1;
    cout << "\n =============== Student #" << number++ << " ===============\n";
    cout << "\t Name: "; cin >> stud.name;
    cout << "\t Rating: "; cin >> stud.rating;
    cout << "\t BirthDate: "; cin >> stud.date.day >> stud.date.month >> stud.date.year;
    cout << "\t Marks: ";
    for (size_t i = 0; i < sizeof(stud.marks) / sizeof(stud.marks[0]); i++)
    {
        cin >> stud.marks[i];
    }
    cout << endl;
}

void fillRectangle(Rectangle& rect)
{
    static int num = 1;
    cout << "Enter the height and the width of the " << num++ << " rectangle: "; cin >> rect.height >> rect.width;
}
void resize(Rectangle& rect, int newWidth, int newHeight) {
    rect.width = newWidth;
    rect.height = newHeight;
}
void move(Rectangle& rect, int dx, int dy) {
    rect.x += dx;
    rect.y += dy;
}
void printRectangle(Rectangle rect)
{
    cout << "Rectangle ( x=" << rect.x << ", y=" << rect.y << ", width=" << rect.width << ", height=" << rect.height << " )\n\n";
    for (int i = 1; i <= rect.height; i++) {
        for (int j = 1; j <= rect.width; j++) {
            cout << '*';
        }
        cout << endl;
    }
}

int main()
{
    /*Student andrii = { "Pedos", "Andrii", 9.5, "BV211", 27, 2, 2007, "380980506652", "apedos2007@gmail.com", 
        {10, 11, 12, 9, 11, 12, 12, 10, 11, 12} };*/
    /*Student andrii = { "Andrii", 9.5, {27, 2, 2007}, {10, 11, 12, 9, 11, 12, 12, 10, 11, 12} };
    printStudent(andrii);

    Student olya{};
    fillStudent(olya);
    printStudent(olya);*/
    /*strcpy_s(andrii.name, "Andrii");
    strcpy_s(andrii.lastName, "Pedos");
    andrii.rating = 9.2;
    andrii.birthDay = 27;
    andrii.birthMonth = 02;
    andrii.birthYear = 2007;
    cout << andrii.lastName << endl;
    cout << andrii.name << endl;
    cout << andrii.date.day << andrii.date.month << andrii.date.year << endl;
    cout << andrii.rating << endl;
    cout << andrii.marks[0] << ", " << andrii.marks[1] << endl;*/

    Rectangle rect{};
    fillRectangle(rect);
    printRectangle(rect);
    cout << endl;
    resize(rect, 2, 4);
    printRectangle(rect);
    cout << endl;
    move(rect, 7, 3);
    printRectangle(rect);
}