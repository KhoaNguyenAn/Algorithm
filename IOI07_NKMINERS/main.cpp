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
int n,sl1,sl2,f1[N][4],f2[N][4],tmp1,tmp2,ans = 0;
char x;
int main()
{
	FastRead;
	cin >> n;
	sl1 = 1;
	sl2 = 1;
	for (int i = 1; i <= n; i++)
	{
		  cin >> x;
		  if (x == 'M')
			{
				tmp1 = f1[sl1][2] + f1[sl1-1][3];
				tmp2 = f2[sl2][2] + f2[sl2-1][3];
				if (tmp1 >= tmp2)
				{
					  sl1++;
					  f1[sl1][1] = 1;
					  ans+=tmp1+1;
				}
				else
				{
						sl2++;
					  f2[sl2][1] = 1;
					  ans+=tmp2+1;
				}
			}
			else
			if (x == 'F')
			{
				tmp1 = f1[sl1][1] + f1[sl1-1][3];
				tmp2 = f2[sl2][1] + f2[sl2-1][3];
				if (tmp1 >= tmp2)
				{
					  sl1++;
					  f1[sl1][2] = 1;
					  ans+=tmp1+1;
				}
				else
				{
						sl2++;
					  f2[sl2][2] = 1;
					  ans+=tmp2+1;
				}
			}
			else
			{
				tmp1 = f1[sl1][1] + f1[sl1-1][2];
				tmp2 = f2[sl2][1] + f2[sl2-1][2];
				if (tmp1 >= tmp2)
				{
					  sl1++;
					  f1[sl1][3] = 1;
					  ans+=tmp1+1;
				}
				else
				{
						sl2++;
					  f2[sl2][3] = 1;
					  ans+=tmp2+1;
				}
			}
	}
	cout << ans;
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}