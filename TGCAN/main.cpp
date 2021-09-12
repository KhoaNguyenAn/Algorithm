#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n,a[100],ans,res[1000000];
int main()
{
    //freopen("TGCAN.INP","r",stdin);
    //freopen("TGCAN.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    int tong = 0;
    for (int i = 1; i <= n-2; i++)
        for (int j = i+1; j <= n-1;j++)
            for (int k = j+1; k <= n; k++)
                 {
                    if (a[i] == a[j] && a[i]+a[j] > a[k] && a[i]+a[k] > a[j] && a[j] + a[k] > a[i]) ans++;
                    if (a[i] == a[k] && a[i]+a[j] > a[k] && a[i]+a[k] > a[j] && a[j] + a[k] > a[i]) ans++;
                    if (a[j] == a[k] && a[i]+a[j] > a[k] && a[i]+a[k] > a[j] && a[j] + a[k] > a[i]) ans++;
                 }
    cout << ans;
}


