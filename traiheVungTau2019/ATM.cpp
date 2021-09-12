#pragma comment(linker, "/STACK: 2000000")
#include <bits/stdc++.h>
#include <iostream>
#define taskname "ATM"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 5e5 + 1;
const ll INF = 1e9+10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
stack <int> que;
vector <int> a[N];
vector <int> b[N];
int f[N];
int n,m,u,v,s,sum[N],p,mark[N],num[N],low[N],cnt = 0,scc = 0,label[N],cost[N];
bool seen[N];
void DFS(int u)
{
	 que.push(u);
	 num[u] = low[u] = ++cnt;
	 for (int v: a[u])
	 if (seen[v] == false)
	 {
		  if (num[v] != 0) low[u] = min(low[u],num[v]);
		  else
			{
				  DFS(v);
				  low[u] = min(low[u],low[v]);
			}
	 }
	 if (low[u]==num[u])
	 {
	 scc++;
	 while (true)
	 {
	 	 int k = que.top();
	 	 que.pop();
	 	 sum[scc]+= cost[k];
	 	 label[k] = scc;
	 	 seen[k] = true;
	 	 if (k == u)  return;
	 }
	 }
}
int dp(int u)
{
	 if (f[u] >= 0) return f[u];
	 if (mark[u] == 1) f[u] = sum[u]; else f[u] = -INF;
	 for (int v: b[u])
	   f[u] = max(f[u],dp(v)+sum[u]);
	 return f[u];
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
		}
		for (int i = 1; i <= n; i++) cin >> cost[i];
		cin >> s >> p;
		memset(seen,false,sizeof seen);
		for (int i = 1; i <= n; i++)
				if (seen[i] == false) DFS(i);
		for (int i = 1; i <= n ;i++)
		 for (int v: a[i])
			 if (label[i] != label[v]) b[label[i]].push_back(label[v]);
	  for (int i = 1; i <= p; i++)
		{
		  int x;
		  cin >> x;
			mark[label[x]] = 1;
		}
	  cout << dp(label[s]);
		return 0;

}



