/*
Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
list to perform BFS. Use the map of the area around the college as the graph. Identify the
prominent land marks as nodes and perform DFS and BFS on that.
*/

#include <iostream>
using namespace std;

void BFS(int arr[6][6], int n)
{
    int vis[n];
    int rear = 0, front = 0;
    int queue[2 * n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    queue[rear] = 0;
    vis[0] = 1;
    rear++;
    while (front != rear)
    {
        int node = queue[front];
        front++;
        cout << node + 1 << " ";
        for (int i = 0; i < n; i++)
        {
            if (arr[node][i] == 1 and vis[i] == 0)
            {
                queue[rear] = i;
                rear++;
                vis[i] = 1;
            }
        }
    }
    cout << endl;
}

void DFS(int graph[6][6], int n)
{
    int vis[n];
    int stack[2 * n];
    int top = 0;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    stack[top] = 0;
    while (top != -1)
    {
        int node = stack[top];
        top--;
        if (vis[node] == 0)
        {
            vis[node] = 1;
            cout << node + 1 << " ";
            for (int i = 0; i < n; i++)
            {
                if (graph[node][i] == 1)
                {
                    top++;
                    stack[top] = i;
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    int graph[6][6] = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 1},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0}};
    int ch;
    do
    {
        cout << "The Graph is :" << endl;
        cout << "\t";
        for (int i = 0; i < 6; i++)
        {
            cout << i + 1 << "\t";
        }
        cout << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << i + 1 << "\t";
            for (int j = 0; j < 6; j++)
            {
                cout << graph[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "===========MENU============" << endl;
        cout << "1.BFS traversal of graph " << endl;
        cout << "2.DFS traversal of graph " << endl;
        cout << "3.Exit " << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            cout << "BFS traversal of a graph is : ";
            BFS(graph, 6);
            cout << "--------------------------------------------" << endl;
            break;
        case 2:
            cout << "DFS traversal of a graph is : ";
            DFS(graph, 6);
            cout << "---------------------------------------------" << endl;
            break;
        case 3:
            exit(0);
            break;
        }
    } while (ch == 1 or ch == 2);
    cout << "-----Thank You------" << endl;
    return 0;
}
