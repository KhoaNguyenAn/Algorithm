#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
using namespace std;
const int N =250;
int n,k,ans,par[N];
bool seen[N];
vector<int>a[N];
void dfs(int u)
{
	  seen[u] = true;
	  for (int v = 0; v < a[u].size(); v++)
		if (!seen[a[u][v]])
		{
				dfs(a[u][v]);
				par[u]+=par[a[u][v]];
				for (int v1 = 0; v1 < a[u].size();v1++)
				if (v1 != v)
				if (par[u] == k) ans = min(ans,int(a[u].size())-v-1);
		}
}

int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> k; int u,v;
		ans = 1e9 + 7;
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			a[u].push_back(v);
		}
		fill(seen+1,seen+n+1,false);
		fill(par+1,par+n+1,1);
		dfs(1);
		cout << ans;
		return 0;
}