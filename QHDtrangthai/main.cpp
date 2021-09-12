#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
const int N = 1e4 + 7;
int snt[N],a[N],mmax,s[N],f[N][2];
void sang_era()
{
    fill(snt+1,snt+N+1,true);
    snt[1] = false;
    for (int i = 2; i <= int(sqrt(N));i++)
    if (snt[i] == true)
     {
        for (int j = 2 ; j <= int(N / i) ; j++)
            snt[i*j] = false;
        }
}

void get_array()
{
    mmax = 0;
    for (int i = 1 ; i <= N-1; i++)
    if (snt[i] == true)
    {
        mmax++;
        s[mmax] = i;
    }
}

void dp()
{
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= 1; j++)
            f[i][j] = -99999;
    f[0][0] = 0;
    f[0][1] = 0;
    for (int i = 1; i <= mmax;++i)
    {
        int k = s[i];
        for (int j = int(N); j >= k; j--)
        {
          f[j][0] = max(f[j][0],f[j-k][0]+1);
         if (j >= 2*k)
          f[j][1] = max(f[j][1],max(f[j-2*k][0]+2,f[j-k][1]+1));
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n ; i++)
        cin >> a[i];
    sang_era();
    get_array();
    dp();
    for (int i = 1 ; i <= n ; i++)
        cout << max(f[a[i]][0],f[a[i]][1]) << "\n";
}
