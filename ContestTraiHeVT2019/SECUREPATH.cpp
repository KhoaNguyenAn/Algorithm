#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;

ll n, m, res = 0, CC = 0, CCC = 0, dem = 0, num[N], low[N], B[N], D[N], C[N];

vector <ll> a[N];
vector <ii> V;
map <ii, bool> M;

void DFS (const ll &u, const ll &p) {
    num[u] = ++dem;
    low[u] = num[u];
    for (auto v : a[u]) if (v != p) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v]) {
                M[ii(u, v)] = M[ii(v, u)] = true;
                V.push_back(ii(u, v));
            }
        }
    }
}

void DFS1(const ll &u) {
    B[u] = CC;
    for (auto v : a[u]) if (B[v] == 0 && M[ii(u, v)] == false) DFS1(v);
}

void DFS2(const ll &u) {
    C[u] = CCC;
    for (auto v : a[u]) if (C[v] == 0) DFS2(v);
}

int main() {
    freopen("SECUREPATH.INP", "r", stdin);
    freopen("SECUREPATH.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while (m--) {
        ll x, y; cin >> x >> y;
        a[x].push_back(y); a[y].push_back(x);
    }
    //********************
    CCC = 0;
    memset(C, 0, sizeof C);
    for (ll i = 1; i <= n; i++) if (C[i] == 0) {
        CCC++;
        DFS2(i);
    }
    memset(num, 0, sizeof num);
    for (ll i = 1; i <= n; i++) if (!num[i]) DFS(i, i);
    memset(B, 0, sizeof B);
    CC = 0;
    for (ll i = 1; i <= n; i++) if (B[i] == 0) {
        CC++;
        DFS1(i);
    }
    memset(D, 0, sizeof D);
    for (auto it : V) {
        D[B[it.first]]++;
        D[B[it.second]]++;
    }
    //********************
    for (ll i = 1; i <= CC; i++) if (D[i] == 1) res++;
    res -= CCC;
    res += (CCC - 1) * 2;
    cout << res;
    return 0;
}