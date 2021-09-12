#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
#define INF 999999999
using namespace std;
const int N = 1e4 + 5;
typedef pair <ll,ll> ii;
#define X first
#define Y second
vector <ii> a[N];
priority_queue <ii> que;
int q,n,m,u,v,c,l,r,d[N],seen[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    for (int j = 1; j <= q; j++)
    {
        cin >> n >> m;
        for (int i = 1 ; i <= n; i++)
            a[i].clear();
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> c;
            a[u].push_back(ii(c,v));
        }
        cin >> l >> r;
        fill(d,d+n+1,INF);
        fill(seen,seen+n+1,0);
        d[l] = 0;
        que.push(ii(0,l));
        while (!que.empty())
        {
            ii x = que.top();
            que.pop();
            if (seen[x.Y] == 1) continue;
            seen[x.Y] = 1;
            for (int k = 0; k < a[x.Y].size(); k++)
            {
                ii tmp = a[x.Y][k];
                if (d[tmp.Y] > tmp.X + d[x.Y])
                {
                    d[tmp.Y] = tmp.X + d[x.Y];
                    //trace[tmp.Y] = x.Y;
                    que.push(ii(-d[tmp.Y],tmp.Y));
                }
            }
        }
        if (d[r] == INF) cout << "NO" << "\n"; else cout << d[r] << "\n";
    }
}
