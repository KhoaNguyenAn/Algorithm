#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
const int N = 1e5+3;
int n,m,p,a[N],b[N],c[N],sl,ok,sl1;
bool res[N],bum[N],tmp[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEARCH.INP","r",stdin);
    freopen("SEARCH.OUT","w",stdout);
    cin >> n >> m >> p;
    memset(res,true,sizeof(res));
    memset(tmp,false,sizeof(tmp));
    for (int i = 1; i <= n ; i++)
    {
        cin >> a[i];
        tmp[a[i]] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        res[b[i]] = false;
    }
    for (int i = 1; i <= p ; i++) cin >> c[i];

    sl = 0;
    memset(bum,false,sizeof(bum));
    for (int i = 1; i <= p; i++)
    {
        if (res[c[i]] == true)
        {
            sl++;
            if (bum[c[i]] == false && tmp[c[i]]== true) sl1++;
            bum[c[i]] = true;
        }
        else
        if (res[c[i]] == false)
        {
           if (sl >= n && sl1 >= n) ok = max(sl,ok);
           sl = 0;
           sl1 = 0;
           memset(bum,false,sizeof(bum));
        }
    }
    if (sl >= n && sl1 >= n) ok = max(sl,ok);
    cout << ok;
    return 0;
}
