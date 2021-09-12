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
typedef pair <int,ii> iii;
map <int,int> lua;
const ii d1[3] = {ii(-1,0),ii(1,0),ii(0,1)};
struct mang
{
	  int x,y,z;
};
priority_queue <iii> que;
int n,m,a[3000][3000],x,y,seen[3000][3000],ans,d[3000][3000],tam;
int main()
{
	freopen("FAIR.INP","r",stdin);
	freopen("FAIR.OUT","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		  	 cin >> a[i][j],d[i][j] = INF;
	for (int i = 1; i <= n; i++)
	{
			memset(seen,false,sizeof seen);
			seen[i][1] = true;
		  que.push(iii(1,ii(i,1)));
		  d[i][1] = 1;
			while (!que.empty())
			{
		  iii tmp = que.top();
		  que.pop();
		  for (int i = 0; i < 3; i++)
			{
				 x = tmp.Y.X + d1[i].X;
				 y = tmp.Y.Y + d1[i].Y;
				 if (x > 0 && x <= n && y > 0 && y <= m)
					if (seen[x][y] == false)
					{
						 seen[x][y] =true;
						 if (a[tmp.Y.X][tmp.Y.Y] != a[x][y]) d[x][y] = min(d[x][y],d[tmp.Y.X][tmp.Y.Y] + 1);
										else d[x][y] = min(d[x][y],d[tmp.Y.X][tmp.Y.Y]);
						 que.push(iii(-d[x][y],ii(x,y)));
					}
			}
		  }
	}
	ans = INF;
	for (int i = 1; i <= n; i++) ans = min(ans,abs(d[i][m]));
	cout << ans;
	return 0;
}