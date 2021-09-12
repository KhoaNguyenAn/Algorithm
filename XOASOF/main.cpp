#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int f[100],n,a[100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n ; i++)
        cin >> a[i];
    fill(f+1,f+n+1,INT_MAX);
    for (int i = 1; i <= n; i++)
        for (int j = 1 ; j <= 3 ; j++)
           f[i] = min(f[i],f[i-j]+a[i]);
    cout << *min_element(f+n-2,f+n);
}
