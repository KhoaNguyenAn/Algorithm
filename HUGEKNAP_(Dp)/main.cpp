#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
const int N = 1e4+1;
int a[N],b[N],f[10001][1001],s[N],t,n,m,i,j,k;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		   scanf("%d%d",&n,&m);
		   for (i = 1; i <= n; i++) scanf("%d",&a[i]);
		   for (i = 1; i <= n; i++) scanf("%d",&b[i]);
			 for (i = 1; i <= n; i++)
			  for (j = 1; j <= m; j++)
				  if (j-a[i] >= 0)
						f[i][j] = max(f[i-1][j],b[i]+f[i-1][j-a[i]]); else f[i][j] = f[i-1][j];
			  i = n, j = m ,k = 0;
			  while (i && j)
				{
						if (f[i][j]==f[i-1][j]) i--;
						else
						{
							 s[++k] = i;
							 j = j - a[i];
							 i--;
						}
				}
				printf("%d %d \n",f[n][m],k);
				for (i = k; i >= 1; i--) printf("%d ",s[i]);
				printf("\n");
	}
	return 0;
}