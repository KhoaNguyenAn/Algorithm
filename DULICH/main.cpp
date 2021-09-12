#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
vector <int> b;
int n,w[1000][1000],f[10000][10000];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            w[i][j] = x;
        }
    bool kt = false;
    for(int i=0;i<n;i++) f[i][1<<i]=1;
    for(int j=1;j<(1<<n);j++)
        for(int i=0;i<n;i++) if (f[i][j]==1)
            for(int i1=0;i1<n;i1++) if (w[i][i1]==1&&(j&(1<<i1))==0)
                {
                    f[i1][j|(1<<i1)]=1;
                    int tam = j;
                    tam = tam | (1<<i1);
                    if (tam == (1<<n)-1)
                    {
                        kt = true;
                        int i2 = i1;
                        b.push_back(i2);
                       for (int i4 = 1; i4 <= n; i4++)
                       {
                        tam = tam ^ (1 << i2);
                        for (int i3 = 0 ; i3 < n; i3++)
                            if (w[i3][i2] == 1 && f[i3][tam]==1)
                        {
                            i2 = i3;
                            b.push_back(i2);
                            break;
                        }
                       }
                    }
                    if (kt == true)
                    {
                       std::reverse(b.begin(),b.end());
                       for (int i = 0; i < b.size(); i++)
                        cout << b[i]+1 << "\n";
                    }
                }
}
