#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GAS.INP","r",stdin);
    freopen("GAS.OUT","w",stdout);
    cin >> n >> k;
    res += a[i];
    for (int i = 1; i <= n; i++
    {
       if (a[i] > a[que[bot]])
       {
           bot++;
           que[bot] = i;
           if (que[bot]-que[top]>=k)
           {
              top++;
           }

       }
    }

    return 0;
}
