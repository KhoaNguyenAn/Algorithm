#include <iostream>
#include <math.h>
using namespace std;

int f[10000][10000],n,m;

int main()
{
    cin >> n >> m;
    f[0][0] = 1;
    int mmax = 0;
    for (int i = 1; i <= n; i++)
       for (int j = 1; j <= m; j++)
       {
         f[i][j] = f[i-1][j-1] + f[i-1][j]*(j);
         mmax = max(mmax,f[i][j]);
       }
    cout << f[n][m] << "\n";
    cout << mmax;

}
