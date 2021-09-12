#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
using namespace std;
const int N = 2*1e4;
int b[N],c[N],p[N],s[N];

struct mang
{
    int x;
    int y;
    int w;
};
mang a[N];

bool comp(mang a, mang b)
{
    return a.w < b.w;
}

int getroot(int x)
{
    if (p[x] == 0) return x;
    p[x] = getroot(p[x]);
    return p[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("kruskal1.txt","r",stdin);
   // freopen("kruskal2.txt","w",stdout);
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].w;
    }
    sort(a+1,a+m+1,comp);
    int sl = 0;
    fill(s,s+n,1);
    for (int i = 1; i <= m; i++)
    {
        int x1 = getroot(a[i].x);
        int y1 = getroot(a[i].y);
        if (x1 != y1)
        {
            c[i] = 1;
            sl = sl + a[i].w;
            if (s[x1] < s[y1])
            {
                p[x1] = y1;
                s[y1] += s[x1];
            }
            else
            if (s[x1] >= s[y1])
            {
                p[y1] = x1;
                s[x1] += s[y1];
            }
        }
    }
    //for (int i = 1; i <= m; i++)
    //if (c[i]==1)
    //   cout << a[i].x << ' ' << a[i].y << "\n";
    cout << sl;
}
