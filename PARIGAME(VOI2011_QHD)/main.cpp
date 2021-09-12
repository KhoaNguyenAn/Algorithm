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
ull t,n,h,c,sum[600][600],f[600][600],a[600][600],x,y;
int main()
{
	FastRead;
	cin >> t;
	while (t--)
	{
		 cin >> n;
		 for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) cin >> a[i][j];
		 for (int i = 0; i <= n; i++) sum[i][0] = 0, sum[0][i] = 0;
		 for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		 for (int i = 1; i <= n; i++)
		 {
		 	 if (sum[i][1] % 2 == 0) f[i][1] = true; else f[i][1] = false;
		 	 if (sum[1][i] % 2 == 0) f[1][i] = true; else f[1][i] = false;
		 }
		 for (int i = 2; i <= n; i++)
			for (int j = 2; j <= n; j++)
			{
				  h = sum[i][j] - sum[i-1][j];
				  c = sum[i][j] - sum[i][j-1];
				  if (h % 2 == 0 && f[i-1][j] == false) x = true; else x = false;
				  if (c % 2 == 0 && f[i][j-1] == false) y = true; else y = false;
				  f[i][j] = (x | y);
			}
			if (f[n][n] == true) cout << "YES"<< endl; else cout << "NO" << endl;
	}

	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}