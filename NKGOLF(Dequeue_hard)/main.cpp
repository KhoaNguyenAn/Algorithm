#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 2;
long long h[N],a[N][N],m,n,top,L[N],R[N],res,que[N],tmp;
bool b[N][N];
int main()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= m; j++) cin >> a[i][j];
		for (int i = 1; i <= n-1; i++)
		  for (int j = 1; j <= m-1;j++)
		    b[i][j] = ((a[i][j] <= a[i][j+1]) && (a[i][j] <= a[i+1][j]) &&
									(a[i+1][j+1] >= a[i+1][j]) && (a[i+1][j+1] >= a[i][j+1]));
		 res = 1;
		 for (int i = 1; i <= n; i++)
		 {
		 	  tmp = 1;
		 	  for (int j = 2; j <= m; j++)
					if (a[i][j] >= a[i][j-1])
					{
						tmp++;
						res = max(res,tmp);
					}
					else tmp = 1;
		 }
		 for (int i = 1; i <= m; i++)
		 {
				tmp = 1;
				for (int j = 2; j <= n; j++)
				 if (a[j][i] >= a[j-1][i])
					{
						tmp++;
						res = max(res,tmp);
					}
					else tmp = 1;
		 }
		 memset(h,0,sizeof(h));
		 memset(L,0,sizeof(L));
		 memset(R,0,sizeof(R));
     for (int i = 1; i <= n-1; i++)
		 {
		 	 for (int j = 1; j <= m-1; j++)
				if (b[i][j]) h[j]++; else h[j] = 0;
			 top = 0;
			 que[0] = 0;
			 for (int j = 1; j <= m-1; j++)
			 {
				while (top && h[que[top]]>= h[j]) R[que[top--]] = j-1;
				L[j] = que[top] + 1;
				que[++top] = j;
			 }
			 while (top) R[que[top--]] = m-1;
			 for (int j = 1; j <= m-1; j++) if (h[j]>0) res = max(res,(h[j]+1)*(R[j]-L[j]+2));
		 }
		 cout << res;
		 return 0;
}
