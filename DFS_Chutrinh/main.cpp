#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
vector<int>a[int(1e5+10)];
int n , m, seen[100],top,stk[100];
void xuat(int so)
{
    cout << "YES \n";
    cout << so;
    cout << "\n";
    while (stk[top] != so)
    {
        cout << stk[top] << "\n";
        top--;
    }
    exit(0);
}

void dfs(int u)
{
    top++;
    stk[top] = u;
    seen[u] = 1;
    for (int k = 1; k <= int(a[u].size()); k++)
    {
        if (seen[a[u][k-1]] == 1) xuat(a[u][k-1]);
        if (seen[a[u][k-1]] == 0)
           dfs(a[u][k-1]);
    }
    seen[u] = 2;
    top--;
}

int main()
{
    cin >> n >> m;
    int u,v;
    for (int i = 1; i <= m ; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
    }
    memset(seen,sizeof(seen),0);
    for (int i = 1; i <= n; i++)
    if (seen[i] == 0)
    {
        top = 0;
        dfs(i);
    }
    cout << "NO";
}
