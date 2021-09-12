#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#define ankhoa "REPAIR"
#define INF 999999
using namespace std;
const int N = 1e5 + 3;
int n,m,b1[N],cnt[N],b2[N],v,ans,sl,dem,par[N];
struct mang
{
    int x;
    int y;
    int w;
};
mang a[N];

bool kt(mang a, mang b)
{
    return a.w < b.w;
}

int getroot(int u)
{
    if (par[u] == -1) return u;
    par[u] = getroot(par[u]);
    return par[u];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= m; j++)
        {
           cin >> v;
          if (v == -1)
          {
              a[(i-1)*m+j].x = i;
              a[(i-1)*m+j].y = j+n;
              a[(i-1)*m+j].w = INF;
          }
          else
          {
           a[(i-1)*m+j].x = i;
           a[(i-1)*m+j].y = j+n;
           a[(i-1)*m+j].w = v;
          }
        }
    sort(a+1,a+(n*m)+1,kt);
    sl = 0;
    dem = 0;
    int i = 0;
    fill(par+1,par+n+m+1,-1);
    while (dem != n+m-1)
    {
         i++;
         int x1 = getroot(a[i].x);
         int y1 = getroot(a[i].y);
         if (x1 != y1)
         {
            dem++;
            if (a[i].w != 0)
            {
                ans+= a[i].w;
                sl++;
                b1[sl] = a[i].x;
                b2[sl] = a[i].y;
            }
            if (cnt[x1] > cnt[y1])
            {
                par[y1] = x1;
                cnt[x1] += cnt[y1];
            }
            else
            {
                par[y1] = x1;
                cnt[y1] += cnt[x1];
            }
         }
    }
    cout << ans << "\n";
    cout << sl  << "\n";
    for (int i = 1; i <= sl; i++) cout << b1[i] << " " << b2[i] << "\n";
}
