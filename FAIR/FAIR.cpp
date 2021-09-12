#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <iostream>

const int N = 1e3 + 5;
const int inf = 1e10 + 7;
using namespace std;
int a[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m ; j++)
             cin >> a[i][j];

    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = inf;
    for (int i = 1; i <= n ; i++)
        a[i][i] = 0;
    for (int k = 1 ; k <= n; k++)
        for (int i = 1; i <= n*n; i++)
           for (int j = 1; j <= n*n; j++)
                if (i - n >= 0 && j - n >= 0)
                    {
                      if  (i - n == j)
                      {
                          a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                      }
                      if   (i-1 == j)
                      {
                          a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                      }
                      if    (i+1 == j)
                      {
                          a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                      }
                      if   (i+n == j)
                      {
                          a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                      }
                    }
}
