#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e5 +2;
const int INF = 1e9 + 7;
int  n,a[N],b[N],ans = 0;
void xuat()
{
		int l = INF;
		int r = 0;
		for (int k = 0; k < n; k++)
		if (b[k] == 1)
		{
			 l = min(l,a[k]);
			 r = max(r,a[k]);
		}
		ans = ((ans % INF) + ((r-l) % INF)) % INF;
}
void tim(int i)
{
    for(int j=0;j<=1;j++)
    {
        b[i]=j;
        if (i == (n-1)) xuat(); else tim(i+1);
		}
}
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		freopen("ATTACK.INP","r",stdin);
		freopen("ATTACK.OUT","w",stdout);
		cin >> n;
		for (int i = 0;i < n; i++) cin >> a[i];
		tim(0);
		cout << (ans + INF) % INF;
		return 0;
}