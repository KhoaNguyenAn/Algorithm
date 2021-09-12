#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#define ll long long
#define INF 1e9+7
const int N = 1e6+4;
using namespace std;
unsigned long long n,res,x,sl,ans[N];
bool kt;
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
				cin >> x;
				if ((1 << int(log2(x))) == x)
				{
					 res = int(log2(x)) % 5;
					 ans[i] = res;
				}
				else
				{
						sl = 0; kt = false;
						while (x >= 2)
						{
							if ((1 << int(log2(x))) == x)
							{
								res = (int(log2(x)) + sl)%5;
								ans[i] = res;
								kt = true; break;
							}
							else
							{
								 sl++;
								 x = x - (1 << int(log2(x)));
							}
						}
						if (kt != true)
						{
						res = sl % 5;
						ans[i] = res;
						}
				}
		}
		for (int i = 1; i <= n; i++)
		if (ans[i] == 0) cout << "U \n";
		else
		if (ans[i] == 1) cout << "Wolfris \n";
		else
		if (ans[i] == 2) cout << "Goldenalize \n";
		else
		if (ans[i] == 3) cout << "Qambitions \n";
		else
		if (ans[i] == 4) cout << "Illusionary \n";
		return 0;
}