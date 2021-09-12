#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BUILD.INP"
#define out "BUILD.OUT"
using namespace std;
const int N=(int)1e5+1;
const int MOD=(int)1e9+7;
const ll INF=-((ll)1e18+7);
vector<int> a[2*N];
int f[2*N];
int w[2*N];
int k;
void dfs(int u,int p,long double m)
{
    int kt=0;
    f[u]=0;
    w[u]=0;
    for(int v : a[u])
        if (v!=p)
        {
            kt=1;
            dfs(v,u,m);
            w[u]=max(w[v],w[u]);
            f[u]+=f[v];
        }
    if (kt==0)
    {
        w[u]=1;
        f[u]=1;
        //cout<<u<<" "<<f[u]<<" "<<w[u]<<"\n";
        return;
    }
    long double temp=(long double)w[u]/(long double)f[u];
    //cout<<u<<" "<<f[u]<<" "<<w[u]<<" "<<temp<<"\n";
    if (temp>=m) w[u]=f[u]+1;
    f[u]++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n>>k;
    int u,v;
    for (int i=2;i<=n;i++)
    {
        cin>>v;
        a[v].pb(i);
        a[i].pb(v);
    }
    long double l=0,r=1;
    for (int i = 1;i <= 30; i++)
    {
        long double m=(r+l) /2;
        dfs(1,0,m);

        //cout<<w[1]<<" "<<l<<" "<<r<<"\n";
         //cout<<"\n";
        if (w[1]<=k)
            r=m;
        else l=m;

    }
    //double res=((int)(l*1000000))/1000000;
    //cout<<l;
   cout << setprecision(7) << fixed << l;
}
