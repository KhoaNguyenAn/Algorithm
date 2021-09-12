#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
const int N = int(1e3) + 10;
using namespace std;
int n,f[N][N],a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
       cin >> a[i];
    for (int i = n ; i >= 1; i--)
      for (int j = i+1; j <= n; j++)
        {
            if (a[i] == a[j]) f[i][j] = f[i+1][j-1];
            else f[i][j] = min(f[i+1][j],f[i][j-1]) + 1;
        }
    cout << f[1][n];
}
