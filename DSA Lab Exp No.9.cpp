/*
Company maintains employee information as employee ID, name, designation and salary.
Allow user to add, delete information of employee. Display information of particular
employee. If employee does not exist an appropriate message is displayed. If it is, then
the system displays the employee details. Use index sequential file to maintain the data.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std; 
class Employee{
    private:
        int code;
        char name[20];
        float salary;
    public:
        void read();
        void display();
        int getEmpCode()            { return code;}
        int getSalary()             { return salary;}
        double updateSalary(float s)  { return s;}
};
void Employee::read(){
    cout<<"Enter employee code: ";
    cin>>code;
    cout<<"Enter name: ";
    cin.ignore();
    cin.getline(name,20);
    cout<<"Enter salary: ";
    cin>>salary;
} 
void Employee::display()
{
    cout<<code<<" "<<name<<"\t"<<salary<<endl;
}
fstream file;
void deleteExistingFile(){
    remove("EMPLOYEE.txt");
}
void appendToFile(){
    Employee x;
    x.read();
    file.open("EMPLOYEE.txt",ios::binary|ios::app);
    if(!file){
        cout<<"ERROR IN CREATING FILE\n";
        return;
    }
    file.write((char*)&x,sizeof(x));
    file.close();
    cout<<"Record added sucessfully.\n";
}
void displayAll(){
    Employee x;
    file.open("EMPLOYEE.txt",ios::binary|ios::in);
    if(!file){
        cout<<"ERROR IN OPENING FILE \n";
        return;
    }
    while(file){
    if(file.read((char*)&x,sizeof(x)))
        x.display();
    }
  file.close();
} 
void searchForRecord(){
    Employee x;
    int c;
    int isFound=0;
    cout<<"Enter employee code: ";
    cin>>c;
    file.open("EMPLOYEE.txt",ios::binary|ios::in);
    if(!file){
        cout<<"ERROR IN OPENING FILE \n";
        return;
    }
    while(file){
        if(file.read((char*)&x,sizeof(x))){
            if(x.getEmpCode()==c){
                cout<<"RECORD FOUND \n";
                x.display();
                isFound=1;
                break;
            }
        }
    }
    if(isFound==0){
        cout<<"Record not found!!!\n";
    }
    file.close();
}
double increaseSalary(){
    Employee x;
    int c;
    int isFound=0;
    float sal;
    cout<<"Enter employee code: \n";
    cin>>c;
    file.open("EMPLOYEE.txt",ios::binary|ios::in);
    if(!file){
        cout<<"ERROR IN OPENING FILE !!!\n";
    }
    while(file){
        if(file.read((char*)&x,sizeof(x))){
            if(x.getEmpCode()==c){
                cout<<"Salary hike? ";
                cin>>sal;
                return x.updateSalary(x.getSalary()+sal);
                isFound=1;
                break;
            }
        }
    }
    if(isFound==0){
        cout<<"Record not found!!!\n";
    }
    file.close();
    cout<<"Salary updated successfully."<<endl;
}
void insertRecord(){
    Employee x;
    Employee newEmp;
    newEmp.read();
    fstream fin;
    file.open("EMPLOYEE.txt",ios::binary|ios::in);
    fin.open("TEMP.txt",ios::binary|ios::out);
    if(!file){
        cout<<"Error in opening EMPLOYEE.txt file!!!\n";
        return;
    }
    if(!fin){
        cout<<"Error in opening TEMP.txt file!!!\n";
        return;
    }
    while(file){
        if(file.read((char*)&x,sizeof(x))){
            if(x.getEmpCode()>newEmp.getEmpCode()){
                fin.write((char*)&newEmp, sizeof(newEmp));
            }
            fin.write((char*)&x, sizeof(x));
        }
    }
    fin.close();
    file.close();
    rename("TEMP.txt","EMPLOYEE.txt");
    remove("TEMP.txt");
    cout<<"Record inserted successfully."<<endl;
}
int main()
{
     char ch;
     deleteExistingFile();
     do{
     int n;
     cout<<"ENTER CHOICE:- \n"<<"1.ADD AN EMPLOYEE \n"<<"2.DISPLAY \n"<<"3.SEARCH \n"<<"4.INCREASE SALARY \n"<<"5.INSERT RECORD \n";
     cout<<"Make a choice: ";
     cin>>n;
     switch(n){
        case 1:
            appendToFile();
            break;
        case 2 :
            displayAll();
            break;
        case 3:
            searchForRecord();
            break;
        case 4:
            cout<<"Increased salary: "<<increaseSalary();
            break;
        case 5:
            insertRecord();
            break;
        default :
            cout<<"Invalid Choice\n";
        }
        cout<<"Do you want to continue ? : ";
        cin>>ch;
    }
        while(ch=='Y'||ch=='y');
    return 0;
}
