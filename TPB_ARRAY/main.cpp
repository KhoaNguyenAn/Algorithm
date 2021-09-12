#include <iostream>
#define INF 9999999
const int N = 1e5 + 7;
using namespace std;
int n,a[N],f1[N],f2[N],pre[N],suf[N],mmax = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; f1[0] = -INF; f2[n+1] = -INF ; pre[0] = -INF ; suf[n+1] = -INF;
    for (int i = 1; i <= n ; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f1[i] = max(0,f1[i-1]) + a[i];
        pre[i] = max(pre[i-1],f1[i]);
        f2[n-i+1] = max(0,f2[n-i+2])+a[n-i+1];
        suf[n-i+1] = max(suf[n-i+2],f2[n-i+1]);
    }
    for (int i = 1; i <= n; i++) mmax = max(mmax,(pre[i]+suf[i+1]));
    cout << mmax;
}
