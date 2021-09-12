#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;
pair <int,int>ii;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> l >> r >> x >> y;
    for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin >> xx;
				if (xx == ".") f[i][j] = 3; else f[i][j] = 4;
			}
		deque <ii> deg;
		deg.push_back(ii(x,y));
		while (!deg.empty())
		{
			 ii tmp = deg.front();
			 deg.pop_front();
			 for (int i = 1; i <= 4; i++)
			 {
					if (f[i+1][j] == 3)
					{
						ans[i+1][j] += 1;
						deg.push_front(ii(i+1,j));
					}
					if (f[i-1][j] == 3)
					{
						ans[i-1][j] += 1;
						deg.push_front(ii(i-1,j));
					}
					if (f[i][j+1] == 3)	deg.push_back(ii(i,j+1));
					if (f[i][j-1] == 3) deg.push_back(ii(i,j-1));
			 }
		}

}
