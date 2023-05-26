/*


*/
#include<iostream>
using namespace std;
class Telephone
{
    int hash_address,i,j;
    long int key;
    int x;
    int mobno[10];
    string name[10];
    public:
        Telephone()
        {
            for (int i=0;i<10;i++)
            {
                mobno[i]=-1;
            }
        }
        void insertRecord_LP()
        {
            cout<<"Enter no.of Records:-";
            cin>>x;
            for (int i=0;i<x;i++)
            {
                cout<<"Enter The Telephone No.:-";
                cin>>key;
                hash_address=key%10;
                if (mobno[hash_address]==-1)
                {
                    mobno[hash_address]=key;
                    cout<<"Enter The Name:-";
                    cin>>name[hash_address];
                }
                else //linear probing
                {
                    int i=1;
                    while (mobno[hash_address+i]<10)
                    {
                        if (mobno[hash_address+i]==-1)
                        {
                            mobno[hash_address+i]=key;
                            cout<<"Enter The Name:-";
                            cin>>name[hash_address+i];
                            break;
                        }
                        else if (mobno[hash_address+i]!=-1)
                        {
                            i++;
                        }
                    }
                }
            }
        }
        void insertRecord_QP()
        {
            cout<<"Enter no.of Records:-";
            cin>>x;
            for (int i=0;i<x;i++)
            {
                cout<<"Enter The Telephone No.:-";
                cin>>key;
                hash_address=key%10;
                if (mobno[hash_address]==-1)
                {
                    mobno[hash_address]=key;
                    cout<<"Enter The Name:-";
                    cin>>name[hash_address];
                }
                else //quadratic probing
                {
                    int i=1;
                    hash_address=hash_address+(i*i);
                    while (mobno[hash_address]<10)
                    {
                        if (mobno[hash_address]==-1)
                        {
                            mobno[hash_address]=key;
                            cout<<"Enter The Name:-";
                            cin>>name[hash_address];
                            break;
                        }
                        else if (mobno[hash_address]!=-1)
                        {
                            i++;
                            hash_address=hash_address+(i*i);
                        }
                    }
                }
            }
        }
        void display()
        {
            for(int address=0; address<10; address++)
                {
                    cout<< address <<" "<< mobno[address] <<" "<< name[address] <<endl;
                }  
        } 
};
int main()
{
    Telephone t1;
    int ch;
    do
    {
        cout<<"****** Telephone Entries ######";
        cout<<"\nEnter Your Choice :- ";
        cout<<"\n1.Insert Records By Linear Probing ";
        cout<<"\n2.Insert Records By Quadratic Probing ";
        cout<<"\n3.Display ";
        cout<<"\n4.Exit ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            t1.insertRecord_LP();
            break;
            case 2:
            t1.insertRecord_QP();
            break;
            case 3:
            t1.display();
            break;
            case 4:
            exit(0);
            break;
        }
    } while (ch!=4);
    return 0;
}
