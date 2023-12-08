#include <iostream>
using namespace std;

class Square;

class Rectangle
{
private:
    int height;
    int width;
public:
    Rectangle() :height(0), width(0) {}
    explicit Rectangle(int value) :height(value), width(value) {}
    Rectangle(int height, int width) :height(height), width(width) {}

    void Print()const
    {
        cout << "Height: " << height << " ";
        cout << "Width: " << width << endl;
    }
    //operator typename() {} //1
    //operator typename()const {} //2
    //explicit operator typename()const {} //3
    explicit operator int()
    {
        return height * width;
    }
    explicit operator Square();
};

class Square
{
    int side;
public:
    Square() :side(0) {}
    Square(int s) :side(s) {}

    void Print()const
    {
        cout << "Side: " << side << " ";
        cout << "Side: " << side << endl;
    }
    operator Rectangle()
    {
        Rectangle rect(side, side + 10);
        return rect;
    }
};

Rectangle::operator Square()
{
    return Square(height + width);
}

int main()
{
    int value = 9;
    double valDouble = value; // 9.0 -> int - double // standart to standart
    int a = (int)3.33; // standart to standart

    Rectangle rect(10, 15);
    Square sq(7);
    rect.Print();
    cout << endl;
    sq.Print();
    cout << endl;

    value = (int)rect; // abstract to standart
    cout << "Rect: " << value << endl;
    cout << endl;

    rect = sq;
    rect.Print();
    cout << endl;

    sq = (Square)rect;
    sq.Print();
    cout << endl;
}