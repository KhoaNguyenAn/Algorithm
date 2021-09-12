#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;
const int N = 2*(1e2 + 7);
const int mmax = 2*1000*(1e2 + 7);

int ans,f[mmax],a[N],sl,sum,n;

int main()
{
	cin >> n;
	sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	f[0] = 1;
	sl = 0;
	for (int i = 1; i <= n; i++)
	    for (int j = sum - a[i]; j >= 0; j--)
			if (f[j] > 0)
                f[j+a[i]]+=f[j];

    for (int i = 1; i <= sum; i++)
        if (f[i] > 0) sl++;
    cout << sl << "\n";
	for (int i = 1; i <= sum; i++)
		if (f[i] > 0) cout << i << " ";
}
