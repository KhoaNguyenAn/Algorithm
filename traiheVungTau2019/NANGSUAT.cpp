#include <bits/stdc++.h>
#include <iostream>
#define taskname "NANGSUAT"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 200 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
int n,res,mmax = -INF,Used[N],matchX[N],matchY[N],ok,match_ans[N],L,R,mid,cur,c[N][N];
queue <int> que;
bool DFS(int u)
{
	 if (Used[u] == cur) return 0;
	 Used[u] = cur;
	 for (int v = 1; v <= n; v++)
	 if ((c[u][v] >= mid) &&(matchX[v] == 0 || DFS(matchX[v])))
	 {
	 	  matchX[v] = u;
	 	  matchY[u] = v;
	 	  return 1;
	 }
	 return 0;
}
bool check()
{
	memset(matchX,0,sizeof matchX);
	memset(Used,0,sizeof Used);
	int res = 0;
	for (cur = 1; cur <= n; cur++)
		 res+=DFS(cur);
	return (res == n);
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n;
		L = INF;
		R = -INF;
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++)
				{
						cin >> c[i][j];
						R = max(R,c[i][j]);
						L = min(L,c[i][j]);
				}
		while (L <= R)
		{
			 mid = (L+R) >> 1;
			 if (check()== true)
			 {
					L = mid + 1;
					for (int i = 1; i <= n; i++) match_ans[i] = matchY[i];
			 }
				else R = mid-1;
		}
		ok = INF;
		for (int i = 1; i <= n; i++) ok = min(ok,c[i][match_ans[i]]);
		cout << ok << endl;
		for (int i = 1; i <= n; i++) cout << match_ans[i] << endl;
		return 0;
}



