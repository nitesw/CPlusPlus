#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;

void fillArray(int arr[], int length, int min = 1, int max = 10);
void fillArray(double arr[], int length, int min = 1, int max = 10);
void fillArray(char arr[], int length, char symbol);
void fillArray(string arr[], int length, string str);

void printArray(string arr[], int length, string help = "\nPrinted Array: ");
void printArray(char arr[], int length, string help = "\nPrinted Array: ");
void printArray(int arr[], int length, string help = "\nPrinted Array: ");
void printArray(double arr[], int length, string help = "\nPrinted Array: ");

void reverseArray(int arr[], int length, string reverse = "\nReversed Array: ");
void reverseArray(double arr[], int length, string reverse = "\nReversed Array: ");

void filteredArray(int arr[], int length, string filtered = "\nFiltered Array: ");
void filteredArray(double arr[], int length, string filtered = "\nFiltered Array: ");

int searchNum(int arr[], int length, int num);

int minNum(int arr[], int length);
double minNum(double arr[], int length);

int maxNum(int arr[], int length);
double maxNum(double arr[], int length);

int minNumPos(int arr[], int length);
int minNumPos(double arr[], int length);

int maxNumPos(int arr[], int length);
int maxNumPos(double arr[], int length);