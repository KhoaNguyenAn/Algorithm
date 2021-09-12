#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
const int N = 1e5;
int t,d,n,a[N],ans[int(1e6+4)],res,f[N];
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> d >> n;
        for (int j = 1; j <= n ; j++)
        {
            cin >> a[j];
            f[j] = (f[j-1]+a[j]) % d;
            ans[f[j]]++;
        }
        for (int k = 1; k <= d; k++)
         res+= (ans[k] * (ans[k]-1)) / 2;
    }
    cout << res;
    return 0;
}
