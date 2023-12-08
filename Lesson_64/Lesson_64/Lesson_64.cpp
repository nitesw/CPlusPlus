#include <iostream>
using namespace std;

class User
{
public:
    virtual void Info() = 0;
};

class Admin : public User
{
public:
    void Info()override
    {
        cout << "I'm an admin" << endl;
    }
};
class Manager : public User
{
public:
    void Info()override
    {
        cout << "I'm a manager" << endl;
    }
};
class Guest : public User
{
public:
    void Info()override
    {
        cout << "I'm a guest" << endl;
    }
};

enum UserTypes { ADMIN, MANAGER, GUEST };
UserTypes ReadUserTypeFromFile()
{
    return UserTypes::ADMIN;
}

class UserFactory
{
public:
    User* CreateUser(UserTypes code)
    {
        switch (code)
        {
        case ADMIN: new Admin(); break;
        case MANAGER: new Manager(); break;
        case GUEST: new Guest(); break;
        }
    }
};

int main()
{
    UserFactory factoryMethod;
    UserTypes code = ReadUserTypeFromFile();

    User* user = factoryMethod.CreateUser(code);
    user->Info();
    
    delete user;
}