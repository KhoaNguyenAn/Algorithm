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
struct mang
{
	int x,y;
};
mang a[N];
int n,ans,xx,yy,zz,kk,x1,x2,x3,x4;
int main()
{
	FastRead;
	freopen("ART.INP","r",stdin);
	freopen("ART.OUT","w",stdout);
	cin >> n;
  for (int i = 1; i <= n; i++)
	{
		 cin >> a[i].x >> a[i].y;
	}
	n++;
	a[n].x = a[1].x;
	a[n].y = a[1].y;
	ans = 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[i].y == a[i-1].y)
		{
		 x1 = INF,x2 = -INF;
		 x3 = INF,x4 = -INF;
		 for (int j = 2; j <= n; j++)
		   if (j != i)
				{
					if (a[j].y == a[j-1].y)
					{
						if (a[j].y < a[i].y)
						{
							x1 = min(x1,max(min(a[j-1].x,a[j].x),min(a[i-1].x,a[i].x)));
							x2 = max(x2,min(max(a[j-1].x,a[j].x),max(a[i-1].x,a[i].x)));
						}
						else
						if (a[j].y > a[i].y)
						{
							x3 = min(x3,max(min(a[j-1].x,a[j].x),min(a[i-1].x,a[i].x)));
							x4 = max(x4,min(max(a[j-1].x,a[j].x),max(a[i-1].x,a[i].x)));
						}
					}
				}
		  if (x1==INF||x2==-INF||x3==INF||x4==-INF) continue;
      ans+=min((x4-x3),(x2-x1));
		}
		else
		{
			x1 = INF,x2 = -INF;
			x3 = INF,x4 = -INF;
			for (int j = 2; j <= n; j++)
		   if (j != i)
				{
					if (a[j].x == a[j-1].x)
					{
						if (a[j].x < a[i].x)
						{
							x1 = min(x1,max(min(a[j-1].y,a[j].y),min(a[i-1].y,a[i].y)));
							x2 = max(x2,min(max(a[j-1].y,a[j].y),max(a[i-1].y,a[i].y)));
						}
						else
						{
							x3 = min(x3,max(min(a[j-1].y,a[j].y),min(a[i-1].y,a[i].y)));
							x4 = max(x4,min(max(a[j-1].y,a[j].y),max(a[i-1].y,a[i].y)));
						}
					}
				}
			if (x1==INF||x2==-INF||x3==INF||x4==-INF) continue;
		  ans+=min((x4-x3),(x2-x1));
		}
	}
	cout << ans;
	return 0;
}