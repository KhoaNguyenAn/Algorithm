#include <bits/stdc++.h>
#include <iostream>
#define taskname "1144F"
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
/***
		 To break barriers
		 To reach for the star
		 To make the unknown known
		 To make the ordinary extraodinary
		 To make the greater greater
***/
vector <ii> edge;
vector <int> a[N];
int u,v,n,m,temp[N];
bool slt;
void DFS(int u,int c)
{
	  temp[u] = c;
	  for (int k = 0; k < a[u].size(); k++)
		{
			 int v = a[u][k];
			 if (temp[v] == -1) DFS(v,c^1);
			 else
			 {
			 	  if (temp[u] == temp[v]) slt = false;
			 }
		}
}
inline void solve()
{
		slt = true;
		memset(temp,-1,sizeof temp);
		DFS(1,0);
		if (slt == false)
		{
			 cout << "NO";
			 return;
		}
		cout << "YES" << endl;
		for (int i = 1; i <= m; i++)
		if (temp[edge[i].X] == 1) cout << 1; else cout << 0;
}
inline void init()
{
    cin >> n >> m;
    edge.push_back(ii(-1,-1));
    for (int i = 1; i <= m; i++)
		{
			 cin >> u >> v;
			 a[u].push_back(v);
			 a[v].push_back(u);
			 edge.push_back(ii(u,v));
		}
}
/************** [MAIN] **************/
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		init();
		solve();
		return 0;

}



/**********************************************
*|	 Code written by Kaze1402	||*
*||	NguyenAnKhoa, #GD high school HCM_VN	 ||*
**********************************************/
/** _"You said you worked hard? Well, maybe you need to work a little longer"_**/



