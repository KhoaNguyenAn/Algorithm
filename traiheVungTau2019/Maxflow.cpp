#include <bits/stdc++.h>
#define ll long long
#define MIN(x,y) if (x>y) x=y
#define For(i,a,b) for (int i=a;i<=b;++i)
#define maxn 1005
#define inf 1000000007
using namespace std;

int n, m, s, t, c[maxn][maxn], f[maxn][maxn];
int tr[maxn];
int maxflow=0, tt=0;

void inp() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("maxflow.inp","r",stdin);
    freopen("maxflow.out","w",stdout);
}

void nhap() {
    cin >> n >> m >> s >> t;
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    int u, v;
    For(i,1,m) {
        cin >> u >> v;
        cin >> c[u][v];
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        For(i,1,n) if (c[u][i]>f[u][i] && tr[i]==0) {
            tr[i]=u;
            q.push(i);
        }
    }
}

int find_edge() {
    memset(tr,0,sizeof(tr));
    tr[s]=-1;
    bfs(s);
    return(tr[t]);
}

void addflow() {
    int delt=inf;
    int u=t;
    while (u!=s) {
        int v=tr[u];
        MIN(delt,c[v][u]-f[v][u]);
        u=v;
    }
    u=t;
    while (u!=s) {
        int v=tr[u];
        f[u][v] -= delt;
        f[v][u] += delt;
        u=v;
    }
    maxflow+=delt;
}

void solve() {
    while (find_edge()) {
        addflow();
    }
    cout << maxflow;
}

int main()
{
    inp();
    nhap();
    solve();
    return 0;
}