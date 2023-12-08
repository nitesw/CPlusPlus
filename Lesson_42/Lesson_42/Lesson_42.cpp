#include "Book.h"
#include "Library.h"

Library TestLibrary(Library& lib)
{
    Library temp; // default ctor
    temp.AddNewBook(Book("C++ for Begginers", 2000, "Sriven Prata", 1500, Genre::Programming));
    return temp;
}

int main()
{
#pragma region Library
    Book book1("C++ for Begginers", 2000, "Sriven Prata", 1500, Genre::Programming);
    Book book2("Harry Potter", 1997, "J.K.Rowling", 800, Genre::Fantasy);
    Book book3("Sherlock Holmes", 1887, "Arthur Conan Doyle", 2000, Genre::Novel);
    Book book4("Java for kids", 2015, "Morgan Nick", 408, Programming);
    Book book5("Mowgli", 1893, "Pantera", 500, Genre::Fantasy);
    Book book6("Financier", 1911, "Dreiser Theodore", 377, Genre::Science);

    //book6.ShowInfo();

    Library lib("Library for kids", "Soborna Str. 16");
    lib.AddNewBook(book1);
    lib.AddNewBook(book2);
    lib.AddNewBook(book3);
    lib.AddNewBook(book4);
    lib.AddNewBook(book5);
    lib.AddNewBook(Book("Financier", 1911, "Dreiser Theodore", 377, Genre::Science));
    //lib.Show();
#pragma endregion

    cout << "\n\n------------------------------Test copy------------------------------" << endl;
    //{
        Library test(lib);
        //test.Show();
    //}
    cout << "\n\n------------------------------Lib------------------------------" << endl;
    //lib.Show();
    Library temp = TestLibrary(lib);
    temp = lib = test;
    temp = lib;
    temp.Show();
    //lib.Show();
    //test.Show();


}