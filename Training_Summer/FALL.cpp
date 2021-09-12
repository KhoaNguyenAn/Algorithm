#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#define long long ll
using namespace std;
struct mang
{
    int x,y,h;
};
mang a[N];
bool comp(mang a1,mang b1)
{
    return a1.h < b1.h;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y >> m;
    for (int i = 1; i <= n ;i++)
        cin >> a[i].x >> a[i].y >> a[i].h;
    sort(a+1,a+n+1,comp);
    for (int i = n; i >= 1; i--)
    {
       for (int j = 1; j <= n; j++)
        if (j != i && (a[i].h - a[j].h <= m))
        {

        }
    }
    return 0;
}
