#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int a;

bool comp(mang a1, mang b1)
{
    return a1.y < b1.y;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
            cin >> b[i];
    sort(b+1,b+1+n);

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> xx >> yy;
        a[i].x = xx;
        a[i].y = yy;
    }
    sort(a+1,a+q+1,comp);
    for (int i = 1; i <= n; i++)
    {

    }
    return 0;
}
