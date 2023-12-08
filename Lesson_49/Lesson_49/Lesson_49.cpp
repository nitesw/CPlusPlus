#include <iostream>
#include <Windows.h>
using namespace std;

#pragma region MainLesson
class Car
{
protected:
    string brand;
    string model;
    int year;
    int mileage;
    string country;
    int max_speed;
    float volume;
public:
    Car() :brand(""), model(""), year(0), mileage(0), country(""), max_speed(0), volume(0) {}
    Car(string b, string m, int y, int mil, string c, float v) :brand(b), model(m), year(y), mileage(mil), country(c), max_speed(0), volume(v) {}

    void setSpeed(int speed)
    {
        if (speed > 0) max_speed = speed;
    }
    virtual void Drive()const
    {
        cout << "I am a Car. I can drive with speed of " << max_speed << " km/h" << endl;
    }
    void Print()const
    {
        cout << "=============== Car ===============" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Mileage: " << mileage << endl;
        cout << "Country: " << country << endl;
        cout << "Max speed: " << max_speed << endl;
        cout << "Volume: " << volume << endl;
    }
};

class PoliceCar : public Car
{
    int soundVolume;
public:
    PoliceCar() :soundVolume(0), Car() {}
    PoliceCar(string b, string m, int y, int mil, string c, float v, int sound) :soundVolume(sound), Car(b, m, y, mil, c, v) {}

    void Drive()const override
    {
        cout << "I am a Police Car. I can drive with speed of " << max_speed << " km/h" << endl;
    }
    void Print()const
    {
        cout << "=============== Police Car ===============" << endl;
        Car::Print();
        cout << "Sound Volume: " << soundVolume << endl;
    }
    void BeepBeep()
    {
        Beep(659.26, 200);
        Beep(659.26, 200);
        Sleep(200);
        Beep(659.26, 200);
        Sleep(100);
        Beep(523.26, 200);
        Beep(659.26, 200);
        Sleep(200);
        Beep(783.98, 200);
        Sleep(400);
        Beep(391.99, 200);
    }
};
class SportCar : public Car
{
    int nitro;
public:
    SportCar() :nitro(0), Car() {}
    SportCar(string b, string m, int y, int mil, string c, float v, int nitro) :nitro(nitro), Car(b, m, y, mil, c, v) {}

    void Drive()const
    {
        cout << "I am a Sport Car. I can drive with speed of " << max_speed << " km/h" << endl;
    }
    void Print()const
    {
        cout << "=============== Sport Car ===============" << endl;
        Car::Print();
        cout << "Nitro speed: " << nitro << endl;
    }
    void NitroSpeed()
    {
        cout << "I have nitro speed of: " << nitro << " km/h" << endl;
        max_speed += nitro;
        cout << "---------> " << max_speed << endl;
    }
};

void TestDrive(Car& car)
{
    car.setSpeed(70);
    car.Drive();
}
#pragma endregion

class Shape
{
protected:
    string name;
    string type;
    int side;
public:
    Shape() :name(""), type(""), side(0) {}
    Shape(string n, int s) :name(n), type("Geometric shape"), side(s) {}

    virtual void Show()const
    {
        cout << "I am a " << name << ", " << type << ", with side of " << side << endl;
    }
    virtual void GetArea()const
    {
        cout << "Here I make some calculation about shape area" << endl;
    }
};

class MyRectangle : public Shape
{
    int otherSide;
public:
    MyRectangle() :otherSide(0), Shape() {}
    MyRectangle(string n, int s, int oS) :otherSide(oS), Shape(n, s) {}

    void Show()const override
    {
        cout << "I am a " << name << ", " << type << ", with side of " << side << endl;
    }
    void GetArea()const
    {
        cout << "Rectangle area: " << side * otherSide << endl;
    }
};
class MyCircle : public Shape
{
    float radius = side;
public:
    MyCircle() :radius(0), Shape() {}
    MyCircle(string n, int s) : Shape(n, s) {}

    void Show()const override
    {
        cout << "I am a " << name << ", " << type << ", with radius of " << side << endl;
    }
    void GetArea()const
    {
        double area = 3.14 * (double(radius) * double(radius));
        cout << "Circle area: " << area << endl;
    }
};
class MyRightTriangle : public Shape
{
    int otherSide;
public:
    MyRightTriangle() :otherSide(0), Shape() {}
    MyRightTriangle(string n, int s, int oS) :otherSide(oS), Shape(n, s) {}

    void Show()const override
    {
        cout << "I am a " << name << ", " << type << ", with side of " << side << endl;
    }
    void GetArea()const
    {
        double area = 0.5 * (double)side * (double)otherSide;
        cout << "Right triangle area: " << area << endl;
    }
};
class MyTriangle : public Shape
{
    int height;
public:
    MyTriangle() :height(0), Shape() {}
    MyTriangle(string n, int s, int h) :height(h), Shape(n, s) {}

    void Show()const override
    {
        cout << "I am a " << name << ", " << type << ", with side of " << side << endl;
    }
    void GetArea()const 
    {
        double area = 0.5 * side * height;
        cout << "Triangle area: " << area << endl;
    }
};
class MyTrapeze : public Shape
{
    int otherSide;
    int height;
public:
    MyTrapeze() :otherSide(0), height(0), Shape() {}
    MyTrapeze(string n, int s, int oS, int h) :otherSide(oS), height(h), Shape(n, s) {}

    void Show()const override
    {
        cout << "I am a " << name << ", " << type << ", with side of " << side << endl;
    }
    void GetArea()const
    {
        double area = 0.5 * (side + otherSide) * height;
        cout << "Right triangle area: " << area << endl;
    }
};

void TestShape(Shape& shape)
{
    shape.Show();
    shape.GetArea();
}

int main()
{
    /*Car simpleCar("Fiat", "Double", 2000, 300000, "Italy", 2.0);
    simpleCar.setSpeed(185);
    simpleCar.Drive();
    simpleCar.Print();
    cout << endl;

    PoliceCar policeCar("Toyota", "Camry", 2015, 30000, "Japan", 3.5, 500);
    policeCar.setSpeed(215);
    policeCar.Drive();
    policeCar.Print();
    policeCar.BeepBeep();
    cout << endl;

    SportCar sportCar("Lamborghini", "Urus", 2023, 20, "Italy", 4.0, 50);
    sportCar.setSpeed(250);

    TestDrive(simpleCar);
    TestDrive(policeCar);
    TestDrive(sportCar);*/

    Shape shape("Simple Shape", 10);
    MyRectangle rectangle("Rectangle", 4, 5);
    MyCircle circle("Circle", 5);
    MyRightTriangle rightTriangle("Right Triangle", 2, 6);
    MyTriangle triangle("Triangle", 5, 3);
    MyTrapeze trapeze("Trapeze", 4, 2, 8);

    TestShape(shape);
    TestShape(rectangle);
    TestShape(circle);
    TestShape(rightTriangle);
    TestShape(triangle);
    TestShape(trapeze);
}