#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstring>
using namespace std;
const int N = round(1e6)+7;
int que[2*N],a[N],n,m;
bool seen[N];
int main()
{
    freopen("BFS1.txt","r",stdin);
    freopen("BFS2.txt","w",stdout);
    cin >> n >> m;
    string st;
    int index,index1,sl,x1,y1;
    sl = 0;
    int dx[8] = {-1,1,0,0,-1,-1,1,1};
    int dy[8] = {0,0,-1,1,-1,1,-1,1};
    memset(seen,sizeof(seen),false);
    for (int i = 1; i <= n; i++)
    {
        cin >> st;
        for (int j = 0; j <= m-1; j++)
        {
            index = (i*m)+j;
            a[index] = st[j] - '0';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m-1; j++)
        {
            index = (i*m)+j;
            if (a[index] == 1 && seen[index] == false)
            {
                sl++;
                que[0] = 0;
                int top = 1;
                int bot = 1;
                que[top] = index;
                seen[index] = true;
                while (top >= bot)
                {
                    int tam = que[bot];
                    bot++;
                    x1 = tam / m;
                    y1 = tam % m;
                    for (int l = 0; l <=7;l++)
                      if (x1 + dx[l] >= 1 && y1+dy[l] >=0 && x1 + dx[l] <= n && y1+dy[l] <= m - 1 )
                      {
                        index1 = (x1 + dx[l])*m + (y1 + dy[l]);
                        if (seen[index1] == false && a[index1] == 1)
                        {
                          seen[index1] = true;
                          top++;
                          que[top] = index1;
                        }
                      }
                }
            }
        }
    }
    cout << sl;
}
