///...................................*****.................................................///
///        Author :  Ankhoa                                                                 ///
///                  Department of Computer Science                                         ///
///                  & Algorithm                                                            ///
///                  Gia Dinh high school , Vietnam.                                        ///
///...................................*****.................................................///
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
#include <sstream>
#include <set>
#include <list>
#include <map>
#include <stack>
using namespace std;
/*....................................Values................................................*/
#define       PI                   acos(-1)
#define       M                    1000000007
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define base 27ll
#define MAXN 1000010
#define MOD 1000000007ll
const int N = 1e5+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
/*....................................Functions.............................................*/
#define       sqr(x)               x*x
#define       min3(a,b,c)          min(a,min(b,c))
#define       max3(a,b,c)          max(a,max(b,c))
#define       all(v)               v.begin(), v.end()
#define       ok                   cout << "ok" << endl
#define       mem(x,y)             memset(x,y,sizeof(x))
#define       READ(f)              freopen(f, "r", stdin)
#define       WRITE(f)             freopen(f, "w", stdout)
/*.....................................Loops...............................................*/
#define       rep( i , a , b )     for( i=a ; i<b ; i++)
#define       rev( i , a , b )     for( i=a ; i>=b ; i--)
#define       repx( i ,a,b, x)     for( i=a ; i<b ; i+=x)

#define       FastRead             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*..................................Shutdown..............................................*/


typedef pair <int,int> ii;
map <int,int> lua;
char x;
int n,m,a[3000][3000],sum,ans = INF,f[3000][3000],g[3000][3000];
int main()
{
	freopen("PATH.INP","r",stdin);
	freopen("PATH.OUT","w",stdout);
	FastRead;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
				cin >> x;
				if (x =='.') a[i][j] = 0; else a[i][j] = 1;
		}
	ans = 3;
	for (int i = 1; i <= n; i++) f[i][0] = INF,f[i][m+1] = INF,g[i][0] = INF,g[i][m+1] = INF;
	for (int i = 1; i <= m; i++) f[0][i] = INF,f[n+1][i] = INF,g[0][i] = INF,g[n+1][i] = INF;
	f[1][1] = INF;
	f[n][m] = INF;
	g[1][1] = INF;
	g[n][m] = INF;
	for (int i = n; i >= 1; i--)
	for (int j = 1; j <= m; j++)
	{
		if (a[i][j] == 0)
		 f[i][j] = max(min(min(f[i+1][j],f[i+1][j-1]),f[i+1][j+1]) + 1,f[i][j]);
	  else
		 f[i][j] = max(min(min(f[i+1][j],f[i+1][j-1]),f[i+1][j+1]),f[i][j]);
	}
	for (int i = 1; i <= m; i++)	ans = min(ans,f[1][i]);
	for (int i = 1; i <= n; i++)
	 for (int j = 1; j <= m; j++)
	{
		if (a[i][j] == 0)
		 g[i][j] = max(g[i][j],min(min(g[i][j-1],g[i-1][j-1]),g[i+1][j-1])+1);
		else
		 g[i][j] = max(g[i][j],min(min(g[i][j-1],g[i-1][j-1]),g[i+1][j-1]));
	}
	for (int i = 1; i <= n; i++) ans = min(ans,g[i][m]);
	cout << ans;
	return 0;
}