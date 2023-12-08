#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Comp;
void editProduct(Comp&, const int& number = 0);
void writeFile(string fname, Comp* store, const int& size);

const int LENGTH = 50;
double dollars = 36.95;

struct Comp
{
    char type[LENGTH];
    char brand[LENGTH];
    char model[LENGTH];
    double price;
    int stock;
    double dollar;
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

Comp* readStore(string fname, int& size)
{
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "\t\tFile is not found!";
        return nullptr;
    }
    file.seekg(0, ios_base::end);
    size = file.tellg() / sizeof(Comp);
    file.clear();
    file.seekg(0);
    Comp* tmp = new Comp[size];
    for (size_t i = 0; i < size; i++)
    {
        file.read((char*)&tmp[i], sizeof(Comp));
    }
    return tmp;
}

void writeFile(string fname, Comp* store, const int& size)
{
    ofstream file(fname);
    for (size_t i = 0; i < size; i++)
    {
        file.write((char*)&store[i], sizeof(Comp));
    }
}
void writeBook(string fname, Comp product)
{
    ofstream file(fname);
    file.write((char*)&product, sizeof(Comp));
}

// Fill DataBase
void fillDB(Comp*& store, int& size, const int& count)
{
    if (store == nullptr)
    {
        size = count;
        store = new Comp[size];
        for (size_t i = 0; i < size; i++)
        {
            editProduct(store[i], i + 1);
        }
        return;
    }
    Comp* tmp = new Comp[size + count];
    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = store[i];
    }
    for (size_t i = size; i < size + count; i++)
    {
        editProduct(tmp[i], i - size + 1);
    }
    size += count;
    delete[] store;
    store = tmp;
}

void deleteProduct(Comp*& store, int& size, string value)
{
    int new_size = size - 1;
    Comp* tmp = new Comp[new_size];
    int j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (toLowerCase(store[i].model) != toLowerCase(value.c_str()))
        {
            tmp[j] = store[i];
            j++;
        }
    }
    size = new_size;
    delete[] store;
    store = tmp;
}

// Edit product
void editProduct(Comp& product, const int& number)
{
    string text = "Product #" + to_string(number);
    cout << "\n\t ================ " << text << " ================\n";
    cout << "\t\t Enter type             : "; cin.getline(product.type, LENGTH);
    cout << "\t\t Enter brand            : "; cin.getline(product.brand, LENGTH);
    cout << "\t\t Enter model            : "; cin.getline(product.model, LENGTH);
    do
    {
        cout << "\t\t Enter price (in USD)   : "; cin >> product.price;
    } while (product.price < 1);
    do
    {
        cout << "\t\t Enter how many in stock: "; cin >> product.stock;
    } while (product.stock < 1);
    cin.ignore();
}

// Print all the goods
void printProduct(Comp product, const int& number = 0)
{
    double priceUAH = product.price * product.dollar;
    string text = "Product #" + to_string(number);
    cout << "\n\t ================ " << text << " ================\n";
    cout << "\t\t " << product.type << ": ";
    cout << product.brand << " ";
    cout << product.model << ". ";
    cout << "Price: " << priceUAH << " UAH. ";
    cout << "In stock: " << product.stock << endl;
}
void printStore(Comp* product, const int& size, bool flag = false)
{
    for (size_t i = 0; i < size; i++)
    {
        if (!flag)
        {
            printProduct(product[i]);
            continue;
        }
        printProduct(product[i], i + 1);
    }
}

void sortByType(Comp*& store, int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (toLowerCase(store[j].type) > toLowerCase(store[j + 1].type))
            {
                Comp tmp = store[j];
                store[j] = store[j + 1];
                store[j + 1] = tmp;
            }
        }
    }
}
void sortByPrice(Comp*& store, int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (store[j].price > store[j + 1].price)
            {
                Comp tmp = store[j];
                store[j] = store[j + 1];
                store[j + 1] = tmp;
            }
        }
    }
}

void searchByType(Comp* store, int size, string value)
{
    int j = 0;
    bool flag = false;
    for (size_t i = 0; i < size; i++)
    {
        if (toLowerCase(store[i].type) == toLowerCase(value.c_str()))
        {
            printProduct(store[i], j + 1);
            j++;
            flag = true;
        }
    }
    if (!flag) cout << "\t\t Sorry, we couldn't find the type you are looking for!" << endl;
}
void searchByBrand(Comp* store, int size, string value)
{
    int j = 0;
    bool flag = false;
    for (size_t i = 0; i < size; i++)
    {
        if (toLowerCase(store[i].brand) == toLowerCase(value.c_str()))
        {
            printProduct(store[i], j + 1);
            j++;
            flag = true;
        }
    }
    if (!flag) cout << "\t\t Sorry, we couldn't find the brand you are looking for!" << endl;
}

void printersByPrice(Comp* store, int size, int value)
{
    int j = 0;
    bool flag = false;
    for (size_t i = 0; i < size; i++)
    {
        if (store[i].price < value && toLowerCase(store[i].type) == toLowerCase("printer"))
        {
            printProduct(store[i], j + 1);
            j++;
            flag = true;
        }
    }
    if (!flag) cout << "\t\t Sorry, we couldn't find printers at a price that does not exceed your cost!" << endl;
}
void goodsLess(Comp* store, int size)
{
    int j = 0;
    bool flag = false;
    for (size_t i = 0; i < size; i++)
    {
        if (store[i].stock < 5)
        {
            printProduct(store[i], j + 1);
            j++;
            flag = true;
        }
    }
    if (!flag) cout << "\t\t Sorry, we couldn't find goods that are less than 5 in stock!" << endl;
}

void dollar(Comp& price)
{

}
void convert(Comp*& store, int size)
{
    
}

void tabularReport(Comp* store, int size)
{
    bool* printed = new bool[size];
    for (int i = 0; i < size; i++) 
    {
        printed[i] = false;
    }

    for (int j = 0; j < size; j++) 
    {
        if (printed[j]) 
        {
            continue;
        }
        cout << "\n\t ---------------- " << store[j].type << "s ----------------\n";
        int index = 0;
        for (int i = 0; i < size; i++) 
        {
            if (toLowerCase(store[j].type) == toLowerCase(store[i].type)) 
            {
                printed[i] = true;
                index++;
                printProduct(store[i], index);
            }
        }
        cout << endl << endl;
    }

    delete[] printed;
}

int main()
{
    const char fname[] = "store.txt";
    int size = 0;
    Comp* store = readStore(fname, size);
    int choice;

    do
    {
        cout << "\n\t\t ::::::::::::::: Store DataBase :::::::::::::::" << endl;
        cout << "\t\t\t 1 - Fill/add (somehting to) DB;\n";
        cout << "\t\t\t 2 - Print DB;\n";
        cout << "\t\t\t 3 - Delete (something) from DB;\n";
        cout << "\t\t\t 4 - Sort DB by;\n";
        cout << "\t\t\t 5 - Search in DB by;\n";
        cout << "\t\t\t 6 - Choose in DB;\n";
        cout << "\t\t\t 7 - Correct the price of the dollar (current " << dollars <<");\n";
        cout << "\t\t\t 8 - Tabular report;\n";
        cout << "\t\t\t 9 - Clear console;\n";
        cout << "\t\t\t 0 - Exit;\n";
        cout << "\n\t\t\t Select choice: "; cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int counter;
            cout << "\t\t\t\t Enter the number: "; cin >> counter;
            cin.ignore();
            fillDB(store, size, counter);
            writeFile(fname, store, size);
            break;
        }
        case 2:
        {
            if (store == nullptr)
            {
                cout << "\t\t Store is empty" << endl;
                break;
            }
            printStore(store, size, true);
            break;
        }
        case 3:
        {
            if (store == nullptr)
            {
                cout << "\t\t Store is empty" << endl;
                break;
            }
            string value;
            bool flag = false;
            cout << "\t\t Enter the model you want to delete: "; cin >> value;
            for (size_t i = 0; i < size; i++)
            {
                if (toLowerCase(store[i].model) == toLowerCase(value.c_str()))
                {
                    deleteProduct(store, size, value);
                    writeFile(fname, store, size);
                    flag = true;
                }
            }
            if (!flag) cout << "\t\t Sorry, we couldn't find your model!" << endl;
            break;
        }
        case 4:
        {
            if (store == nullptr)
            {
                cout << "\t\t Store is empty" << endl;
                break;
            }
            int choice1;
            cout << "\n\t\t Sort by type or by price (1/2): "; cin >> choice1;
            switch (choice1)
            {
            case 1:
            {
                sortByType(store, size);
                writeFile(fname, store, size);
                break;
            }
            case 2:
            {
                sortByPrice(store, size);
                writeFile(fname, store, size);
                break;
            }
            default:
                break;
            }
            break;
        }
        case 5:
        {
            if (store == nullptr)
            {
                cout << "\t\t Store is empty" << endl;
                break;
            }
            string value;
            int choice1;
            cout << "\n\t\t Search by type or by brand (1/2): "; cin >> choice1;
            switch (choice1)
            {
            case 1:
            {
                cout << "\t\t Enter the type you want to search for: "; cin >> value;
                searchByType(store, size, value);
                break;
            }
            case 2:
            {
                cout << "\t\t Enter the brand you want to search for: "; cin >> value;
                searchByBrand(store, size, value);
                break;
            }
            default:
                break;
            }
            break;
        }
        case 6:
        {
            if (store == nullptr)
            {
                cout << "\t\t Store is empty" << endl;
                break;
            }
            int choice1;
            int value;
            cout << "\n\t\t Choose from: "; 
            cout << "\n\t\t\t 1 - Print all printers at a price that does not exceed your cost"; 
            cout << "\n\t\t\t 2 - Print all goods which left 5 or less in the storage"; 
            cout << "\n\n\t\t Select choice: "; 
            cin >> choice1;
            switch (choice1)
            {
            case 1:
            {
                cout << "\t\t Enter the price (in USD): "; cin >> value;
                printersByPrice(store, size, value);
                break;
            }
            case 2:
            {
                goodsLess(store, size);
                break;
            }
            default:
                break;
            }
            break;
        }
        case 7:
        {
            cout << "Enter the new price: "; cin >> dollars;
            break;
        }
        case 8:
        {
            if (store == nullptr)
            {
                cout << "\t\t Store is empty" << endl;
                break;
            }
            tabularReport(store, size);
            break;
        }
        case 9:
        {
            system("cls");
            break;
        }
        default:
            break;
        }
    } while (choice != 0);
}