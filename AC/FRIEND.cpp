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
const int N = 1e3+6;
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
map <long long,long long> b;
long long n,m,a1,b1,a2,b2,a[300][300],ans = INF,u,v,c;
int main()
{
	FastRead;
	freopen("FRIEND.INP","r",stdin);
	freopen("FRIEND.OUT","w",stdout);
	cin >> n >> m;
	cin >> a1 >> b1 >> a2 >> b2;
	for (int i = 1; i <= n; i++)
       for (int j = 1; j <= n; j++)
            a[i][j] = INF;
    for (int i = 1; i <= n; i++)
        a[i][i] = 0;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> c;
        a[u][v] = c;
        a[v][u] = c;
    }
	for (int i = 1; i <= n; i++)
     for (int j = 1; j <= n ; j++)
        for (int k = 1; k <= n; k++)
         {
            if (a[j][k] > a[j][i] + a[i][k])
            {
                a[j][k] = a[j][i] + a[i][k];
                a[k][j] = a[j][k];
            }
         }
	for (int i = 1; i <= n; i++)
	{
		if (a[a1][i]+a[i][b1] == a[a1][b1] && a[a2][i]+a[i][b2] == a[a2][b2])
		{
			 if (a[a1][i] == a[a2][i]) ans = min(ans,a[a1][i]);
		}
	}
	if (ans == INF) cout << -1; else cout << ans;
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}