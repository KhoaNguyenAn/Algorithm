#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
typedef  long long ll;
using namespace std;
const int N = 1e5+7;
ll n,k,b[N],f[N],sl,a[N];

int main()
{
   cin >> n >> k;
    b[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
        b[i] = b[i-1] + a[i];
    ll sl = 0;
    ll ans = 1e20;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    if (sl < k)
    {
        f[i] = abs(sl*a[i]-b[i-1])+f[i-1];
        sl++;
    }
    else
    {
        ans = min(ans,abs(ll(f[i-1])));
        f[i] = abs(k*a[i]-(b[i-1]-b[i-k-1]))+f[i-1];
        f[i] = abs(f[i] - abs(abs((b[i]-b[i-k])-k*a[i-k])));
    }
    cout << ans;
}
