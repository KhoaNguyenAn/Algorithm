#include <iostream>
#include <stdio.h>
#include <math.h>

#define ll long long
using namespace std;

const int mmax = 1e3 + 7 ;

int f[mmax][3],a[mmax],b[mmax],u,n,v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n ; i++)
       cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)
    {
    	if (b[i] == 1)
    	{
    		f[i][1] = max(f[i-1][1],f[i-1][2]+a[i]);
    		f[i][2] = f[i-1][2];
    	}
    	if (b[i] == 2)
    	{
            f[i][2] = max(f[i-1][2],f[i-1][1]+a[i]);
    		f[i][1] = f[i-1][1];
    	}
    }
    int ans =  0;
    for (int i = 1; i <= n; i++)
    {
    	ans = max(ans,f[i][1]);
    	ans = max(ans,f[i][2]);
    }
    cout << ans;
}
