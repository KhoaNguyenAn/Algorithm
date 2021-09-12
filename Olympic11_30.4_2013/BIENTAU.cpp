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
const int N = 5e3+6;
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
int n,a[N],res,tmp;
int main()
{
	FastRead;
	//freopen("BIENTAU.INP","r",stdin);
	//freopen("BIENTAU.OUT","w",stdout);
	cin >> n;
	/*for (int i = 1; i <= n; i++)
	{
		 cin >> a[i];
		 b[i] = a[i] - a[i-1];
	}
	ans = 0;
	for (int i = 1; i <= n; i++)
	 for (int j = 1; j <= n; j++)
		{
			 if (b[i] != b[j]) f[i][j] = 0;
			 else
			 if (j+1 > i) f[i][j] = 0;
			 else
			 if (b[i] == b[j]) f[i][j] = f[i-1][j-1]+1;
			 ans = max(ans,f[i][j]);
		}
	ans++;
	if (ans < 5) cout << 0; else cout << ans;*/
	res = 1;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 5; i <= n-5; i++)
	{
		int tmp = 1;
		for (int j = n; j > i; j--)
		if (a[j]-a[j-1] == a[j-i]-a[j-i-1])
		{
			 tmp++;
			 res = max(res,tmp);
			 if (tmp == i) break;
		}
	else tmp = 1;
	}
	if (res < 5) cout << '0'; else cout << res;
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}