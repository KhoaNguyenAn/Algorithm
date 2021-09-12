#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair <long long ,long long> ii;
const int INF = 1e15 + 7;
priority_queue <ii> que;
const int N = 1e5+5;
long long n,e,t,m,d[N],res,u,v,s;
bool seen[N];
vector <ii> a[N];
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> e >> t >> m;
		for (int i = 1; i <= m; i++)
		{
			   cin >> u >> v >> s;
			   a[v].push_back(ii(u,s));
		}
		fill(seen+1,seen+n+1,false);
		fill(d+1,d+n+1,INF);
		d[e] = 0;
		que.push(ii(0,e));
		while (!que.empty())
		{
			  ii x = que.top();
			  que.pop();
			  if (seen[x.Y]==true) continue;
			  seen[x.Y] = true;
			  for (v = 0; v < a[x.Y].size();v++)
				{
					 ii tmp = a[x.Y][v];
					 if (d[tmp.X] > d[x.Y]+tmp.Y)
					 {
							d[tmp.X] = d[x.Y] + tmp.Y;
							que.push(ii(-d[tmp.X],tmp.X));
					 }
				}
		}
		res = 0;
		for (int i = 1; i<=n;i++)
			if (d[i] <= t) res++;
		cout << res;
    return 0;
}
