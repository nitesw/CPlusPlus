#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
using namespace std;

class Dictionary
{
    string name;
    map<string, list<string>> words;
public:
    Dictionary() :name("no name") {}
    Dictionary(string name) :name(name) {}

    void PrintDictionary()
    {
        cout << "\n\t\t\tDictionary name: " << name << endl;
        for (auto pair : words)
        {
            cout << "\t\t\t\t" << pair.first << " - ";
            for (string t : pair.second)
            {
                cout << t << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void AddNewWord(string word, list<string> translation)
    {
        words.insert(make_pair(word, list<string>(translation)));
    }
    bool IsExists(string word)
    {
        return words.find(word) != words.end();
    }
    void AddTranslation(string word, string translation)
    {
        words[word].push_back(translation);
    }
    void SearchForTranslation()
    {
        string word;
        cout << "\n\tEnter word to see translation: "; getline(cin, word);

        if (!IsExists(word))
            cout << "\tWord not found!" << endl << endl;
        else
        {
            cout << "\t\tMeans: ";
            for (string elem : words[word])
            {
                cout << elem << " ";
            }
            cout << endl << endl;
        }
    }
    void AddTranslation()
    {
        string input = "";
        cout << "\n\tEnter the word to add translations: "; getline(cin, input);

        if (!IsExists(input))
            cout << "\tWord not found!" << endl << endl;
        else
        {
            string translate = "";
            do
            {
                cout << "\t\tEnter translation (Press enter to exit): ";
                getline(cin, translate);
                if (!translate.empty())
                    AddTranslation(input, translate);
            } while (!translate.empty());
            system("cls");
        }
    }
    void DeleteWord(string word)
    {
        if (!IsExists(word))
            cout << "\tWord not found!" << endl << endl;
        else
        {
            words[word].clear();
            words.erase(word);
            system("cls");
        }
    }

    friend ofstream& operator << (ofstream& out, Dictionary& dic);
    friend ifstream& operator >> (ifstream& in, Dictionary& dic);

    void SaveToFile()
    {
        ofstream out_file("dictionary.txt", ios_base::out);
        out_file << *this;
        out_file.close();
    }
    void Load()
    {
        ifstream in("dictionary.txt", ios_base::in);
        in >> *this;
        in.close();
    }
};

ofstream& operator << (ofstream& out, Dictionary& dic)
{
    out << dic.name << endl;
    for (auto pair : dic.words)
    {
        out << pair.first << endl;
        for (string t : pair.second)
        {
            out << t << endl;
        }
        out << "#" << endl;
    }
    return out;
}
ifstream& operator >> (ifstream& in, Dictionary& dic)
{
    getline(in, dic.name); //in >> dic.name;
    while (!in.eof())
    {
        string word;
        getline(in, word); //in >> word;
        if (word.empty()) break;
        list<string> list;
        string translation = "#";
        do
        {
            getline(in, translation); //in >> translation;
            if(translation != "#")
                list.push_back(translation);
        } while (translation != "#");
        dic.words.insert(make_pair(word, list));
    }
    return in;
}


int main()
{
    /*map<string, list<string>> dic;

    string word = "run";
    list<string> meanings = list<string>({ "bigtu", "zapochatkuvatu", "pochatu" });
    dic.insert(make_pair(word, meanings));

    dic.insert(make_pair("mind", list<string>({ "dumka", "dusha", "svidomist'", "sens" })));
    dic.insert(make_pair("bad", list<string>({ "luho", "poganui", "borg", "deficit" })));
    dic.insert(make_pair("test", list<string>({ "mean1", "mean2", "mean3" })));

    for (string s : dic["mind"])
    {
        cout << s << " ";
    }

    //////////////////// add translate
    string input = "";
    cout << "\nEnter word to add translatins: "; getline(cin, input);

    if (dic.find(input) == dic.end())
        cout << "Word not found!\n";
    else
    {
        string translate = "";
        do
        {
            cout << "Enter translate: ";
            getline(cin, translate);
            dic[input].push_back(translate);
        } while (!translate.empty());
    }
    for (string s : dic[input])
    {
        cout << s << " ";
    }

    ////////////////////// check translate
    cout << "\nEnter word to translate: "; getline(cin, input);

    if (dic.find(input) == dic.end())
        cout << "Translate not found!\n";
    else
    {
        cout << "\tMeans:\n";
        for (string elem : dic[input])
            cout << elem << " ";
    }*/

    Dictionary dic("English-Ukrainian");

    int choice;
    
    do
    {
        cout << "\t\tDictionary menu" << endl;
        cout << "\t1. Print dictionary" << endl;
        cout << "\t2. Add new word to dictionary" << endl;
        cout << "\t3. Add new translation to the word" << endl;
        cout << "\t4. Find word's translations" << endl;
        cout << "\t5. Delete word from dictionary" << endl;
        cout << "\t6. Clear console" << endl;
        cout << "\t7. Save dictionary" << endl;
        cout << "\t8. Load dictionary" << endl;
        cout << "\t9. Exit" << endl;
        cout << "\tEnter youre choice: "; cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            dic.PrintDictionary();
            break;
        }
        case 2:
        {
            system("cls");
            string word;
            list<string> translations;
            int num;
            cout << "\n\tEnter the word: "; cin >> word;
            cout << "\n\tEnter number translations for the word - " << word << ": "; cin >> num;
            for (size_t i = 0; i < num; i++)
            {
                string translation;
                cout << "\tTranslation #" << i + 1 << ": ";
                cin >> translation;
                translations.push_back(translation);
            }
            dic.AddNewWord(word, translations);
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            cin.ignore();
            dic.AddTranslation();
            break;
        }
        case 4:
        {
            system("cls");
            cin.ignore();
            dic.SearchForTranslation();
            break;
        }
        case 5:
        {
            string word;
            system("cls");
            cin.ignore();
            cout << "\n\tEnter word to delete: ";  cin >> word;
            dic.DeleteWord(word);
            break;
        }
        case 6:
        {
            system("cls");
            break;
        }
        case 7:
        {
            dic.SaveToFile();
            system("cls");
            break;
        }
        case 8:
        {
            dic.Load();
            system("cls");
            break;
        }
        default:
            break;
        }
    } while (choice != 9);
}