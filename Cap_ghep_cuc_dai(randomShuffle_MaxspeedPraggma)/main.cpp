//Dai Ca Di Hoc
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define Task "assign"

using namespace std;

int n, m, res = 0, cur;
vector <int> ke[maxn];
int MatchX[maxn], Used[maxn],id[maxn];

bool DFS(int u){
    if (Used[u] == cur) return 0;
    Used[u] = cur;
    for (int v : ke[u])
        if (MatchX[v] == 0|| DFS(MatchX[v])){
            MatchX[v] = u;
            return 1;
        }
    return 0;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n;
    int u,v,i;
    while (cin >> u >> v) ke[u].PB(v);
    for (int i = 1; i <= m; i++) id[i] = i;
    random_shuffle(id+1,id+m+1);
    for (cur = m; cur >= 1; --cur)
		{
			  //cur = id[i];
        res += DFS(cur);
		}
    cout << res << "\n";
    for (i = 1; i <= n; ++i) cout << MatchX[i] << " ";
    return 0;
}
