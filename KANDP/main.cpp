#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#define X first
#define Y second
using namespace std;
const int N = 1e3;
typedef pair <int,int> ii;
const int ii d[8] = {ii(-1,-2),ii(-1,2),ii(1,-2),ii(2,-1),ii(2,1),ii(1,2),ii(-2,-1),ii(-2,1)};
queue <ii> que;
void bfs()
{
    seen[x][y] = true;
    que.push(ii(x,y));
    while (!que.empty())
    {
        ii tmp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++)
        {
            int x = tmp.X + d[i].X;
            int y = tmp.Y + d[i].Y;
            if (seen[x][y] == false)
            {
                que.push(ii(x,y));
                seen[x][y] = true;
                d[x][y] = d[tmp.X][tmp.Y] + 1;
                if (x == x2 && y == y2) return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    cin >> a >> b;
    cin >> t;
    bfs(x,y);
    res = (x-y) / 2;
    cout << res;
    return 0;
}
