#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;
int a[10][10],seen[100],i,n,m,u,v,mmax,dem,f[100],vt;

void dfs(int u)
{
    seen[u] = true;
    for (int k = 1; k <= n; k++)
    if (a[u][k] == true && seen[k] == true)
    {
        f[u] = max(f[k]+1,f[u]);
        if (f[u] > mmax)
        {
            mmax = f[u];
            vt = u;
        }
    }
    else
    if (a[u][k] == true && seen[k] == false)
    {
        f[u] = max(f[k] + 1,f[u]);
        dfs(k);
        f[u] = max(f[k] + 1,f[u]);
        if (f[u] > mmax)
        {
            mmax = f[u];
            vt = u;
        }
    }
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m ; i++)
    {
        cin >> u >> v;
        a[u][v] = true;
   }
    memset(seen,sizeof(seen),false);
    mmax = 0;
    for (int i = 1; i <= n; i++)
    if (seen[i]==false) dfs(i);
    cout << mmax;
    cout << "\n";
    int sl = 0;
    cout << vt << ' ';
    while (true)
    {
      for (int i = 1; i <= n; i++)
      if (a[vt][i] == true && f[i] == f[vt] - 1)
      {
         vt = i;
         sl++;
         cout << i << ' ';
         break;
      }
      if (sl == mmax) return 0;
    }
}
