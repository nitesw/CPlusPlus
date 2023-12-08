#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //ofstream // out file stream
    //ifstream // in file stream
    //fstream // out & in file stream

    /*ofstream file;
    string myfile = "myfile.txt";
    file.open(myfile, ios_base::app);
    if (!file.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        string text;
        int i = 0;
        while (i < 3)
        {
            cout << "Enter something: "; 
            getline(cin, text);
            i++;
            file << i << ") " << text << endl;
        }
        //cin >> text;
        file.close();
    }*/

    /*int arr[]{4,2,2,1,3,6,5,8,9,7};
    string fname = "number.txt";
    ofstream file_number(fname, ios_base::app);
    if (!file_number.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            file_number << arr[i] << endl;
        }
        file_number.close();
    }
    //remove("number.txt"); // file delete*/

    /*string fname = "number.txt";
    ifstream file(fname);
    int number[100];
    int size = 0;
    if (!file.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        //while (!file.eof())
        //{
        //    file >> number[size++];
        //    //cout << number << endl;
        //}
        while (file >> number[size++])
        {
            file >> number[size++];
            //cout << number << endl;
        }
        size--;
        file.close();
    }
    for (size_t i = 0; i < size; i++)
    {
        if(i == size - 1) cout << number[i];
        else cout << number[i] << ", ";
    }
    cout << endl;*/

    /*string fname = "myfile.txt";
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        //char s[50];
        //file >> s;
        //file.getline(s, 50);
        //cout << s << endl;

        string text;
        //getline(file, text);
        while (getline(file, text))
        {
            cout << text << endl;
        }

        file.clear();
        file.seekg(0);
        cout << "\nRead file again" << endl;
        while (getline(file, text))
        {
            cout << text << endl;
        }

        file.clear();
        file.seekg(5, ios_base::beg);
        cout << "\nOffset 5 bytes" << endl;
        //getline(file, text);
        char s;
        file.get(s);
        cout << s << endl;

        cout << endl;
        file.clear();
        file.seekg(-9, ios_base::end);
        file.get(s);
        cout << s << endl;
    }*/

    /*string fname1 = "firstf.txt";
    ofstream file1(fname1);
    if (!file1.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        string text;
        cout << "Enter something: ";
        getline(cin, text);
        file1 << text << endl;
        file1.close();
    }

    ifstream file1S(fname1);
    string fname2 = "secondf.txt";
    ofstream file2(fname2, ios_base::app);
    if (!file1S.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        string word;
        while (file1S >> word) 
        {
            if (word.size() >= 7) 
            {
                file2 << word << endl;
            }
        }
        file1S.close();
        file2.close();
    }*/

    /*string fname1 = "firstf.txt";
    ifstream file1(fname1);
    string fname2 = "thirdf.txt";
    ofstream file2(fname2, ios_base::app);
    if (!file1.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        string word;
        while (file1 >> word) 
        {
            file2 << word << " ";
        }
        file1.close();
        file2.close();
    }*/
    
    
}