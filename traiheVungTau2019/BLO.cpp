#include <bits/stdc++.h>
using namespace std;
int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int ans = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        ans = ans * 10 + c - '0';
    return ans;
}
void WriteInt(int64_t x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}
const int maxn=2e5+5;
vector<int> adj[maxn];
int num[maxn],low[maxn],nChild[maxn];
int64_t res[maxn];
int n,m,cnt;
void DFS(int u,int p=-1)
{
    num[u]=low[u]=++cnt;
    nChild[u]=1;
    bool CriticalNode=false;
    for (int v:adj[u]) if (v!=p){
        if (num[v])
            low[u]=min(low[u],num[v]);
        else {
            DFS(v,u);
            nChild[u]+=nChild[v];
            res[u]+=1ll*nChild[v]*(n-nChild[v]);
            low[u]=min(low[u],low[v]);
            if (low[v]>=num[u])
                CriticalNode=1;
        }
    }
    res[u]+=n-1;
    res[u]+=1ll*nChild[u]*(n-nChild[u]);
    if (!CriticalNode)
        res[u]=2*(n-1);
}
int main()
{
    freopen("BLO.inp","r",stdin);
    #ifndef meomeomeooooo
        freopen("BLO.out","w",stdout);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    n=ReadInt(); m=ReadInt();
    for (int i=1; i<=m; ++i) {
        int u=ReadInt(),v=ReadInt();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int i=1; i<=n; ++i) {
        WriteInt(res[i]);
        putchar('\n');
    }
    return 0;
}
