#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#define INF 99999999
#include <string>
#include <cstring>
#include <stdlib.h>
typedef long long ll;
const int N = 1e4 + 7;
using namespace std;
int f[N],tmp1,tmp2,tmp3;
bool c[N];
ll n,m,v;

/*
    Author : A_K
    10CTin ~~~~
    Contest : PO2018C2
    Project : Booking_Room
                            */
int main()
{
    cin >> n >> m;
    fill(c,c+n+1,false);
    for (int i = 1; i <= m ; i++)
    {
        cin >> v;
        c[v] =  true;
    }
    f[0] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
    if (c[i] == false)
     tmp1 = f[i-1] + 5; else tmp1 = f[i-1];
    if (i > 2)
    {
      if (c[i-2] == false)
        tmp2 = f[i-3] + 9; else tmp2 = tmp1;
    } else tmp2 = INF;
    if (i > 4)
    {
      if (c[i-4] == false)
        tmp3 = f[i-5] + 15; else tmp3 = tmp1;
    } else tmp3 = INF;
    f[i] = min(tmp1,min(tmp2,tmp3));
    }
    cout << f[n] << "00000";
}
/*
13 5
3 6 7 11 12 */
// 2900000



