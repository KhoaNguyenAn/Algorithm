#include <bits/stdc++.h>
#include <iostream>
#define taskname "LMINMAX"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1e6 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
int n,m,a[N],f[N],res;
deque <int> mmax;
deque <int> mmin;
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen(taskname".INP","r",stdin);
	freopen(taskname".OUT","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[0] = 1;
	res = 1;
	for (int i = 1; i <= n; i++)
	 for (int j = f[i-1]; j <= i; j++)
		{
			while (!mmax.empty() && mmax.front() < j) mmax.pop_front();
			while (!mmin.empty() && mmin.front() < j) mmin.pop_front();
			while (!mmax.empty() && a[mmax.back()] < a[i]) mmax.pop_back();
			while (!mmin.empty() && a[mmin.back()] > a[i]) mmin.pop_back();
			mmax.push_back(i);
			mmin.push_back(i);
			if (abs(a[mmax.front()]-a[mmin.front()] <= m))
			{
					f[i] = j;
					res = max(res,i-j+1);
					break;
			}
		}
		cout << res;
		return 0;
}



