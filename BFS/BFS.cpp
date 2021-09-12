#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;
vector<int>a[int(1e3)+6];
int seen[100],que[100];

int main()
{
    int u ,v ,n ,m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
   memset(seen,sizeof(seen),false);
   int sl = 0;
   for (int k = 1 ; k <= n; k++)
   if (seen[k] == false)
   {
    sl++;
    que[0] = 0;
    int top = 1;
    int bot = 1;
    que[top] = k;
    seen[k] = true;
    while (top >= bot)
    {
        int x = que[bot];
        bot++;
        cout << x << ' ';
        for (int i = 1; i <= int(a[x].size()); i++)
            if (seen[a[x][i-1]] == false)
            {
               seen[a[x][i-1]] = true;
               top++;
               que[top] = a[x][i-1];
            }
     }
     cout << "\n";
   }
   cout << sl;
}
