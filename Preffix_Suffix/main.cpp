#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin << a[i];
        b[i] = b[i-1] + a[i];
    }
    for (int i = k; i <= n; i++)
       c[i] = b[i] - b[i-k];
    for (int i = n - k; i >= 1; i++)
       d[i] = b[i] - b[i+k];
    for (int i = k + 1; i <= n; i++)
        if (c[i] > f[i-1) f[i] = c[i] else f[i] = f[i-1];
    for (int i = n - k; i >= 1; i++)
        if (d[i] > e[i+1]) e[i] = d[i] else e[i] = e[i-1];
    for (int i = k ; i <= n)
}
