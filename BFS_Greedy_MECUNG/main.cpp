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
const int N = 1e5+10;
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
int n,m,u,v,c,tmp,d[N],ans,h[N];
vector <ii> a[N];
int main()
{
	FastRead;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> c;
		a[u].push_back(ii(v,c));
		a[v].push_back(ii(u,c));
	}
	queue <int> que;
	que.push(n);
	d[n] = 1;
	while (!que.empty())
	{
     tmp = que.front();
     que.pop();
     if (tmp == 1) break;
     for (v = 0; v < a[tmp].size(); v++)
		 {
				u = a[tmp][v].X;
				if (d[u] != 0) continue;
				que.push(u);
				d[u] = d[tmp] + 1;
		 }
	}
	cout << d[1]-1 << endl;
	queue <int> quetmp;
	h[1] = 1;
	que.push(1);
	for (int turn = 1; turn < d[1]; turn++)
	{
		  ans = INF;
		  while (!que.empty())
			{
				 int x = que.front();
				 que.pop();
				 quetmp.push(x);
				 for (int i = 0; i < a[x].size(); i++)
				 if (d[a[x][i].X] == d[x]-1)
					  ans = min(ans,a[x][i].Y);
			}
			cout << ans << " ";
			while (!quetmp.empty())
			{
				 int x = quetmp.front();
				 quetmp.pop();
				 for (int i = 0; i < a[x].size();i++)
				 if (d[a[x][i].X] == d[x]-1 && a[x][i].Y == ans && !h[a[x][i].X])
				 {
				 	  h[a[x][i].X] = 1;
				 	  que.push(a[x][i].X);
				 }
			}
	}
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}