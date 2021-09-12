#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#define X first
#define Y second
using namespace std;
typedef pair <int,int> ii;
queue <ii> que;
ii comeback, trace[550][5500];
int d,s,f[550][5500],last[550][5500];
bool seen[550][5500];
string ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> d >> s;
    que.push(ii(0,0));
    memset(seen,false,sizeof seen);
    seen[0][0] = true;
    f[0][0] = 1;
		while (!que.empty())
		{
			ii tmp = que.front();
			que.pop();
			for (int i = 0; i <= 9; i++)
			{
					int iii = (tmp.X*10+i) % d;
					int jjj = (tmp.Y+i);
					if (seen[iii][jjj]==false && jjj <= s)
					{
						 f[iii][jjj] = f[tmp.X][tmp.Y] + 1;
						 trace[iii][jjj] = tmp;
						 last[iii][jjj] = i;
						 que.push(ii(iii,jjj));
						 seen[iii][jjj] = true;
					}
			}
		}
		if (f[0][s]==0)
		{
			  cout << -1;
			  return 0;
		}
		comeback = ii(0,s);
		for (int i = 1; i <= f[0][s]-1; i++)
		{
				ans = ans + char(last[comeback.X][comeback.Y]+'0');
				comeback = trace[comeback.X][comeback.Y];
		}
		reverse(ans.begin(),ans.end());
		cout << ans;
    return 0;
}
