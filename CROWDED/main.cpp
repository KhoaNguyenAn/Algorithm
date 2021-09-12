#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#define INF 9999999
using namespace std;
const int N = 1e6;
struct mag
{
    int x,h;
};
mag a[N],stk[N];
bool comp(mag A1,mag B1)
{
    return (A1.x < B1.x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CROWDED.INP","r",stdin);
    freopen("CROWDED.OUT","w",stdout);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].h;
    sort(a+1,a+n+1,comp);
    stk[0] = 0;
    top = 0;
    bot = 1;
    res = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[i].h > stk[bot].h) bot--;
        bot++;
        stk[bot].h = a[i].h;
        stk[bot].x = a[i].x;
        while (stk[top].h < a[i].h - d) top++;
        if (stk[top] >= (a[i] << 1)) f[i] = 1;
    }

    // VE PHAI

    stk[0] = 0;
    top = 0;
    bot = 1;
    for (int i = n; i >= 1; i++)
    {
        while (a[i].h > stk[bot].h) bot--;
        bot++;
        stk[bot].h = a[i].h;
        stk[bot].x = a[i].x;
        while (stk[top].h < a[i].h - d) top++;
        if (stk[top] >= (a[i] << 1)) f[i] = 1;
    }
    for (int i = 1; i <= n ;i++) if (f[i]) res++;
    cout << res;
    return 0;
}
