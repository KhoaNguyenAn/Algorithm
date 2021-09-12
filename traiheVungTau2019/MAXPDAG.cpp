#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cstring>
#define X first
#define Y second
using namespace std;
const int N = 1e5 +6;
typedef pair <int,int> ii;
vector <ii> a[N];
long long seen[N],i,n,m,u,v,mmax,dem,f[N],vt;

void dfs(int u)
{
    seen[u] = true;
    for (int v = 0; v < a[u].size(); v++)
		{
	   int k = a[u][v].X;
    if (seen[k] == true)
    {
        f[u] = max(f[k]+a[u][v].Y,f[u]);
        if (f[u] > mmax)
        {
            mmax = f[u];
            vt = u;
        }
    }
    else
    if (seen[k] == false)
    {
        f[u] = max(f[k] + a[u][v].Y,f[u]);
        dfs(k);
        f[u] = max(f[k] + a[u][v].Y,f[u]);
        if (f[u] > mmax)
        {
            mmax = f[u];
            vt = u;
        }
    }
		}
}


int main()
{
	  ios_base::sync_with_stdio(0);
	  cin.tie(0);
	  freopen("MAXPDAG.INP","r",stdin);
	  freopen("MAXPDAG.OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m ; i++)
    {
    	 int u,v,c;
        cin >> u >> v >> c;
        a[u].push_back(ii(v,c));
   }
    memset(seen,sizeof(seen),false);
    mmax = 0;
    for (int i = 1; i <= n; i++)
    if (seen[i]==false) dfs(i);
    cout << mmax;
}
