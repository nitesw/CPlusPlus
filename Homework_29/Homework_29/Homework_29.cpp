#include <iostream>
#include <cmath>
using namespace std;

struct Rectangle
{
    int x, y;
    int height, width;
};
struct Coords
{
    int x, y;
};

struct Fraction 
{
    int numerator;
    int denominator;
    void simplify() 
    {
        int gcd = 1;
        int smaller = (numerator < denominator) ? numerator : denominator;

        for (int i = 2; i <= smaller; ++i) 
        {
            if (numerator % i == 0 && denominator % i == 0) gcd = i;
        }

        numerator /= gcd;
        denominator /= gcd;
    }
};

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

double distance(Coords coord1, Coords coord2)
{
    double dist;
    dist = sqrt(pow(coord2.x - coord1.x, 2) + pow(coord2.y - coord1.y, 2));
    return dist;
}

Fraction addFractions(Fraction f1, Fraction f2) 
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result.simplify();
    return result;
}
Fraction subtractFractions(Fraction f1, Fraction f2) 
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result.simplify();
    return result;
}
Fraction multiplyFractions(Fraction f1, Fraction f2) 
{
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    result.simplify();
    return result;
}
Fraction divideFractions(Fraction f1, Fraction f2) 
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    result.simplify();
    return result;
}

int main()
{
    /*Rectangle rect{};
    fillRectangle(rect);
    printRectangle(rect);
    cout << endl;
    resize(rect, 2, 4);
    printRectangle(rect);
    cout << endl;
    move(rect, 7, 3);
    printRectangle(rect);*/

    /*Coords coord1{ 9, 1 };
    Coords coord2{ 1, 7 };
    double res_dist = distance(coord1, coord2);
    cout << "The distance between the points is: " << res_dist << endl;*/

    Fraction f1{ 2, 3 };
    Fraction f2{ 3, 4 };

    Fraction sum = addFractions(f1, f2);
    Fraction difference = subtractFractions(f1, f2);
    Fraction product = multiplyFractions(f1, f2);
    Fraction quotient = divideFractions(f1, f2);

    cout << "Sum: " << sum.numerator << "/" << sum.denominator << endl;
    cout << "Difference: " << difference.numerator << "/" << difference.denominator << endl;
    cout << "Product: " << product.numerator << "/" << product.denominator << endl;
    cout << "Quotient: " << quotient.numerator << "/" << quotient.denominator << endl;
}