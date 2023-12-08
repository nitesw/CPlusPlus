#include <iostream>;
using namespace std;

int main()
{
	/*double full, coins;
	int money;

	cout << "Enter amount of money that you have: ";
	cin >> full;

	money = full;
	coins = (full - money)*100;

	cout << money << " UAH " << coins << " Cents";
	На це не звертайте увага, просто доробив те що не встиг зробити в аулиторії.*/
	
	/*
	double R, R0, R1=2, R2=4, R3=8;

	R0 = 1 / R1 + 1 / R2 + 1 / R3;
	R = 1 / R0;
	
	cout << "R1 = " << R1 << ", R2 = " << R2 << ", R3 = " << R3 << ", R0 = " << R << endl;*/

	/*
	const double pi = 3.14;
	double L, R, S;

	cout << "Enter lenght of the circle: ";
	cin >> L;

	R = L / (2 * pi);
	S = pi * (R * R);

	cout << "Area of the circle is: " << S << endl;
	Трішки не зрозуміле завдання в плані чисел, так як не було задана довжина, тому вирішив зоб користувач сам вводив значення
	*/

	/*
	double S, velocity, acceleration, time;

	cout << "Enter velocity: "; cin >> velocity;
	cout << "Enter time: "; cin >> time;
	cout << "Enter accelaration: "; cin >> acceleration;

	S = velocity * time + (acceleration * (time * time)) / 2;

	cout << "\nThe distance traveled in rectilinear motion with uniform acceleration is: " << S << endl;*/

	/*
	double meters, seconds, kilometers, time;
	int time_m, full_time;

	cout << "Enter distance length (meters): "; cin >> meters;
	cout << "Enter time (min. sec): "; cin >> seconds;
	
	cout << "Distance is: " << meters << " meters" << endl;

	time_m = seconds;
	time = (seconds - time_m) * 100;
	full_time = (time_m * 60) + time;
	kilometers = (meters/full_time) * 3.6;
	

	cout << "Time is: " << time_m << " min " << time << " sec = " << full_time << " sec" << endl;
	cout << "You ran at a speed of: " << kilometers << " km/h";*/

	int full_days, days, full_week;

	cout << "Enter the number of days: "; cin >> full_days;

	days = full_days % 7;
	full_week = full_days - days;
	full_week = full_week / 7;

	cout << full_week << (full_week == 1 ? " week and " : " weeks and ") << days << (days == 1 ? " day" : " days");

	/*Всі завдання вище*/
}