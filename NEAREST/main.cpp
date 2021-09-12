#include <iostream>
#include <bits/stdc++.h>
#define INF 9999999999
using namespace std;
const int N = 1e6+5;
int f[N],top,a[N],n,f1[N],f2[N];
struct ma
{
    int x,y;
};
ma stk[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NEAREST.INP","r",stdin);
    freopen("NEAREST.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    stk[0].x = INF;
    stk[0].y = 0;
    top = 1;
    for (int i = 1; i <= n; i++)
    {
        while (a[i] >= stk[top-1].x) top--;
        stk[top].x = a[i];
        stk[top].y = i;
        f1[i] = stk[top-1].y;
        top++;
    }

    stk[0].x = INF;
    stk[0].y = 0;
    top = 1;
    for (int i = n; i >= 1; i--)
    {
        while (a[i] >= stk[top-1].x) top--;
        stk[top].x = a[i];
        stk[top].y = i;
        f2[i] = stk[top-1].y;
        top++;
    }
    for (int i = 1; i <= n; i++) cout << f1[i] << " " << f2[i] << "\n";
    return 0;
}
