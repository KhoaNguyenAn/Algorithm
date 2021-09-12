#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, u, v, a[N], b[N];
long long ans = 0, f[N][2];
vector<int> adj[N];

long long DFS(int u, int p = 0)
{
    long long ret = b[u];
    f[u][b[u]] = 1;
    for (int &v : adj[u])
        if (v != p)
        {
            ret += DFS(v, u);
            ret += f[u][0] * f[v][1] + f[u][1] * f[v][0];
            f[u][0] += f[v][b[u]];
            f[u][1] += f[v][1^b[u]];
        }
    return ret;
}

int main()
{
    freopen("DEBLO.inp", "r", stdin);
    freopen("DEBLO.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int bit = 21; bit >= 0; bit--)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = f[i][1] = 0;
            b[i] = (a[i] >> bit & 1);
        }
        ans += (DFS(1) << bit);
    }
    cout << ans;
}
