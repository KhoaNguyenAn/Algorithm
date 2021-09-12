#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define N 100000
const long double PI = 4*atan(1);
int n;
long double mid,ans,l,r,a[10005];
long double sum(long double x)
{
    long double res = 0,aa,bb,cc,cosx;
		for (int k = 1; k <= n; k++)
		{
				aa = x + a[k];
				bb = x + a[k+1];
				cc = a[k] + a[k+1];
				cosx = (aa*aa + bb*bb - cc*cc) / (2*aa*bb);
				res += acos(cosx);
		}
		return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
		a[n+1] = a[1];
		l = 0;
		r = 1e20;
		for (int i = 1; i <= 350; i++)
		{
			mid = (l+r)/2;
			ans = sum(mid);
			if ((long double)(ans - (2*PI)) >= 0.0000000000001) l = mid; else r = mid;
		}
		cout << setprecision(3) << fixed << ((l+r)/2) << endl;
    return 0;
}