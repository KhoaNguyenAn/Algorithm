#include <iostream>
#include <stdio.h>
#include <math.h>
#define INF 9999999
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll stk[N],l[N],r[N],top,n,a[N],m,b[N];
int main()
{
     ios_base :: sync_with_stdio(0);
     cin.tie(0);
     freopen("RECT.INP","r",stdin);
     freopen("RECT.OUT","w",stdout);
     cin >> m >> n;
     for (int i = 1; i <=n ; i++)
     {
         cin >> a[i];
         b[i] = m - a[i];
     }
     stk[0] = 0;
     top = 0;
     for (int i = 1; i <= n ; i++)
     {
         while (a[stk[top]] >= a[i] && a[i] != 0)
             {
                top--;
             }
             l[i] = stk[top] + 1;
             top++;
             stk[top] = i;
     }

    // VE PHAI

    stk[0] = n+1;
     top = 0;
     for (int i = n; i >= 1 ; i--)
     {
         while (a[stk[top]] >= a[i] && a[i] != 0)
             {
                top--;
             }
             r[i] = stk[top] - 1;
             top++;
             stk[top] = i;
     }
     ll mmax = -INF;
     for (int i =1;i<=n;i++)
     {
        mmax = max(mmax,a[i]*abs((r[i]-l[i]+1)));
     }

     // AAAAAAAAAA
     stk[0] = 0;
     top = 0;
     for (int i = 1; i <= n ; i++)
     {
         while (b[stk[top]] >= b[i] && b[i] != 0)
             {
                top--;
             }
             l[i] = stk[top] + 1;
             top++;
             stk[top] = i;
     }

    // VE PHAI

     stk[0] = n+1;
     top = 0;
     for (int i = n; i >= 1 ; i--)
     {
         while (b[stk[top]] >= b[i] && b[i] != 0)
             {
                top--;
             }
             r[i] = stk[top] - 1;
             top++;
             stk[top] = i;
     }
     for (int i =1;i<=n;i++)
     {
        mmax = max(mmax,b[i]*abs((r[i]-l[i]+1)));
     }
     cout << mmax;
}
