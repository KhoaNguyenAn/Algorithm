#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define X first
#define Y second
const int N = 1e2 + 3;
#define INF 999999
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
priority_queue <iii> que;
vector <ii> d3;
int a[N][N],seen[N][N],d[N][N],n,m,tmp1,tmp2,trace1[N][N],trace2[N][N],ans;
const ii d1[4] = {ii(1,0),ii(-1,0),ii(0,-1),ii(0,1)};
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
         {
           cin >> a[i][j];
           d[i][j] = INF;
           seen[i][j] = false;
         }
     for (int i = 1; i <= n; i++)
     {
         d[i][1] = a[i][1];
         que.push(iii(-a[i][1],ii(i,1)));
     }
     while (!que.empty())
     {
         iii x = que.top();
         que.pop();
         if (seen[x.Y.X][x.Y.Y]==true) continue;
         seen[x.Y.X][x.Y.Y] = true;
         for (int i = 0; i < 4; i++)
         {
            int idx = x.Y.X + d1[i].X;
            int idy = x.Y.Y + d1[i].Y;
            if (d[idx][idy] > a[idx][idy] + d[x.Y.X][x.Y.Y])
            {
                d[idx][idy] = a[idx][idy] + d[x.Y.X][x.Y.Y];
                trace1[idx][idy] = x.Y.X;
                trace2[idx][idy] = x.Y.Y;
                que.push(iii(-d[idx][idy],ii(idx,idy)));
            }
         }
     }
     int mmin = 9999999;
     for (int i = 1; i <= n; i++)
     {
        if (d[i][m] < mmin)
        {
            ans = i;
            mmin = d[i][m];
        }
     }
    cout << mmin << "\n";
    d3.push_back(ii(ans,m));
    tmp1 = trace1[ans][m];
    tmp2 = trace2[ans][m];
    while (tmp2 != 1)
    {
        int tam = tmp1;
        d3.push_back(ii(tmp1,tmp2));
        tmp1 = trace1[tmp1][tmp2];
        tmp2 = trace2[tam][tmp2];
    }
    d3.push_back(ii(tmp1,tmp2));
    reverse(d3.begin(),d3.end());
    for (int i = 0; i < d3.size(); i++)
        cout << d3[i].X << " " << d3[i].Y << "\n";
}
