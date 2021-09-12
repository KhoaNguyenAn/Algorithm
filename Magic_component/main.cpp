#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define INF 9999999999LL
#define base 1000000007
using namespace std;
ll n;
const int N = 100;
int A[5][5] =
{
    {0,1,1,0,1},
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,0,1,0,0},
    {0,0,0,1,0}
};
int I[5][5] =
{
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,0,1,0,0},
    {0,0,0,1,0},
    {0,0,0,0,1}
};
int f[5][1] =
{
    {1},
    {0},
    {0},
    {0},
    {0}
};
struct ds
{
    ll d[N][N];
    int m1,n1;
	ds() {memset(d,0,sizeof(d));}
};
ds ans,cur,ok;
ds operator * (ds A1,ds B1)
{
    ds C;
    C.m1 = B1.m1;
    C.n1 = A1.n1;
   for (int i = 0; i < C.n1; i++)
    for (int j = 0; j < C.m1; j++)
    {
        C.d[i][j] = 0;
        for (int k = 0; k < A1.m1; k++)
           C.d[i][j] = (C.d[i][j] + (A1.d[i][k]*1LL * B1.d[k][j]*1LL) % base) % base;
    }
    return C;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans.m1 = 5;
    ans.n1 = 5;
    cur.m1 = 5;
    cur.n1 = 5;
    ok.m1 = 1;
    ok.n1 = 5;
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    {
        ans.d[i][j] = I[i][j];
        cur.d[i][j] = A[i][j];
    }
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 1; j++) {ok.d[i][j] = f[i][j];}
    while (n > 0)
    {
        if (n % 2 == 1) ans = ans*cur;
        cur = cur*cur;
        n >>= 1;
    }
    ds res = ans * ok;
    cout << res.d[0][0];
    return 0;
}
