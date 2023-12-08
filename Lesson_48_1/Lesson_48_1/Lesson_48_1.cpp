#include <iostream>
using namespace std;

class Student
{
protected:
    string name;
    string surname;
    int birthYear;
    float avarageMark;
public:
    Student() :name("no name"), surname("no surname"), birthYear(0), avarageMark(0) {}
    Student(string n, string s, int bY, float aM) :name(n), surname(s), birthYear(bY), avarageMark(aM) {}

    void IncreaseAvgMark(float num)
    {
        avarageMark += num;
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Birth Year: " << birthYear << endl;
        cout << "Avarage Mark: " << avarageMark << endl;
    }
};
class Aspirant : public Student
{
    string theme;
public:
    Aspirant() :theme("no theme"), Student() {}
    Aspirant(string theme, string n, string s, int bY, float aM) :theme(theme), Student(n, s, bY, aM) {}

    void Print()
    {
        Student::Print();
        cout << "Theme: " << theme << endl;
    }
    void WorkPrint()
    {
        cout << "I " << name << " " << surname << ", with avg mark of " << avarageMark << ", born in year of " << birthYear << ", wrote PhD thesis on the topic of " << theme << endl;
    }
};

class Passport
{
protected:
    string name;
    string surname;
    char sex;
    int birthYear;
    string docNum;
public:
    Passport() :name("no name"), surname("no surname"), sex('X'), birthYear(0), docNum("no doc num") {}
    Passport(string n, string s, char se, int bY, string dN) :name(n), surname(s), sex(se), birthYear(bY), docNum(dN) {}

    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Sex: " << sex << endl;
        cout << "Birth Year: " << birthYear << endl;
        cout << "Doc Num: " << docNum << endl;
    }
};
class ForeignPassport : public Passport
{
    string visaCategory;
    string visaCountry;
    string foreignDocNum;
public:
    ForeignPassport() :visaCategory("no visa"), visaCountry("no visa"), foreignDocNum("no foreigh doc num"), Passport() {}
    ForeignPassport(string vCat, string vCou, string fDN, string n, string s, char se, int bY, string dN) :visaCategory(vCat), visaCountry(vCou), foreignDocNum(fDN), Passport(n, s, se, bY, dN) {}

    void PrintVisa()
    {
        cout << "Visa Category: " << visaCategory << endl;
        cout << "Visa Country: " << visaCountry << endl;
    }
    void Print()
    {
        Passport::Print();
        cout << "Foreign Doc Num: " << foreignDocNum << endl;
        cout << "Visa Category: " << visaCategory << endl;
        cout << "Visa Country: " << visaCountry << endl;
    }
};

int main()
{
    /*Aspirant asp("Eco", "Mathew", "Bush", 2000, 54.2);

    asp.Print();
    cout << endl;

    asp.IncreaseAvgMark(11.8);
    asp.Print();
    cout << endl;

    asp.WorkPrint();
    cout << endl;*/

    ForeignPassport passport("National Visa", "Ukraine", "00053661243", "Micheal", "Dun", 'M', 1987, "00077318901");

    passport.PrintVisa();
    cout << endl;

    passport.Print();
}