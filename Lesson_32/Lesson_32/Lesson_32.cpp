#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book;
void editBook(Book&, const int& number = 0);
void writeFile(string fname, Book* library, const int& size);

const int LENGTH = 50;

struct Book
{
    char name[LENGTH];
    char author[LENGTH];
    char publisher[LENGTH];
    char genre[LENGTH];
};

string toLowerCase(const char* str1)
{
    string text;
    for (size_t i = 0; i < strlen(str1); i++)
    {
        text += tolower(str1[i]);
    }
    return text;
}

// Fill/add db
void fillDB(Book*& library, int& size, const int& count)
{
    if (library == nullptr)
    {
        size = count;
        library = new Book[size];
        for (size_t i = 0; i < size; i++)
        {
            editBook(library[i], i + 1);
        }
        return;
    }
    Book* tmp = new Book[size + count];
    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = library[i];
    }
    for (size_t i = size; i < size + count; i++)
    {
        editBook(tmp[i], i - size + 1);
    }
    size += count;
    delete[] library;
    library = tmp;

}

// Edit book
void editBook(Book& book, const int& number)
{
    string text = to_string(number) + ") Book ";
    cout << "\n\t ================ " << (number == 0 ? book.name : text) << " ================\n";
    cout << "\t\t Enter name     : "; cin.getline(book.name, LENGTH);
    cout << "\t\t Enter author   : "; cin.getline(book.author, LENGTH);
    cout << "\t\t Enter publisher: "; cin.getline(book.publisher, LENGTH);
    cout << "\t\t Enter genre    : "; cin.getline(book.genre, LENGTH);
}

// Print all the books
void printBook(Book book, const int& number = 0)
{
    string text = to_string(number) + ") " + book.name;
    cout << "\n\t ================ " << (number == 0 ? book.name : text) << " ================\n";
    cout << "\t\t Author   : " << book.author << endl;
    cout << "\t\t Publisher: " << book.publisher << endl;
    cout << "\t\t Genre    : " << book.genre << endl;
}
void printLibrary(Book* library, const int& size, bool flag = false)
{
    for (size_t i = 0; i < size; i++)
    {
        if (!flag)
        {
            printBook(library[i]);
            continue;
        }
        printBook(library[i], i + 1);
    }
}

Book* readLibrary(string fname, int& size)
{
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "\t\tFile is not found!";
        return nullptr;
    }
    file.seekg(0, ios_base::end);
    size = file.tellg() / sizeof(Book);
    file.clear();
    file.seekg(0);
    Book* tmp = new Book[size];
    for (size_t i = 0; i < size; i++)
    {
        file.read((char*)&tmp[i], sizeof(Book));
    }
    return tmp;
}

void writeFile(string fname, Book* library, const int& size)
{
    ofstream file(fname);
    for (size_t i = 0; i < size; i++)
    {
        file.write((char*)&library[i], sizeof(Book));
    }
}
void writeBook(string fname, Book book)
{
    ofstream file(fname);
    file.write((char*)&book, sizeof(Book));
}

void searchByAuthor(Book* library, const int& size, string value)
{
    int j = 0;
    bool flag = false;
    for (size_t i = 0; i < size; i++)
    {
        if (toLowerCase(library[i].author) == toLowerCase(value.c_str()))
        {
            printBook(library[i], j + 1);
            j++;
            flag = true;
        }
    }
    if (!flag) cout << "\n\t\t Sorry, we couldn't find the book you are looking for!" << endl;
}
void searchByName(Book* library, const int& size, string value)
{
    int j = 0;
    bool flag = false;
    for (size_t i = 0; i < size; i++)
    {
        if (toLowerCase(library[i].name) == toLowerCase(value.c_str()))
        {
            printBook(library[i], j + 1);
            j++;
            flag = true;
        }
    }
    if (!flag) cout << "\n\t\t Sorry, we couldn't find the book you are looking for!" << endl;
}

void sortByName(Book*& library, int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (toLowerCase(library[j].name) > toLowerCase(library[j + 1].name))
            {
                Book tmp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = tmp;
            }
        }
    }
}
void sortByAuthor(Book*& library, int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (toLowerCase(library[j].author) > toLowerCase(library[j + 1].author))
            {
                Book tmp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = tmp;
            }
        }
    }
}
void sortByPublisher(Book*& library, int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (toLowerCase(library[j].publisher) > toLowerCase(library[j + 1].publisher))
            {
                Book tmp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = tmp;
            }
        }
    }
}

void deleteBook(Book*& store, int& size, string value)
{
    int new_size = size - 1;
    Book* tmp = new Book[new_size];
    int j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (toLowerCase(store[i].name) != toLowerCase(value.c_str()))
        {
            tmp[j] = store[i];
            j++;
        }
    }
    size = new_size;
    delete[] store;
    store = tmp;
}

int main()
{
    Book one{ "It", "Stephen King", "Viking", "Horror" };
    Book two{ "The Da Vinci Code", "Dan Brown", "Bantam Books", "Thriller" };
    Book three{ "Harry Potter Series", "J. K. Rowling", "Bloomsbury", "Fantasy" };
    
    /*fstream test;
    test.open(fname, ios_base::in);*/
    // write, read
    //fstream file(fname, ios_base::out | ios_base::app);
    //file.seekg(0, ios_base::end);
    //int lenFile = file.tellg(); // number of the byte which you on now
    //cout << "Size of Book: " << sizeof(Book) << endl;
    //cout << "Size of File: " << lenFile << endl;
    /*if (!file.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        file.write((char*)&one, sizeof(Book));
        file.write((char*)&two, sizeof(Book));
    }
    file.close();*/

    /*int index = 1;
    fstream file(fname, ios_base::in | ios_base::out);
    if (!file.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        file.seekg(0, ios_base::end);
        int len = file.tellg() / sizeof(Book);
        file.clear();
        file.seekg(0);
        Book* tmp = new Book[len];
        Book book;
        for (size_t i = 0; i < len; i++)
        {
            file.read((char*)&tmp[i], sizeof(Book));
        }
        printLibrary(tmp, len);


        file.clear(0);
        file.seekg(0);
        tmp[index] = three;
        for (size_t i = 0; i < len; i++)
        {
            file.write((char*)&tmp[i], sizeof(Book));
        }
        delete[] tmp;
    }*/

    const char fname[] = "library.txt";
    int size = 0;
    Book* library = readLibrary(fname, size);
    int choice;
    do
    {
        cout << "\n\t\t ::::::::::::::: DataBase library :::::::::::::::" << endl;
        cout << "\t\t\t 1 - Fill/add (somehting to) DB;\n";
        cout << "\t\t\t 2 - Print DB;\n";
        cout << "\t\t\t 3 - Search by athour in DB;\n";
        cout << "\t\t\t 4 - Search by name in DB;\n";
        cout << "\t\t\t 5 - Sort by name in DB;\n";
        cout << "\t\t\t 6 - Sort by author in DB;\n";
        cout << "\t\t\t 7 - Sort by publisher in DB;\n";
        cout << "\t\t\t 8 - Delete book from DB;\n";
        cout << "\t\t\t Select choice: "; cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int counter;
            cout << "\t\t\t\t Enter the number: "; cin >> counter;
            cin.ignore();
            fillDB(library, size, counter);
            writeFile(fname, library, size);
            break;
        }
        case 2:
        {
            if (library == nullptr)
            {
                cout << "Library is empty" << endl;
                break;
            }
            printLibrary(library, size, true);
            break;
        }
        case 3:
        {
            if (library == nullptr)
            {
                cout << "Library is empty" << endl;
                break;
            }
            searchByAuthor(library, size, "Sephen King");
        }
        case 4:
        {
            if (library == nullptr)
            {
                cout << "Library is empty" << endl;
                break;
            }
            searchByName(library, size, "Dude");
        }
        case 5:
        {
            if (library == nullptr)
            {
                cout << "Library is empty" << endl;
                break;
            }
            sortByName(library, size);
            writeFile(fname, library, size);
        }
        case 6:
        {
            if (library == nullptr)
            {
                cout << "Library is empty" << endl;
                break;
            }
            sortByAuthor(library, size);
            writeFile(fname, library, size);
        }
        case 7:
        {
            if (library == nullptr)
            {
                cout << "Library is empty" << endl;
                break;
            }
            sortByPublisher(library, size);
            writeFile(fname, library, size);
        }
        case 8:
        {
            if (library == nullptr)
            {
                cout << "Library is empty" << endl;
                break;
            }
            string value;
            bool flag = false;
            cout << "\t\t Enter name of the book you want to delete: "; cin >> value;
            for (size_t i = 0; i < size; i++)
            {
                if (toLowerCase(library[i].name) == toLowerCase(value.c_str()))
                {
                    deleteBook(library, size, value);
                    writeFile(fname, library, size);
                    flag = true;
                }
            }
            if (!flag) cout << "\t\t Sorry, we couldn't find your book!" << endl;
            break;
        }
        default:
            break;
        }
    } while (choice != 0);
}