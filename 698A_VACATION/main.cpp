#include <iostream>
#include <math.h>
using namespace std;
int n,f[100000][3],a[100000],mmax;
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
        f[0][0] = 0;
        f[0][1] = 0;
        f[0][2] = 0;
		for (int i = 1; i <= n ; i++)
		{
			mmax = max(f[i-1][0],f[i-1][1]);
			mmax = max(mmax,f[i-1][2]);
			f[i][0] = mmax;
			if (a[i] == 1 || a[i] == 3)
				f[i][1] = max(f[i-1][2],f[i-1][0]) + 1;
            if (a[i] == 2 || a[i] == 3)
                f[i][2] = max(f[i-1][1],f[i-1][0]) + 1;
       }
       mmax = max(f[n][0],f[n][1]);
       mmax = max(mmax,f[n][2]);
       cout << n - mmax;
}

