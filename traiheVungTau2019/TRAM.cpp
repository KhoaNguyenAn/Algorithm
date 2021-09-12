#include <bits/stdc++.h>
#include <iostream>
#define taskname "TRAM"
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
int u,v,q,res,cnt = 0,num[N],low[N],n;
map <ii,long long> c;
void DFS(int u,int p)
{
	 num[u] = low[u] = ++cnt;
	 for (auto v: a[u])
	 {
	 	 if (v != p)
			if (num[v] != 0) low[u] = min(low[u],num[v]);
			else
			{
				 DFS(v,u);
				 low[u] = min(low[u],low[v]);
				 if (low[v] >= num[v] && (c[ii(u,v)] == 0 || c[ii(v,u)] == 0)) res++;
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
		cin >> n;
		for (int i = 1; i <= n-1; i++)
		{
			 cin >> u >> v;
			 a[u].push_back(v);
			 a[v].push_back(u);
		}
		cin >> q;
		for (int i = 1; i <= q; i++)
		{
				cin >> u >> v;
				a[u].push_back(v);
				a[v].push_back(u);
				c[ii(u,v)] = 1;
				c[ii(v,u)] = 1;
		}
		DFS(1,-1);
		cout << res;
		return 0;

}



