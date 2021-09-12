#include <bits/stdc++.h>
#include <iostream>
#define taskname "DEBLO"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e6 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
vector <int> a[N];
queue <int> que;
void DFS(int u)
{
	 seen[u] = true;
	 for (int k = 0; k < a[u].size(); k++)
	 {
	 	  int v = a[u][k];
	 	  if (seen[v] == false) DFS(v);
	 	  sum = sum + f[v]^c[u];

	 }
	 f[u] =
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("taskname".INP","r",stdin);
		//freopen("taskname".OUT","w",stdout);
		cin >> n;
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> c[i];
			sum+=c[i];
			f[i] = c[i];
		}
		for (int i = 1; i <= n-1; i++)
		{
			 cin >> u >> v;
			 a[u].push_back(v);
			 a[v].push_back(u);
		}
		DFS(1);
		cout << sum;
		return 0;

}



