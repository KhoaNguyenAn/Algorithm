#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t,d,n,a[N],f[N],ans[int(1e6+7)],res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> d >> n;
        res = 0;
        f[0] = 0;
        memset(ans,0,sizeof(ans));
        for (int j = 1; j <= n ; j++)
        {
            cin >> a[j];
            f[j] = (f[j-1]+a[j]) % d;
            if (f[j] == 0) res++;
            ans[f[j]]++;
        }
        for (int k = 0; k < d; k++)
          res+= (ans[k]*(ans[k]-1)) / 2;
        cout << res << "\n";
    }
    return 0;
}
