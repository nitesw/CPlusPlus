#include <iostream>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

class Student
{
private:
    string name;
    string surname;
    string last_name;
    date birth_date;
    string phone;
    string city;
    string country;
    string education;
    string education_city;
    string education_country;
    int number_group;
public:
#pragma region Methods
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setLastname(string lastname)
    {
        this->last_name = lastname;
    }
    string getLastname()
    {
        return last_name;
    }
    void setSurname(string surname)
    {
        this->surname = surname;
    }
    string getSurname()
    {
        return surname;
    }
    void setBirthday(date d)
    {
        this->birth_date.day = d.day;
        this->birth_date.month = d.month;
        this->birth_date.year = d.year;
    }
    date getBirthday()
    {
        return birth_date;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    string getPhone()
    {
        return phone;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    string getCity()
    {
        return city;
    }
    void setCountry(string country)
    {
        this->country = country;
    }
    string getCountry()
    {
        return country;
    }
    void setEducation(string education)
    {
        this->education = education;
    }
    string getEducation()
    {
        return education;
    }
    void setEducationCity(string education_city)
    {
        this->education_city = education_city;
    }
    string getEducationCity()
    {
        return education_city;
    }
    void setEducationCountry(string education_country)
    {
        this->education_country = education_country;
    }
    string getEducationCountry()
    {
        return education_country;
    }
    void setNumberGroup(int number_group)
    {
        this->number_group = number_group;
    }
    int getNumberGroup()
    {
        return number_group;
    }

    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Last name: " << last_name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Birthdate: " << birth_date.day << "/" << birth_date.month << "/" << birth_date.year << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "Education place: " << education << endl;
        cout << "Education city: " << education_city << endl;
        cout << "Education country: " << education_country << endl;
        cout << "Number of a group: " << number_group << endl;
    }
    void Init()
    {
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Last name: "; cin >> last_name;
        cout << "Enter Surname: "; cin >> surname;
        cout << "Enter Birthdate: "; cin >> birth_date.day; cin >> birth_date.month; cin >> birth_date.year;
        cout << "Enter Phone: "; cin >> phone;
        cout << "Enter City: "; cin >> city;
        cout << "Enter Country: "; cin >> country;
        cout << "Enter Education place: "; cin >> education;
        cout << "Enter Education city: "; cin >> education_city;
        cout << "Enter Education country: "; cin >> education_country;
        cout << "Enter Number of a group: "; cin >> number_group;
    }
#pragma endregion
};

int main()
{
    Student st;
    st.Init();
    cout << endl << endl;
    st.Print();
    cout << endl << endl;
    st.setCity("Kyiv");
    st.setEducationCountry("Ukraine");
    st.Print();
}