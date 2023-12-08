#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

struct Coord
{
    int x;
    int y;
};

class MyRectangle
{
private:
    int width;
    int height;
    char symbol;
    Coord coords;
public:
    MyRectangle()
    {
        width = 0;
        height = 0;
        symbol = '*';
        coords = { 2,2 };
    }
    MyRectangle(int size)
    {
        this->height = size;
        this->width = size;
    }
    MyRectangle(int w, int h)
    {
        this->height = h;
        this->width = w;
    }
    void setWidth(int width)
    {
        this->width = width;
    }
    int getWidth()
    {
        return width;
    }
    void setHeight(int height)
    {
        this->height = height;
    }
    int getHeight()
    {
        return height;
    }
    void setCoords(Coord Cx, Coord Cy)
    {
        this->coords.x = Cx.x;
        this->coords.y = Cy.y;
    }
    Coord getCoords()
    {
        return coords;
    }
    void Init()
    {
        do
        {
            cout << "Enter height: "; cin >> height;
            cout << "\nEnter width: "; cin >> width;
            cout << "\nEnter coords: "; cin >> coords.x; cin >> coords.y;
            system("cls");
        } while (height < 1 || width < 1 || coords.x < 0 || coords.y < 0);
    }
    void newHeightAndWidthInit()
    {
        do
        {
            cout << "\nEnter new height: "; cin >> height;
            cout << "\nEnter new width: "; cin >> width;
            system("cls");
        } while (height < 1 || width < 1); 
    }
    void newCoordsInit()
    {
        do
        {
            cout << "\nEnter new coords (x, y): "; cin >> coords.x; cin >> coords.y;
            system("cls");
        } while (coords.x < 0 || coords.y < 0); 
    }
    void printRect(char s)
    {
        symbol = s;
        gotoxy(coords.x, coords.y);
        int tmp_x = coords.x;
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                cout << symbol;
                coords.x++;
                gotoxy(coords.x, coords.y);
            }
            cout << endl;
            coords.x = tmp_x;
            coords.y++;
            gotoxy(coords.x, coords.y);
        }
    }
};

int main()
{
    MyRectangle rect;
    rect.Init();
    rect.printRect('*');
    rect.newHeightAndWidthInit();
    rect.newCoordsInit();
    rect.printRect('*');
    int choice;
    do
    {
        cout << "\n\nPress 1 to delete the rectangle: ";
        cin >> choice;
        if (choice == 1) system("cls");
    } while (choice != 1);

    MyRectangle rect1(5);
    rect1.printRect('/');
    do
    {
        cout << "\n\nPress 1 to delete the rectangle: ";
        cin >> choice;
        if (choice == 1) system("cls");
    } while (choice != 1);

    MyRectangle rect2(8, 4);
    rect2.printRect('$');
    do
    {
        cout << "\n\nPress 1 to delete the rectangle: ";
        cin >> choice;
        if (choice == 1) system("cls");
    } while (choice != 1);
}