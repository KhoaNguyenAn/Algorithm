#include <bits/stdc++.h>
#include <iostream>
#define taskname "NET"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e5 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
vector <int> a[N];
int num[N],low[N],m,cnt = 0,mark[N][2],f[N][2],res = 0,u,v,n,k,l;
void DFS(int u,int p)
{
	 num[u] = low[u] = ++cnt;
	 f[u][0] = mark[u][0];
	 f[u][1] = mark[u][1];
	 for (int v:a[u])
	 if (v != p)
	 {
	 	 if (num[v] != 0) low[u] = min(low[u],num[v]);
	 	 else
		 {
		 	  DFS(v,u);
		 	  f[u][0]+=f[v][0];
		 	  f[u][1]+=f[v][1];
		 	  low[u] = min(low[u],low[v]);
		 	  if (low[v] >= num[v]) // u and v la cau
if (f[v][0] == 0 || f[v][1] == 0 ||f[v][0] == k || f[v][1] == l)
					 res++;
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
		cin >> n >> m >> k >> l;
		for (int i = 1; i <= k; i++)
		{
			 cin >> u;
			 mark[u][0] = 1;
		}
		for (int i = 1; i <= l; i++)
		{
			 cin >> u;
			 mark[u][1] = 1;
		}
		for (int i = 1; i <= m; i++)
		{
			 cin >> u >> v;
			 a[u].push_back(v);
			 a[v].push_back(u);
		}
		DFS(1,0);
		cout << res;
		return 0;

}



