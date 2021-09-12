#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;
const long long inf = 1e9 + 10;
int x,n1,tam,tam1,n2,n,m,sum,h[100000],d[100000],pos[100000],heap[100000];
vector <int> a[100000],b[100000];
void pop()
{
          x = heap[1];
          h[x]=1;
          sum+=d[x];
          pos[heap[n1]] = pos[heap[1]];
          heap[1] = heap[n1];
          n1--;
          tam = 1;
          while (tam*2 <= n1)
          {
             if (tam*2 == n1)
                tam1 = tam*2;
             else
             if (d[heap[tam*2]] <= d[heap[tam*2+1]])
                  tam1 = tam*2;
             else tam1 = tam*2+1;

             if (d[heap[tam1]] < d[heap[tam]])
             {
                 swap(pos[heap[tam]],pos[heap[tam1]]);
                 swap(heap[tam],heap[tam1]);
                 tam = tam1;
             }
             else break;
          }
}

int main()
{
      cin >> n >> m;
      int u,v,k;
      for (int i = 1; i <= m; i++)
      {
         cin >> u >> v >> k;
         a[u].push_back(v);
         a[v].push_back(u);
         b[u].push_back(k);
         b[v].push_back(k);
      }
      sum = 0;
      fill(d+1,d+n+1,inf);
      fill(h+1,h+n+1,0);
      d[1] = 0;
      n1 = n;
      for (int i = 1; i <= n; i++)
        pos[i] = i;
      for (int i = 1; i <= n; i++)
        heap[i] = i;
      for (int i = 1; i <= n; i++)
      {
        pop();
        for (int j = 0; j <= int(a[x].size())-1; j++)
        if (h[a[x][j]] == 0)
        {
          int vt = pos[a[x][j]];
          d[heap[vt]] = min(d[heap[vt]],b[x][j]);
          while (vt / 2)
          {
            if (d[heap[vt/2]] > d[heap[vt]])
            {
              swap(pos[heap[vt/2]],pos[heap[vt]]);
              swap(heap[vt/2],heap[vt]);
              vt = vt / 2;
            }
            else break;
          }
        }
      }
      cout << sum;
}
