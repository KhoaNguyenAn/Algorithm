#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int A[N],M[N][300],l,r,n,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RMQ.INP","r",stdin);
    freopen("RMQ.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
     cin >> A[i];
    for (int i = 0; i < n; i++)
    M[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
    for (int i = 0; i + (1 << j) - 1 < n; i++)
      if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
        M[i][j] = M[i][j - 1];
      else
        M[i][j] = M[i + (1 << (j - 1))][j - 1];
    for (int i = 1; i <=k ; i++)
    {
        cin >> l >> r; l--; r--;
        int tmp = floor(log2(r-l+1));
        cout << min(A[M[l][tmp]],A[M[r-(1 << tmp)+1][tmp]]) << endl;
    }
    return 0;
}
