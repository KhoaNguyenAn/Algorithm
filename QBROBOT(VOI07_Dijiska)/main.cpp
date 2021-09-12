//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "NAME"
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e6 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,m,k,u,v,d[N];
vector<int>a[N];
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n >> m >> k;
		while (m--)
		{
			 cin >> u >> v;
			 a[u].push_back(v);
			 a[v].push_back(u);
			 d[u]++; d[v]++;
		}
		multiset <ii> s; s.clear();
		for (int i = 1; i <= n; i++) s.insert(ii(d[i], i));
		while (!s.empty())
		{
			 ii t = *s.begin(); s.erase(s.begin());
			int bac = t.first, id = t.second;
			if (bac>=k)
			{
			  s.insert(t);
				break;
			}
			for (auto v: a[id])
			{
				if (s.find(ii(d[v],v)) != s.end())
				{
					 s.erase(s.find(ii(d[v],v)));
					 s.insert(ii(d[v]-1,v));
					 d[v]--;
				}
			}
		}
		cout << s.size() << endl;
		for (auto v: s)
			cout << v.second << " ";
		return 0;
}
/**Code written by AnkhoaGD**/


