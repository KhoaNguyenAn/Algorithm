#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int chat_np(int ans)
{
    int l = 1;
    int r = 1000;
    while (l < r)
    {
        int tmp1 = ((l+r) >> 1);
        if (a[tmp1] >= ans)
        {
            r = tmp1-1;
        }
        else
        {
           l = tmp1+1;
        }
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n ; i++) cin >> a[i];
    memset(c,0,sizeof(c));
    for (int i = 1; i <= m ; i++)
    {
        cin >> x >> y;
        if (c[y] != 0)
        {
            if (x > c[y]) c[y] = x;
        } else c[y] = x;
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= 1000; j++)
        if (c[j] != 0)
        {
            int tmp = lower_bound(a+1,a+n+1,((a[i]-2*c[j])-a));
            f[i] = min(f[i],f[tmp]+j);
        }
    }
    cout << f[n];
    return 0;
}
