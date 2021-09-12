#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int N = 1e6;
int bot,stk[N],a[N],res[N],n,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    stk[n+1] = -1;
    bot = 1;
    for (int i = n; i >= 1; i++)
    {
        while (a[i] < a[stk[bot-1]]) bot--;
        bot++;
        stk[bot] = i;
        if (stk[bot] - stk[1] + 1 == k) res[stk[1]] = a[stk[1]];
    }
    for (int i = 1; i <= n ; i++)
        cout << res[i];
    return 0;
}
