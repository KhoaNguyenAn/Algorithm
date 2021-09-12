#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <stdio.h>
const int N = 4e3 + 7;
int sl,a[100],f[N],c,res[N],n;
using namespace std;

int main()
{
    freopen("GANVUONG1.txt","r",stdin);
    freopen("GANVUONG2.txt","w",stdout);
    sl = 0;
    while (cin >> n)
    {
      sl++;
      a[sl] = n;
    }
    for (int i = 2; i <= 2000; i++)
      for (int j = i; j <= 2000; j++)
       {
            c = i*i+j*j;
            int tmp = sqrt(c-1);
            if (tmp * tmp == c-1) f[tmp]++;
            tmp = sqrt(c+1);
            if (tmp * tmp == c+1) f[tmp]++;
        }
   for (int i = 2; i <= 2000; i++)
      res[i] = res[i-1] + f[i];
   for (int i = 1; i <= sl; i++)
    cout << res[a[i]] << "\n";
    fclose(stdin);
    fclose(stdout);
}
