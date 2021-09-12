#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
const int N = 2e6+5;
const int INF = 1e9+9;
ll a[N],BIT[N],n,ans,b[N],m,u,v;
void update(ll x,ll val)
{
    b[x]=val;
    for (ll j = x; j <= int(2e6+2); j+= (j&-j))
    {
      BIT[j]=val;
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
    freopen("QUERY.INP","r",stdin);
    freopen("QUERY.OUT","w",stdout);
    cin >> n >> m;
    char x;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
			  if (x == 'S')
				{
					cin >> u >> v;
				  update(u,v);
				}
				else
				{
					cin >> u >> v;
					cout << get(u,v) << "\n";
				}
    }
    return 0;
}