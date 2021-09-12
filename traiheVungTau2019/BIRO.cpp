#include <bits/stdc++.h>
#include <iostream>
#define taskname "BIRO"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e2 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,f[N],x,tmp = -1,h[N];
bool seen[N];
vector <int> a[N];
void DFS(int u)
{
	  seen[u] = true;
	  for (int k = 0; k < a[u].size(); k++)
		{
			 int v = a[u][k];
			 if (seen[v] == false)
			 {
			 	h[v] = h[u] + 1;
			 	tmp = max(tmp,h[v]);
				DFS(v);
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
    for (int i = 2; i <= n; i++)
		{
			 cin >> x;
			 a[x].push_back(i);
		}
		memset(seen,false,sizeof seen);
		h[1] = 1;
		DFS(1);
		for (int i = 1; i <= n; i++)
			cout << (tmp-h[i]+1)*a[i].size()+1 << " ";
		return 0;
}



