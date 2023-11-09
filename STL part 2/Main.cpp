#include <iostream>
#include <map>
#include <Windows.h>
#include <fstream>
using namespace std;

typedef pair<string, string> word;

static void Input(multimap<string, string>& dict, fstream &file)
{
    string str1, str2;
    cout << "введите слово на англ -> ";
    cin >> str1;
    cout << "введите перевод -> ";
    cin >> str2;
    dict.insert(word(str1, str2));
    file << str1 << " - " << str2 << endl;
}
void Print(multimap<string, string>& dict)
{
    for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
    {
        cout << ptr->first << " -> " << ptr->second << endl;
    }
}
int Find_Sim(multimap<string, string>& dict, string str)
{
    int count = 1;
    for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
    {
        if (ptr->first == str)
        {
            count++;
        } 
    }
    return count;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    multimap<string, string> dict;
    fstream file("Dict.txt", ios::in | ios::out | ios::trunc);

    int v;
    do
    {
        cout << "1. Add word\n2. Print All\n3. Find\n4. Find similar\n 5. Exit\n -> ";
        cin >> v;
        //cin.ignore();
        string str;
        multimap<string, string> ::iterator rez;
        switch (v)
        {
        case 1:
            system("cls");
            Input(dict, file);
            break;
        case 2:
            system("cls");
            Print(dict);
            break;
        case 3:
            system("cls");
            cout << "Enter word -> ";
            cin >> str;
            rez = dict.find(str);
            if (rez == dict.end())// если не нашли !!
            {
                cout << "Нет такого слова в словаре!!!! Ищите в другом месте!!!\n";
            }
            else // Если нашли !!!
            {
                cout << rez->second << endl;
            }
            break;
        case 4:
            cout << "Enter word -> ";
            cin >> str;
            cout << str << " " << Find_Sim(dict, str) << " similar words\n";
            break;
        }
    } while (v != 4);


}

/*
* Реализовать:
* 1. работа с текстовым файлом
* 2. при поиске, так же показать количество повторов(сколько раз слово встречается в словаре).

*/