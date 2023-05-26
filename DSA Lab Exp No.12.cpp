/*
Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
must be unique
Standard Operations: Insert(key, value), Find(key), Delete(key).
*/

#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int chain;
    string word;
    string mean;
} obj[10];

int hash_func(string wd)
{
    int key = 0;
    for (int i = 0; i < wd.size(); i++)
    {
        key += wd[i];
    }
    return key % 10;
}

void collision(int key, string wd, string mn)
{
    int i = 1;
    while (((key + i) % 10) != key)
    {
        if (obj[(key + i) % 10].word == "-")
        {
            obj[(key + i) % 10].word = wd;
            obj[(key + i) % 10].mean = mn;
            obj[(key + i - 1) % 10].chain = (key + i) % 10;
            break;
        }
        else
        {
            i++;
        }
    }
}

void hash_ini()
{
    for (int i = 0; i < 10; i++)
    {
        obj[i].word = "-";
        obj[i].mean = "-";
        obj[i].chain = -1;
    }
}

void hash_table()
{
    string wd, mn;
    cout << "Enter a word: ";
    cin >> wd;
    cout << "Enter meaning for word: ";
    cin >> mn;
    int hash_key = hash_func(wd);
    if (obj[hash_key].word == "-")
    {
        obj[hash_key].word = wd;
        obj[hash_key].mean = mn;
    }
    else
    {
        collision(hash_key, wd, mn);
    }
}

void display()
{
    cout << "index"
         << "\t\t"
         << "word"
         << "\t\t\t"
         << "meaning"
         << "\t\t\t"
         << "chain" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t\t" << obj[i].word << "\t\t" << obj[i].mean << "\t\t\t" << obj[i].chain << endl;
    }
}

void del_key(string word)
{
    int key = hash_func(word);
    if (obj[key].word == word)
    {
        obj[key].word = "-";
        obj[key].mean = "-";
        obj[key].chain = -1;
    }
    else if (obj[key].chain != -1)
    {
        int target = obj[key].chain;
        int prev = key;
        while (true)
        {
            if (obj[target].word == word)
            {
                obj[prev].chain = obj[target].chain;
                obj[target].word = "-";
                obj[target].mean = "-";
                obj[target].chain = -1;
                cout << "Deletion successful" << endl;
                break;
            }
            prev = target;
            target = obj[target].chain;
            if (target == key)
            {
                cout << "Word not found" << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Word not found" << endl;
    }
}

void find(string word)
{
    int key = hash_func(word);
    if (obj[key].word == word)
    {
        cout << "Found the word" << endl;
        cout << obj[key].word << "-->" << obj[key].mean << endl;
    }
    else if (obj[key].chain != -1)
    {
        int target = obj[key].chain;
        while (true)
        {
            if (obj[target].word == word)
            {
                cout << "Found the word" << endl;
                cout << obj[target].word << "-->" << obj[target].mean << endl;
                break;
            }
            target = obj[target].chain;
            if (target == key)
            {
                cout << "Not found" << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Not found" << endl;
    }
}

int main()
{
    int ch;
    string del_wd;
    string src;
    hash_ini();
    do
    {
        cout << "\n******Dictionary Using Hashing (Chaining)******" << endl;
        cout << "1. Insert data in hash table " << endl;
        cout << "2. Display Hash Table " << endl;
        cout << "3. Delete word from hash table " << endl;
        cout << "4. Find word in a hash table " << endl;
        cout << "5. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter no of entries you want to make: ";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                hash_table();
            }
            break;
        case 2:
            display();
            break;
        case 3:
            cout << "Enter the word you want to delete: ";
            cin >> del_wd;
            del_key(del_wd);
            break;
        case 4:
            cout << "Enter the word you want to search: ";
            cin >> src;
            find(src);
            break;
        }
    } while (ch < 5);
    cout << "Done Successfully" << endl;
    return 0;
}
