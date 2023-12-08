#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string name;
    string author;
    string publisher;
    string genre;

    void print()
    {
        cout << "\n=============== " << name << " ===============\n";
        cout << "\tAuthor   : " << author << endl;
        cout << "\tPublisher: " << publisher << endl;
        cout << "\tGenre    : " << genre << endl;
        cout << endl;
    }
};

void printBooks(Book* library, const int& size)
{
    for (size_t i = 0; i < size; i++)
    {
        library[i].print();
    }
}
int findAuthor(Book* library, const int& size, string author, int index = 0)
{
    for (size_t i = index; i < size; i++)
    {
        if (library[i].author == author) return i;
    }
    return -1;
}
string toLowerCase(string text)
{
    for (size_t i = 0; i < text.size(); i++)
    {
        text[i] = tolower(text[i]);
    }
    return text;
}
void sortByName(Book* library, const int& size)
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

void sortByAuthor(Book* library, const int& size)
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
void sortByPublisher(Book* library, const int& size)
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

void editBook(Book* library, const int& size, int index)
{
    cout << "\n\nYou editing a book named " << library[index].name << endl;
    cout << "Enter the new name: "; cin >> library[index].name;
    cout << "Enter the new author: "; cin >> library[index].author;
    cout << "Enter the new publisher: "; cin >> library[index].publisher;
    cout << "Enter the new genre: "; cin >> library[index].genre;
}

void addBook(Book*& library, int& size)
{
    Book newBook;
    cin.ignore();
    cout << "Enter book name: ";
    getline(cin, newBook.name);
    cout << "Enter author name: ";
    getline(cin, newBook.author);
    cout << "Enter publisher name: ";
    getline(cin, newBook.publisher);
    cout << "Enter genre: ";
    getline(cin, newBook.genre);

    Book* new_library = new Book[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        new_library[i] = library[i];
    }
    new_library[size] = newBook;
    delete[] library;
    library = new_library;
    size++;
}

void deleteBook(Book*& library, int& size)
{
    string choice;
    cout << "Enter the name of the book to delete: ";
    getline(cin, choice);

    bool bookFound = false;
    for (int i = 0; i < size; i++)
    {
        if (library[i].name == choice)
        {
            bookFound = true;
            break;
        }
    }
    if (!bookFound)
    {
        cout << "Book not found in the library." << endl;
        return;
    }

    Book* new_library = new Book[size - 1];
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (library[i].name == choice)
        {
            continue;
        }

        new_library[j] = library[i];
        j++;
    }

    delete[] library;
    library = new_library;
    size--;
}

int main()
{
    int size = 10;
    Book* library = new Book[size]
    {
        {
            "It",
            "Stephen King",
            "Viking",
            "Horror"
        },
        {
            "The Da Vinci Code",
            "Dan Brown",
            "Bantam Books",
            "Thriller"
        },
        {
            "The Alchemist",
            "Paulo Coelho",
            "HarperTorch",
            "Adventure"
        },
        {
            "The Witcher Series",
            "Andrzej Sapkowski",
            "Hachette",
            "Fantasy"
        },
        {
            "Harry Potter Series",
            "J. K. Rowling",
            "Bloomsbury",
            "Fantasy"
        },
        {
            "The Shining",
            "Stephen King",
            "Doubleday",
            "Horror"
        },
        {
            "Graveyard Shift",
            "Stephen King",
            "Doubleday",
            "Horror"
        },
        {
            "The Boogeyman",
            "Stephen King",
            "Doubleday",
            "Horror"
        },
        {
            "The Green Mile",
            "Stephen King",
            "Signet Books",
            "Horror"
        },
        {
            "Carrie ",
            "Stephen King",
            "Doubleday",
            "Horror"
        }
    };

    printBooks(library, size);

    string author = "Dan Brown";
    /*cout << "Enter the author to search for: ";
    getline(cin, author);*/
    int index = findAuthor(library, size, author);
    while (index != -1)
    {
        cout << "Found " << author << " ===> on position " << index << endl;
        library[index].print();
        index = findAuthor(library, size, author, index + 1);
    }

    cout << "\n\nSort by name:\n\n";
    sortByName(library, size);
    printBooks(library, size);

    int index2 = 0;
    editBook(library, size, index2);
    printBooks(library, size);

    cout << "\n\nSort by author:\n\n";
    sortByAuthor(library, size);
    printBooks(library, size);

    cout << "\n\nSort by publisher:\n\n";
    sortByPublisher(library, size);
    printBooks(library, size);

    cout << "\n\nAdd a book:\n\n";
    addBook(library, size);
    printBooks(library, size);

    cout << "\n\nDelete a book:\n\n";
    deleteBook(library, size);
    printBooks(library, size);
}