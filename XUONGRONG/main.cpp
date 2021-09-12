#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <bits/stdc++.h>
#define INF 999999
using namespace std;
const int N = 1e4 + 3;
vector <int> a[N];
int seen[N],n,m,u,v,ans;
void dfs(int u , int v)
{
    seen[u] = 1;
    for (int i = 1; i <= int(a[u].size()); i++)
    if (v != a[u][i-1])
    {
       if (seen[a[u][i-1]] == 1) ans++;
       if (seen[a[u][i-1]] == 0) dfs(a[u][i-1],u);
    }
    seen[u] = 2;
}
int main()
{
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(seen,sizeof(seen),0);
    ans = 0;
    dfs(1,-1);
    cout << ans;
}
