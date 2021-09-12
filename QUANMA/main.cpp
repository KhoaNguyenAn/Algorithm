#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef pair <int,int> ii;
const int N = 1e3 +5;
const ii d1[8] = {ii(-1,-2),ii(-2,-1),ii(-2,1),ii(-1,2),ii(1,-2),ii(2,-1),ii(2,1),ii(1,2)};
#define X first
#define Y second
int x1,y1,n,m,d[N][N],x2,y2;
char a[N][N];
bool seen[N][N];
queue <ii> que;
void bfs()
{
    seen[x1][y1] = true;
    que.push(ii(x1,y1));
    while (!que.empty())
    {
        ii tmp = que.front();
        que.pop();
        for (int i = 0; i < 8 ; i++)
        {
            int x = tmp.X + d1[i].X;
            int y = tmp.Y + d1[i].Y;
            if (x > 0 && x <= n && y > 0 && y <= m)
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
    cin >> n >> m;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    bfs();
    cout << d[x2][y2];
}
