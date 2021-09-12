#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
const int N = 2*1e5+6;
unsigned long long n,m,a[N],ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (1)
		{
			unsigned long long tmp = m,dem = 0,sum = 0;
			for (int i = 1; i <= n; i++)
				if (tmp >= a[i]) dem++,tmp-=a[i],sum+=a[i];
			if (dem == 0) break;
			ans+= dem*(m / sum);
			m = m % sum;
		}
		cout << ans;
    return 0;
}
