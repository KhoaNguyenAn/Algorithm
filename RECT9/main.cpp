#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#define Ankhoa "RECT9"
using namespace std;
const int N = 1e2 + 5;
int n , m , mmax , a[N][N] , h[N][N] , b[N] , stk[N] , top , l[N] , r[N];
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(Ankhoa".INP","r",stdin);
    freopen(Ankhoa".OUT","w",stdout);
    cin >> n >> m;
    mmax = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m ; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 9) h[i][j] = h[i-1][j] + 1; else h[i][j] = 0;
        }
        for (int j = 1; j <= m ; j++)
            b[j] = h[i][j];
        fill(l+1,l+N,0);
        fill(r+1,r+N,0);
        stk[0] = 0;
        top = 0;
        b[0] = -1;
        b[m+1] = -1;
        for (int j = 1; j <= m; j++)
        {
          while (b[stk[top]] >= b[j]) top--;
            l[j] = stk[top] + 1;
            top++;
            stk[top] = j;
        }
        stk[0] = m+1;
        top = 0;
        b[0] = -1;
        b[m+1] = -1;
        for (int j = m ; j >= 1; j--)
        {
          while (b[stk[top]] >= b[j]) top--;
            r[j] = stk[top] - 1;
            top++;
            stk[top] = j;
        }
        for (int j = 1; j <= m; j++)
        {
            int kq = b[j] * (r[j]-l[j]+1);
            if (mmax < kq) mmax = kq;
        }
    }
    cout << mmax;
}
