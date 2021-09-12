// http://codeforces.com/contest/981/problem/D
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
const int N = 1e5 + 7;
int n,k;
long long a[100],b[100],ans;
bool f[100][100];
bool kt(long long ans1)
{
    for (int i = 1; i <= n ; i++)
    {
        if ((b[i] & ans1) == ans1) f[i][1] = true; else f[i][1] = false;
        for (int j = 2; j <= k && j <= i; j++)
        {
            f[i][j] = false;
            for (int i1 = j-1; i1 <= i-1; i1++)
            if (f[i1][j-1] == true && (((b[i]-b[i1]) & ans1) == ans1))
            {
                f[i][j] = true;
                break;
            }
        }
    }
    return f[n][k];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ans = 0;
    for (int d = 60; d >= 0; d--)
    {
        ans = (ans ^ (1LL << d));
        if (kt(ans) == false) ans = (ans ^ (1LL << d));
     }
    cout << ans;
    return 0;
}
