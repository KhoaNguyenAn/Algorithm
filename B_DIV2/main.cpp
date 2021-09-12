#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
const int N = int(1e6) + 5;
using namespace std;
int b[N],c[N],i;

struct mang
{
    int x;
    int y;
};
mang a[N];

bool comp(mang a, mang b)
{
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BDIV2_inp.txt","r",stdin);
    freopen("BDIV2_out.txt","w",stdout);
    int n , m , k;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(b+1,b+n+1);
    for (int i = 1; i <= n; i++)
    {
      a[i].x = b[i] % m;
      a[i].y = i;
    }
    sort(a+1,a+n+1,comp);
    int sl = 1;
    int sl1 = 0;
    a[n+1].x = -1;
    a[n+1].y = -1;
    for (int i = 2; i <= n+1; i++)
    {
    if (a[i].x == a[i-1].x)
    {
       sl++;
    }
    else
    {
      if (sl >= k)
      {
        for (int j = i - sl ; j <= i - 1 ; j++)
          {
              sl1++;
              c[sl1] = b[a[j].y];
          }
        sort(c+1,c+sl+1);
        for (int i = 1 ; i <= k ; i++) cout << c[i] << ' ';
        exit(0);
      }
      sl = 1;
    }
    }
    cout << "KHONG DUOC THOI KEN ROI HUHU";
}
