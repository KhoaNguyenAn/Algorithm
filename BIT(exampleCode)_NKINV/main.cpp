#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
const int N = 1e6+5;
const int INF = 1e9+9;
ll a[N],BIT[N],n,ans,b[N];
void update(ll x,ll val)
{
    b[x]+=val;
    for (ll j = x; j <= 60000; j+= (j&-j))
    {
      BIT[j]+=val;
    }
}
ll get(ll L,ll R)
{
    ll sum = 0;
    while (R >= L)
    {
        if (R - (R & -R) >= L)
        {
            sum+= BIT[R];
            R = R - (R & -R);
        }
        else
        {
            sum+= b[R];
            R--;
        }
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(a[i],1);
        ans+= get(a[i]+1,60000);
    }
    cout << ans;
    return 0;
}