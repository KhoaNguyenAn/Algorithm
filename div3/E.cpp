#include <bits/stdc++.h>

using namespace std;

typedef int32_t ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e5 + 5;
const ll INF = 1e9 + 7;
const ll LOG = 17;

struct data {
    ll v, c1, c2;
};

ll T, n, Q, d[N], spT[N][LOG + 1], C[N], d1[N];

vector <data> a[N];

inline void DFS(const ll &u, const ll &p, const ll &cc, const ll &ccc) {
    d[u] = cc; d1[u] = ccc;
    spT[u][0] = p;
    for (auto v : a[u]) if (v.v != p) {
        C[v.v] = C[u] + 1;
        DFS(v.v, u, cc + v.c1, ccc + v.c2);
    }
}

inline ll LCA(ll x, ll y) {
    for (ll k = LOG; k >= 0; k--)
        if (C[spT[x][k]] >= C[y]) x = spT[x][k];
    for (ll k = LOG; k >= 0; k--)
        if (C[spT[y][k]] >= C[x]) y = spT[y][k];
    for (ll k = LOG; k >= 0; k--)
        if (spT[x][k] != spT[y][k])
            x = spT[x][k], y = spT[y][k];
    while (x != y)
        x = spT[x][0], y = spT[y][0];
    return x;
}

int main() {
    //freopen("249748M.INP", "r", stdin);
    //freopen("249748M.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=1;i<=n;i++) a[i].clear();
        ll G = 0;
        for (ll i = 1; i < n; i++) {
            ll x, y, c1, c2; cin >> x >> y >> c1 >> c2;
            a[x].push_back( { y, c1, c2 } );
            a[y].push_back( { x, c2, c1 } );
            G += c1 + c2;
        }
        //********************
        C[1] = 1;
        DFS(1, 1, 0, 0);
        for (ll k = 1; k <= LOG; k++)
        for (ll i = 1; i <= n; i++)
            spT[i][k] = spT[spT[i][k - 1]][k - 1];
        //********************
        cin >> Q;
        while (Q--) {
            ll x, y; cin >> x >> y;
            ll lca=LCA(x,y);
            ll t = d[x] - d[lca] + d1[y] - d1[lca];
            cout << G - t << '\n';
        }
        for (int i = 1; i <= n; i++) a[i].clear();
    }
    return 0;
}