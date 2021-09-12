#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#define ll long long
#define INF 1e9+7
const int N = 1e5+4;
using namespace std;
int n,a[N],f[N],res;
stack <int> stk;
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			f[i] = 1;
			if (stk.empty())
			{
				f[i] = INF;
				stk.push(i);
			}
			else
			while (a[stk.top()] >= a[i])
			{
				f[i] = max(f[i],f[stk.top()]+1);
				stk.pop();
				if (stk.empty())
				{
					f[i] = INF;
					stk.push(i);
					break;
				}
			}
			stk.push(i);
		}
		res = 0;
		for (int i = 1; i <= n; i++) if (f[i] != INF) res = max(res,f[i]);
		cout << res;
		return 0;
}