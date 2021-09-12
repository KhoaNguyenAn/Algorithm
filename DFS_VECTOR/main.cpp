#include <stdio.h>
#include <cstring>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
vector<int>a[int(1e3+10)];
int n,m,seen[100],b[100][100],par_e[100];

void xuat()
{
    cout << "YES";
    exit(0);
}

void dfs(int u)
{
    int tam;
    seen[u] = 1;
    for (int k = 1; k <= int(a[u].size()); k++)
      if (a[u][k-1] != par_e[u])
        {
            if (u == b[a[u][k-1]][1]) tam = b[a[u][k-1]][2]; else tam = b[a[u][k-1]][1];
            if (seen[tam] == 1) xuat();
            par_e[tam] = a[u][k-1];
            dfs(tam);
        }
 }

int main()
{
    int n , m , u , v;
    cin >> n >> m;
    for (int i = 1; i <= m ; i++)
    {
        cin >> u >> v;
        b[i][1] = u;
        b[i][2] = v;
        a[u].push_back(i);
        a[v].push_back(i);
    }
    memset(seen,sizeof(seen),0);
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
    }
    cout << "NO";
}
