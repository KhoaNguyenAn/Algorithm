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
const int N = 1e4+6;
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
struct mang
{
	ll x,y;
};
mang a[N];
vector <iii> b;
ll xx,yy,dis,prebest[N],best[N],pre[N],n;
int main()
{
	//freopen("VOVA.INP","r",stdin);
	//freopen("VOVA.OUT","w",stdout);
	FastRead;
	cin >> n;
	a[0].x = 0;
	a[0].y = 0;
	for (int i = 1; i <= n; i++)
		 cin >> a[i].x >> a[i].y;
	for (int i = 0; i <= n-1; i++)
	 for (int j = i+1; j <= n; j++)
	 {
			xx = a[i].x-a[j].x;
			yy = a[i].y-a[j].y;
			b.push_back(iii(xx*xx+yy,ii(i,j)));
	 }
	 sort(b.begin(),b.end());
	for (int i = 0; i < b.size(); i++)
	{
		 dis = b[i].X;
		 xx = b[i].Y.X;
		 yy = b[i].Y.Y;
		 if (dis != pre[xx])
		 {
		 	   pre[xx] = dis;
		 	   prebest[xx] = best[xx];
		 }
		 if (dis != pre[yy])
		 {
		 	  pre[yy] = dis;
		 	  prebest[yy] = best[yy];
		 }
		 if (xx==0)
		  best[xx] = max(best[xx],prebest[yy]);
		 else
		 {
		 	 best[xx] = max(best[xx],prebest[yy]+1);
		 	 best[yy] = max(best[yy],prebest[xx]+1);
		 }
	}
	cout << best[0] + 1;
	return 0;
}