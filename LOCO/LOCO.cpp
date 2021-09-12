#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define INF 9999999999LL
const int N = 60;
ll n,m,base;
using namespace std;
int I[3][3] =
{
  {1,0,0},
  {0,1,0},
  {0,0,1}
};

int A[3][3] =
{
  {1,1,1},
  {1,0,0},
  {0,1,0}
};
int f[3][1] =
{
  {2},
  {1},
  {1},
};
struct ds
{
    ll d[N][N];
    int n1,m1;
    ds()
    {
        memset(d,0,sizeof(d));
    }
};
ds ans,cur,ok;
ds operator * (ds A1, ds B1)
{
    ds C;
    C.n1 = A1.n1;
    C.m1 = B1.m1;
    for (int i = 0; i < C.n1; i++)
     for (int j = 0; j < C.m1; j++)
        {
            C.d[i][j] = 0;
            for (int k = 0; k < A1.m1; k++)
            {
               C.d[i][j] = (C.d[i][j] + (A1.d[i][k] * B1.d[k][j]) % base) % base;
            }
        }
    return C;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LOCO.INP","r",stdin);
    freopen("LOCO.OUT","w",stdout);
    cin >> n >> base;
    if (n == 0 || n == 1)
    {
        cout << 1; return 0;
    }
    ans.m1 = 3;
    ans.n1 = 3;
    cur.m1 = 3;
    cur.n1 = 3;
    ok.m1 = 1;
    ok.n1 = 3;
    for (int i = 0; i < 3; i++)
     for (int j = 0; j < 3; j++)
        {
            ans.d[i][j] = I[i][j];
            cur.d[i][j] = A[i][j];
        }
    for (int i = 0; i < 3; i++) ok.d[i][0] = f[i][0];
    n = n-2;
    while (n > 0)
    {
        if (n & 1) ans = ans * cur;
        cur = cur * cur;
        n >>= 1;
    }
    ds res = ans * ok;
    cout << res.d[0][0];
    return 0;
}
