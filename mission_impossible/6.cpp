#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#define ll unsigned long long
#define INF 1e18+5
using namespace std;
const int N = 1e6+4;
int n,d[N],p[N],s,tmp;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n ; i++) cin >> p[i] >> d[i];
	tmp = 0;
	s = p[1];
	for (int i = 1; i <= n; i++)
	{
		s = s - d[i-1];
		if (s > 0)
		{
			 s = s + p[i];
		}
		else
		{
			tmp = i;
			s = p[i];
		}
	}
	cout << --tmp;
	return 0;
}