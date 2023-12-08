#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point() :x(0), y(0) {}
    Point(int x, int y) :x(x), y(y) {}

    void Print()const
    {
        cout << "X: " << x << " Y: " << y << endl;
    }

    void operator ++(int)
    {
        this->x++;
        this->y++;
    }
    void operator --(int)
    {
        this->x--;
        this->y--;
    }
    Point& operator!()
    {
        x = -x;
        y = -y;
        return *this;
    }
    int operator >(const Point& other)
    {
        return (this->x + this->y) > (other.x + other.y);
    }
    int operator <(const Point& other)
    {
        return (this->x + this->y) < (other.x + other.y);
    }
};

class Vector
{
private:
    Point* points;
    int numberOfPoints;
public:
    Vector()
    {
        points = nullptr;
        numberOfPoints = 0;
    }
    Vector(const Vector& other)
    {
        this->numberOfPoints = other.numberOfPoints;
        this->points = new Point[other.numberOfPoints];
        for (size_t i = 0; i < other.numberOfPoints; i++)
        {
            points[i] = other.points[i];
        }
        cout << "Copy ctor" << endl;
    }
    Vector(Vector&& other)
    {
        numberOfPoints = other.numberOfPoints;
        points = other.points;
        other.points = nullptr;
        cout << "Move ctor" << endl;
    }
    Vector& operator =(const Vector& other)
    {
        this->numberOfPoints = other.numberOfPoints;
        if (points != nullptr) delete[] points;
        this->points = new Point[other.numberOfPoints];
        for (size_t i = 0; i < other.numberOfPoints; i++)
        {
            points[i] = other.points[i];
        }
        cout << "Operator =" << endl;
        return *this;
    }
    void Add(Point point)
    {
        Point* newPoints = new Point[numberOfPoints + 1];
        for (size_t i = 0; i < numberOfPoints; i++)
        {
            newPoints[i] = points[i];
        }
        newPoints[numberOfPoints] = point;
        if (points != nullptr) delete[] points;
        points = newPoints;
        numberOfPoints++;
    }
    void Print()
    {
        for (size_t i = 0; i < numberOfPoints; i++)
        {
            cout << "Point #" << i + 1 << endl;
            points[i].Print();
        }
    }
    ~Vector()
    {
        if (points != nullptr) delete[] points;
    }
};

Vector testVector(Vector& vect)
{
    Vector temp;
    temp.Add(Point(10, 5));
    return temp;
}

int main()
{
    Point pt1(3, 4);
    Point pt2(2, 3);

    pt1.Print();
    pt2.Print();
    cout << endl;

    pt1++;
    pt1.Print();
    cout << endl;
    pt2--;
    pt2.Print();
    cout << endl;

    cout << (pt1 > pt2) << endl << endl;

    !pt1;
    !pt2;
    pt1.Print();
    pt2.Print();
    cout << endl;
    cout << (pt1 < pt2) << endl << endl;

    Vector pts1;
    pts1.Add(pt1);
    pts1.Add(pt2);
    pts1.Print();
    cout << endl;

    Vector pts2(pts1);
    pts2 = pts1;
    pts2.Print();
    cout << endl;
    pts1.Print();
    cout << endl;
    
    Vector test = testVector(pts1);
    test.Print();
    cout << endl;
    //pts1.Print();
}