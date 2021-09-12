#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;

ll dp[3000][3000],n,m,t,memo[3000][3000];
ll solve(int x, int y)
{
	  if (x == 0 || y == 0) return 0;
	  if (memo[x][y]) return dp[x][y];
	  memo[x][y] = 1;
	  dp[x][y] = solve(x-1,y) + 1 + solve(x-1,y-1);
	  return dp[x][y];
}
int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> t;
		while (t--)
		{
			 cin >> n >> m;
			 for (int i = 1; i <= 1000; i++)
			 {
			 	  ll ans = solve(i,n);
			 	  if (ans >= m)
			 	  {
			 	  	 cout << i << endl;
			 	  	 break;
			 	  }
			 }
		}
		return 0;
}