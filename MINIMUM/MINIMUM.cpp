#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int N = 1e6;
int dqueue[N],a[N],res[N],n,k,top,bot,j,i;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MINIMUM.INP","r",stdin);
    freopen("MINIMUM.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
        top = 1;
        bot = 0;
        i = 0;
        j = 1;
        dqueue[0] = 0;
        a[0] = -1;
        while (i <= n)
        {
            i++;
            if (a[i] > a[dqueue[bot]])
            {
                bot++;
                dqueue[bot] = i;
                if (dqueue[bot] - dqueue[top] >= k)
                {
                top++;
                }
            }
            else
            {
                while (top <= bot && a[i] <= a[dqueue[bot]])
                {
                    bot--;
                }
                bot++;
                dqueue[bot] = i;
                if (dqueue[bot] - dqueue[top] >= k)
                {
                top++;
                }
            }
            if (i-j+1 == k)
            {
                res[j] = a[dqueue[top]];
                j++;
            }
        }
    for (int i = 1; i <= n-k+1 ; i++)
        cout << res[i] << endl;
    return 0;
}
