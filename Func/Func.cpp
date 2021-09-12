#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int k,r,q,p,m;
int cal(int k , int r, int p, int q, int m)
{
    if (k == 1) return (p / q);
    else return (1 / ((r + cal(k,r,p,q,m)) % m));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FUNC.inp","r",stdin);
    freopen("FUNC.out","w",stdout);
    while (cin >> k >> r >> p >> q >> m)
    {
        for (int i = 1; i <= n; i++)

    }
    cout << cal(k,r,p,q,
    return 0;
}
