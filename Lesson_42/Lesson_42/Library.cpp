#include "Library.h"

Library::Library()
{
	name = "no name";
	address = "no address";
	books = nullptr;
	countBooks = 0;
}

Library::Library(string name, string address)
{
	this->name = name;
	this->address = address;
	books = nullptr;
	countBooks = 0;
}

Library::Library(const Library& other)
{
	this->name = other.name;
	this->address = other.address;
	this->countBooks = other.countBooks;
	this->books = new Book[other.countBooks];
	for (size_t i = 0; i < other.countBooks; i++)
	{
		books[i] = other.books[i];
	}
	cout << "Ctor copy" << endl;
}

void Library::Show() const
{
	cout << "Library name: " << name << endl;
	cout << "Library address: " << address << endl << endl;
	for (size_t i = 0; i < countBooks; i++)
	{
		books[i].ShowInfo();
		cout << endl;
	}
}

void Library::AddNewBook(Book book)
{
	Book* newBooks = new Book[countBooks + 1];
	for (size_t i = 0; i < countBooks; i++)
	{
		newBooks[i] = books[i];
	}
	newBooks[countBooks] = book;
	if (books != nullptr) delete[] books;
	books = newBooks;
	countBooks++;
}

Library& Library::operator=(const Library& other)
{
	this->name = other.name;
	this->address = other.address;
	this->countBooks = other.countBooks;
	if (books != nullptr) delete[] books;
	this->books = new Book[other.countBooks];
	for (size_t i = 0; i < other.countBooks; i++)
	{
		books[i] = other.books[i];
	}
	cout << "Operator =" << endl;
	return *this;
}

Library::Library(Library&& other)
{
	name = other.name;
	address = other.address;
	countBooks = other.countBooks;
	books = other.books;
	other.books = nullptr;
	cout << "Move ctor" << endl;
}
