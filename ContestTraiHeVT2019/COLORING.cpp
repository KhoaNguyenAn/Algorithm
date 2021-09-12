#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll maxn = 2e3+5;
const ll maxint = 1e9+7;

multiset <ll> S[maxn][maxn];
ll n, m;
ll a[maxn][maxn];

ll mx[] = {0, -1, 0, 1};
ll my[] = {1, 0, -1, 0};

ll DFS (ll x, ll y, ll p, ll q)
{
    ll Count = 0;
    deque <ii> Q;
    Q.clear();
    Q.push_back(make_pair(x, y));
    while (!Q.empty())
    {
        ll x = Q.back().first;
        ll y = Q.back().second;
        Q.pop_back();
        Count++;
        for (ll i=0; i<=3; i++)
        {
            ll xx = x + mx[i];
            ll yy = y + my[i];
            if (xx>=1 && xx<=n && yy>=1 && yy<=m)
                {
                    if (a[xx][yy]==p)
                    {
                        if (S[xx][yy].count(q)) continue;
                        S[xx][yy].insert(q);
                        Q.push_back(make_pair(xx, yy));
                    }
                    if (a[xx][yy]==q)
                    {
                        if (S[xx][yy].count(p)) continue;
                        S[xx][yy].insert(p);
                        Q.push_back(make_pair(xx, yy));
                    }
                }
        }
    }
    return(Count);
}

int main()
{
    //freopen("TWOFL.INP", "r", stdin);
    //freopen("TWOFL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d%d", &n, &m);
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
            scanf("%d", &a[i][j]);
    //**************
    ll res = 0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
    {
        S[i][j].insert(-1);
        res = max(res, DFS(i, j, a[i][j], -1));
        for (ll k=0; k<=3; k++)
        {
            ll x = i + mx[k];
            ll y = j + my[k];
            if (x>=1 && x<=n && y>=1 && y<=m && a[x][y]!=a[i][j])
                if (!S[i][j].count(a[x][y]))
                    {
                        S[i][j].insert(a[x][y]);
                        res = max(res, DFS(i, j, a[i][j], a[x][y]));
                    }
        }
    }
    //**************
    printf("%d", res);
}