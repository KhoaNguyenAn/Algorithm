#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int n,a[N],z1,z2,res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RUNNING.INP","r",stdin);
    freopen("RUNNING.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int x = 1; x <= n; x++)
    {
        z1 = x+1;
        z2 = x+1;
        for (int y = x+1; y <= n; y++)
        {
            while (a[y]-a[x] > a[z1]-a[y] && z1 < n) z1++;
            while (a[z2]-a[y] <= 2*(a[y]-a[x]) && z2 < n) z2++;
            res+= z2-z1;
        }
    }
    cout << res;
    return 0;
}
