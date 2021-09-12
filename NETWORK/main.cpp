/*#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <bits/stdc++.h>
#define Ankhoa "NETWORK"
#define INF 999999
using namespace std;
const int N = 1e4 + 3;
vector <int> a[N];
int seen[N],n,m,u,v,ans;
void dfs(int u , int v , int cnt)
{
    seen[u] = 1;
    for (int i = 1; i <= int(a[u].size()); i++)
    if (v != a[u][i-1])
    {
       if (seen[a[u][i-1]] == 1) ans += cnt;
       if (seen[a[u][i-1]] == 0)
           dfs(a[u][i-1],u,cnt++);
       cnt--;
    }
    seen[u] = 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(Ankhoa ".INP","r",stdin);
    freopen(Ankhoa ".OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(seen,sizeof(seen),0);
    ans = 0;
    dfs(1,-1,0);
    cout << ans;
}*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int n,m,num[1000],low[1000],dfsCnt=0,brigde=0;
vector <int> g[1000];
bool lock[1000];

void enter(){
    freopen("NETWORK.INP","r",stdin);
    freopen("NETWORK.OUT","w",stdout);
    cin >> n >> m;
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(lock,0,sizeof(lock));
}

void visit(int u, int p){
    lock[u]=1;
    num[u]=low[u]=++dfsCnt;
    int child =0;
    for (int i=0;i<g[u].size();++i){
        int v=g[u][i];
        if (!lock[v]){
            visit(v,u);
            low[u]=min(low[u],low[v]);
            child++;
            if (num[u]<low[v]) brigde++;
        } else if (v!=p) low[u]=min(low[u],num[v]);
}
}
int main(){
    enter();
    visit(1,0);
    cout << m-brigde;
    return 0;
}
