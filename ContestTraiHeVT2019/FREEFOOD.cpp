#include <bits/stdc++.h>
#include <iostream>
#define taskname "FREEFOOD"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1e5 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
int n,x[N], a[N], idx[N], mp[N],cal[N],logm,tam;
long long t,sum[N];
queue <int> que;
bool cmp(int A1,int B1)
{
	return a[A1] < a[B1];
}
void update(int x, int k)
{
	for (int ii = x; ii <= n; ii+= ii & -ii)
	{
		 cal[ii]++;
		 sum[ii] += k;
	}
}
int get(ll v)
{
	 int ans = 0,  x = 0 , mask = logm;
	 for (; mask > 0; mask >>=1)
	 {
	 	 int y = x + mask;
	 	 if (y <= n && sum[y] <= v)
		 {
		 	 ans+= cal[y];
		 	 v -= sum[y];
			 x = y;
		 }
	 }
	 return ans;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		freopen(taskname".INP","r",stdin);
		freopen(taskname".OUT","w",stdout);
		cin >> n >> t;
		for (int i = 1; i <= n; i++)
		{
			 cin >> x[i];
			 cin >> a[i];
			 idx[i] = i;
		}
		sort(idx+1,idx+n+1,cmp);
		for (int i = 1; i <= n; i++)
			mp[idx[i]] = i;
		logm = 1;
		while (logm*2<=n) logm<<=1;
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			 update(mp[i],a[i]);
			 tam = get(t-x[i]);
			 if (tam > res) res = tam;
		}
		cout << res;
		return 0;
}



