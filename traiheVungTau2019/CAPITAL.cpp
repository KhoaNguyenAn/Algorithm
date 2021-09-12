#include <bits/stdc++.h>
#include <iostream>
#define taskname "CAPITAL"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 3e5 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
vector <int> a[N];
int num[N],low[N],cnt = 0,xmax = -1,res = INF,n,m,u,v,TPLT = 0;
void DFS(int u,int p)
{
	 num[u] = low[u] = ++cnt;
	 int x = (p != -1);
	 for (auto v: a[u])
	 {
	 	 if (v != p)
			if (num[v] != 0) low[u] = min(low[u],num[v]);
		  else
			{
				 DFS(v,u);
				 low[u] = min(low[u],low[v]);
				 if (low[v] >= num[u]) x++;
			}
	 }
	 if (x == xmax && u < res)
	 {
	 	  xmax = x;
	 	  res = min(res,u);
	 }
	 else
	 {
	 	 if (x > xmax)
		 {
		 	 xmax = x;
		 	 res = u;
		 }
	 }
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		freopen(taskname".INP","r",stdin);
		freopen(taskname".OUT","w",stdout);
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			 cin >> u >> v;
			 a[u].push_back(v);
			 a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		if (num[i] == 0)
	  {
	  	 DFS(i,-1);
	  	 TPLT++;
	  }
	  cout << TPLT+xmax-1 << " " << res;
		return 0;
}



