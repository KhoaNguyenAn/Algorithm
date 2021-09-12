#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e5 +2;
const int INF = 1e9 + 7;
long long n,m,a[N];
long double l,r,sum,ans,mid;
long long check(long double x)
{
		long long res = 0;
		for (int j = 1; j <= m; j++) res = res + long(floor(a[j]/x));
		return res;
}
int main()
{
	  ios_base::sync_with_stdio(0);
	  cin.tie(0);
	  cout.tie(0);
	  freopen("POTION.INP","r",stdin);
	  freopen("POTION.OUT","w",stdout);
	  cin >> n >> m;
	  sum = 0;
	  for (int i = 1; i <= m; i++)
	  {
			cin >> a[i];
			sum += a[i];
	  }
	  sum /= n;
	  if (check(sum)==n)
		{
			cout << sum;
			return 0;
		}
	  l = 0;
	  r = sum;
	  for (int i = 1; i <= 600; i++)
		{
				mid = (l+r) /2;
				ans = check(mid);
				if (ans >= n) l = mid; else r = mid;
		}
		cout << setprecision(6) << fixed << mid;
}