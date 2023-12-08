#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int value)
    {
        x = y = value;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()const
    {
        cout << "X: " << x << " Y: " << y << endl;
    }
    Point Plus(const Point& other)const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point Minus(const Point& other)const
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }

    Point operator +(const Point& other)const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator +(int value)const
    {
        Point res(this->x + value, this->y + value);
        return res;
    }
    Point operator -(const Point& other)const
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator /(const Point& other)const
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }
    Point operator *(const Point& other)const
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator +=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Point operator -()const
    {
        return Point(-x, -y);
    }
    Point operator =(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
    bool operator <(const Point& other)
    {
        /*if ((this->x + this->y) < (other.x + other.y))
        {
            return true;
        }
        else
        {
            return false;
        }*/
        return (this->x + this->y) < (other.x + other.y);
    }
    bool operator >(const Point& other)
    {
        return (this->x + this->y) > (other.x + other.y);
    }
    bool operator >=(const Point& other)
    {
        return (this->x + this->y) >= (other.x + other.y);
    }
    bool operator <=(const Point& other)
    {
        return (this->x + this->y) <= (other.x + other.y);
    }
    bool operator ==(const Point& other)
    {
        return (this->x == other.x) && (this->y == other.y);
    }
    bool operator !=(const Point& other)
    {
        //return (this->x != other.x) || (this->y != other.y);
        return !(*this == other);
    }
};

int main()
{
    int a = 5;
    int b = 7;
    cout << a + b << endl << endl;

    Point point1(10, 5);
    Point point2(5, 8);

    if (point1 == point2)
    {
        cout << "Point 1 and point 2 is the same" << endl;
    }
    else
    {
        cout << "Point 1 and point 2 is not the same" << endl;
    }
    if (point1 < point2)
    {
        cout << "Point 1 is smaller than point 2" << endl;
    }
    else
    {
        cout << "Point 1 is not smaller than point 2" << endl;
    }
    if (point1 > point2)
    {
        cout << "Point 1 is bigger than point 2" << endl;
    }
    else
    {
        cout << "Point 1 is not bigger than point 2" << endl;
    }

    Point res = point1.Plus(point2);
    cout << "\nPoint 1: "; point1.Print();
    cout << "Point 2: "; point2.Print();
    cout << "Plus res: "; res.Print();
    res = point1.Minus(point2);
    cout << "Minus res: "; res.Print();

    //point1 = point2; //<-
    res = point1 = point2;
    cout << "\nPoint 1: "; point1.Print();
    cout << "Point 2: "; point2.Print();
    cout << "Res: "; res.Print();

    //res = point1.operator+(point2);
    res = point1 + point2;
    cout << "\nPlus res: "; res.Print();

    cout << "\nPoint 2: "; point2.Print();
    res = point2 + 50;
    cout << "Plus res: "; res.Print();

    res = point1 - point2;
    cout << "\nMinus res: "; res.Print();
    res = point1 * point2;
    cout << "Mult res: "; res.Print();
    res = point1 / point2;
    cout << "Divide res: "; res.Print();

    point1 += 15;
    cout << "\nPoint 1: "; point1.Print();

    res = -point2;
    cout << "\nRes: "; res.Print();
}