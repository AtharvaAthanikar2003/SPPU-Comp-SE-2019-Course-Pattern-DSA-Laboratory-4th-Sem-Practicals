/* 
A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method.
*/

#include <iostream>
using namespace std;
struct node
{
    char name[20];
    int count;
    struct node *child[20];
} *root;
class tree
{
public:
    tree()
    {
        root = NULL;
    }
    void create()
    {
        root = new node();
        cout << "\nEnter the name of the book:- ";
        cin >> root->name;
        cout << "\nEnter the no.of chapters:- ";
        cin >> root->count;
        for (int i = 0; i < root->count; i++)
        {
            root->child[i] = new node();
            cout << "\nEnter the name of chapter:- ";
            cin >> root->child[i]->name;
            cout << "\nEnter the no.of sessions:- ";
            cin >> root->child[i]->count;
            for (int j = 0; j < root->child[i]->count; j++)
            {
                root->child[i]->child[j] = new node();
                cout << "\nEnter the name of the session:- ";
                cin >> root->child[i]->child[j]->name;
                cout << "\nEnter the no.of subsections:- ";
                cin >> root->child[i]->child[j]->count;
                for (int k = 0; k < root->child[i]->child[j]->count; k++)
                {
                    root->child[i]->child[j]->child[k] = new node();
                    cout << "\nEnter the name of subsection:- ";
                    cin >> root->child[i]->child[j]->child[k]->name;
                }
            }
        }
    }
    void display()
    {
        cout << "\n**********Welcome To BookStore**********";
        cout << "\nName of book:- " << root->name;
        cout << "\nNumber of chapters:- " << root->count;
        for (int i = 0; i < root->count; i++)
        {
            cout << "\nChapter Name:- " << root->child[i]->name;
            for (int j = 0; j < root->child[i]->count; j++)
            {
                cout << "\n|____Section Name:- " << root->child[i]->child[j]->name;
                for (int k = 0; k < root->child[i]->child[j]->count; k++)
                {
                    cout << "\n|________Subsection Name:- " << root->child[i]->child[j]->child[k]->name;
                }
            }
        }
    }
};
int main()
{
    tree t;
    t.create();
    t.display();
    return 0;
}
