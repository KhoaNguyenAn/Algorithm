#include <bits/stdc++.h>
#include <iostream>
#define taskname "NKLEAGUE"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1000+5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
int n,seen[N];
deque <int> res;
vector <int> a[N];
string st;
void DFS(int u)
{
	 seen[u] = 1;
	 for (int k = 0; k < a[u].size(); k++)
	 {
	 	 int v = a[u][k];
	 	 if (seen[v] == 2) continue;
	 	 if (seen[v] == 1) continue;
	 	 DFS(v);
	 }
	 seen[u] = 2;
	 res.push_front(u);
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("taskname".INP","r",stdin);
		//freopen("taskname".OUT","w",stdout);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> st;
			for (int j = 1; j <= n; j++)
						if (st[j-1] == '1') a[i].push_back(j);
		}
		memset(seen,0,sizeof seen);
		for (int i = 1; i <= n; i++)
		if (seen[i] == 0) DFS(i);
		for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
		return 0;

}



