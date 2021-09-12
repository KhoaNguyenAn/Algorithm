#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
typedef pair <ll,ll> ii;
#define INF 999999999999
#define X first
#define Y second
const int N = 1e5 + 3;
vector <ii> a[N];
vector <int> ans;
ll n,m,d[N],u,v,q,trace[N],seen[N];
priority_queue <ii> que;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> q;
        a[u].push_back(ii(v,q));
        a[v].push_back(ii(u,q));
    }
    fill(d,d+n+1,INF);
    que.push(ii(0,1));
    d[1] = 0;
    while (!que.empty())
    {
        ii x = que.top();
        que.pop();
        if (seen[x.Y] == 1) continue;
        seen[x.Y] = 1;
        for (int i = 1; i <= a[x.Y].size(); i++)
        {
            ii tam = a[x.Y][i-1];
            if (d[tam.X] > tam.Y + d[x.Y])
            {
                d[tam.X] = tam.Y + d[x.Y];
                que.push(ii(-d[tam.X],tam.X));
                trace[tam.X] = x.Y;
            }
        }
    }
    if (d[n] == INF)
    {
        cout << -1;
        return 0;
    }
    ans.push_back(n);
    int tmp = n;
    while (tmp != 1)
    {
        ans.push_back(trace[tmp]);
        tmp = trace[tmp];
    }
    reverse(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
