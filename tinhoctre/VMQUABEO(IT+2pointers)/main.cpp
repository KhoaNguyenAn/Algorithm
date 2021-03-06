#include <bits/stdc++.h>
#include <list>
#include <map>
#include <stack>
using namespace std;
const int N = 1e6+7;
#define ll long long
const int INF = 30005;
typedef pair <int,int> ii;
map <int,int> lua;
ll n,l,d,a[N],ans,mmax,mmin,j,b[N];
struct node
{
	  ll mi,ma;
};
node BIT[N];
void update(ll x,ll val)
{
	  b[x] = val;
	  for (ll k = x; k <= N; k+=k&-k)
		{
			if (BIT[k].mi == 0) BIT[k].mi = 1e9+7;
			BIT[k].mi = min(BIT[k].mi,val);
			BIT[k].ma = max(BIT[k].ma,val);
		}
}
node get(ll l,ll r)
{
		node res;
	  res.mi = INF;
	  res.ma = 0;
		while (r >= l)
		{
			 if (r - (r&-r) >= l)
			 {
					res.mi = min(res.mi,BIT[r].mi);
					res.ma = max(res.ma,BIT[r].ma);
					r = r -	(r & -r);
			 }
			 else
			 {
			 	  res.mi = min(res.mi,b[r]);
					res.ma = max(res.ma,b[r]);
					r--;
			 }
		}
		return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(i,a[i]);
	}
	ans = 0;
	mmax = 0;
	mmin = 1e9+7;
	ll j = 1;
  for (int i = 1; i<= n; i++)
	{
		mmax = max(mmax,a[i]);
		mmin = min(mmin,a[i]);
		while (mmax - mmin > d)
		{
			node tmp = get(j+1,i);
			mmax = tmp.ma;
			mmin = tmp.mi;
			j++;
		}
		// co xet doan (i,i) nen +1
		if (i-j >= l) ans+= (i-j-l+1);
	}
	cout << ans;
  return 0;
}
/*
///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "VMQUABEO"
#define Eureka cerr << "Eureka"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e6 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long n,l,d,a[N],res = 0;
deque <int> mmax,mmin;
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		#ifndef Kaze
		 ///freopen(taskname".INP","r",stdin);
		 ///freopen(taskname".OUT","w",stdout);
		#endif // Kaze
		cin >> n >> l >> d;
		for (int i = 1; i <= n; i++)
		   cin >> a[i];
		for (int i = 1, j = 1; i <= n; i++)
		{
				while (!mmax.empty() && a[mmax.back()] < a[i]) mmax.pop_back();
				while (!mmin.empty() && a[mmin.back()] > a[i]) mmin.pop_back();
				mmax.push_back(i);
				mmin.push_back(i);
				if (!mmax.empty() && !mmin.empty())
				while (abs(a[mmax.front()]-a[mmin.front()]) > d)
				{
					  j++;
					  while (!mmax.empty() && mmax.front() < j) mmax.pop_front();
						while (!mmin.empty() && mmin.front() < j) mmin.pop_front();
				}
				/// Do dai la so khoang cach giua j va i nen la i - j
				if (i - j >= l) res+= i - j + 1 - l;
		}
		cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/