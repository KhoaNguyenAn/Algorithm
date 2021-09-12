/*#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define X first
#define Y second
#define ll long long
#define INF 999999999
using namespace std;
const int N = 1e2+5;

struct mang
{
    int x,y,z;
};
vector <mang> a[N];
priority_queue <ii,vector <int> ,greater<int> > que;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("AIRLINES.INP","r",stdin);
    freopen("AIRLINES.OUT","w",stdout);
    cin >> n >> m >> c >> a >> s >> f;
    for (int i = 1; i <= m ; i++)
    {
        string num;
        getline(cin,num);
        stringstream stream(num);
        int j = 0; int tmp;
        while (stream >> tmp) b[j++] = tmp;
        tmp = b[1];
        for (int jj = 2; jj <= j; jj++)
        {
            a[tmp].push_back(iii)
        }
    }
    fill(d+1,d+n1+1,INF);
    fill(seen+1,seen+n1+1,INF);
    d[s] = 0;
    while (!que.empty())
    {
        ii x = que.top();
        que.pop();
        if (seen[x.Y]== 1) continue;
        seen[x.Y] = 1;
        for (int i = 1; i <= a[x.Y].size();i++)
        {
            mang tmp = a[x.y][i-1];

            trace[tmp.y] = x.Y;
            que.push();
        }
    }
    cout << d[f];
    return 0;
}
*/
