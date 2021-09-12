#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
int a[300000],f[300000],g[300000],d[300000],t[30000],n,mid,ans,j,k[30000];
using namespace std;
const int inf = (1 << 31);

int bns(int l , int r , int v )
{
   while (l <= r)
   {
        mid = (l + r) / 2;
       if (g[mid] >= v)
       {
           r = mid - 1;
       }
       else l = mid + 1;
   }
   return r;
}

int main()
{
    cin >> n ;
    for (int i = 1; i<= n; i++)
    {
         cin >> a[i];
    }
    ans = 0;
    g[0] = inf;
    f[0] = 0;
    d[0] = 0;
    for (int i = 1; i<=n; i++)
    {
      j = bns(1,ans,a[i]);
      f[i] = j + 1;
      g[f[i]] = a[i];
      d[f[i]] = i;
      t[i] = d[j];
      if (f[i] > ans) ans = f[i];
    }
    int tam = d[ans];
    for (int i = ans ; i >= 1; i--)
     {
        k[i] = tam;
        tam = t[tam];
     }
    cout << ans <<"\n";
    for (int i = 1;i <= ans;i++)
    {
        cout << a[k[i]] <<" ";
    }
}
