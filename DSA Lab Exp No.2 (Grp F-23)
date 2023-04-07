/*
Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class student
{
public:
    int roll;
    string name, div, addr;
    void getdata()
    {
        cin.ignore();
        cout << "Enter the student name: ";
        getline(cin, name);
        cout << "Enter the roll number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter the division: ";
        getline(cin, div);
        cout << "Enter the address: ";
        getline(cin, addr);
    }
    void display()
    {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << roll;
        cout << "\nAddress: " << addr;
        cout << "\nDivision: " << div;
        cout << endl;
        cout << endl;
    }
};
vector<student> s;
vector<student>::iterator it;
fstream file;
void search(int keyroll)
{
    int flag = 0;
    for (it = s.begin(); it != s.end(); it++)
    {
        if (it->roll == keyroll)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "Roll Number found!!!\n";
    }
    else
    {
        cout << "Roll Number not found\n";
    }
}
void del(int keyroll)
{
    vector<student>::iterator temp;
    int flag = 0;
    for (it = s.begin(); it != s.end(); it++)
    {
        if (it->roll == keyroll)
        {
            flag = 1;
            temp = it;
        }
    }
    if (flag == 1)
    {
        s.erase(temp);
        cout << "Roll Number is deleted!!!";
    }
    else
    {
        cout << "Roll Number not found";
    }
    file.open("students.txt", ios::out | ios::trunc);
    for (int i = 0; i < s.size(); i++)
    {
        file.write((char *)&s[i], sizeof s[i]);
    }
    file.close();
}
void showdata()
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i].display();
    }
}
void insert()
{
    student stemp;
    stemp.getdata();
    s.push_back(stemp);
    file.open("students.txt", ios::out | ios::trunc);
    for (int i = 0; i < s.size(); i++)
    {
        file.write((char *)&s[i], sizeof s[i]);
    }
    file.close();
}
int main()
{
    int studentcount = 0;
    int tr;
    int ch;
    do
    {
        cout << "\n1.Add student";
        cout << "\n2.Search";
        cout << "\n3.Delete";
        cout << "\n4.Display";
        cout << "\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            // cin.ignore();
            insert();
            studentcount++;
            break;
        case 2:
            cout << "Enter the Roll no to be searched: ";
            cin >> tr;
            search(tr);
            break;
        case 3:
            cout << "Enter the Roll no to be deleted: ";
            cin >> tr;
            del(tr);
            break;
        case 4:
            showdata();
            break;
        case 5:
            exit(0);
        }
    } while (ch < 6);
    fstream fileobj;
    return 0;
}
