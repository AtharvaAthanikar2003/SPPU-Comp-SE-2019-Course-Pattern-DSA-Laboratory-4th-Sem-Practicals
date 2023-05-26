/*
Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each
key ki . Build the Binary search tree that has the least search cost given the access
probability for each key.
*/

#include <iostream>
#include <stdio.h>
#define MAX 10
using namespace std;
void con_obst(void);
void print(int, int);
int p[MAX], q[MAX], w[10][10], c[10][10], r[10][10], i, j, k, n, m;
char idnt[10][10];
int main()
{
    cout << "Enter the no.of identifiers: ";
    cin >> n;
    cout << "Enter the identifiers: \n";
    for (int i = 1; i <= n; i++)
    {
        cin >> idnt[i];
    }
    cout << "Enter success probability of identifiers: \n";
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    cout << "Enter failure probability of identifiers: \n";
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    con_obst();
    print(0, n);
    cout << endl;
}
void con_obst(void)
{
    int i, j, l;
    for (int i = 0; i < n; i++)
    {
        c[i][i] = 0.0;
        r[i][i] = 0;
        w[i][i] = q[i];
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
    }
    c[n][n] = 0.0;
    r[n][n] = 0;
    w[n][n] = q[n];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            w[j][j + i] = q[j + i] + p[j + i] + w[j][j + i - 1];
            c[j][j + i] = 9999;
            for (l = j + 1; l <= j + i; l++)
            {
                if (c[j][j + 1] > (c[j][l - 1] + c[l][j + 1]))
                {
                    c[j][j + i] = c[j][l - 1] + c[l][j + 1];
                    r[j][j + i] = l;
                }
            }
            cout << endl;
        }
        cout << "\nOptimal BST is:: \n";
        cout << "\nw[0]["<<n<<"]:: " << w[0][n];
        cout << "\nc[0]["<<n<<"]:: " << c[0][n];
        cout << "\nr[0]["<<n<<"]:: " << r[0][n];
    }
}
void print(int i, int j)
{
    if (i<j)
    {
        cout << "\n" << idnt[r[i][j]];
    }
    else
        return;
    print(i, r[i][j] - 1);
    print(r[i][j], j);
}
