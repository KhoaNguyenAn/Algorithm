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
#include <string>
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
priority_queue <ii> que;
int n,ans[N],u,v,c,d[N],seen[N],p,sl,nn,val;
vector <ii> a[N];
string st,st1;
int main()
{
	FastRead;
	freopen("VIKHUAN.INP","r",stdin);
	freopen("VIKHUAN.OUT","w",stdout);
	cin >> n;
	cin >> p;
	getline(cin,st1);
	getline(cin,st);
	for (int i = 1; i <= n-1; i++)
	{
			cin >> u >> v >> c;
			a[u].push_back(ii(v,c));
			a[v].push_back(ii(u,c));
	}
	memset(seen, 0 , sizeof seen);
	fill(d,d+N,INF);
	d[p] = 0;
	que.push(ii(0,p));
	while (!que.empty())
	{
		 ii x = que.top();
		 que.pop();
		 if (seen[x.Y] == true) continue;
		 seen[x.Y] = 1;
		 for (int i = 0; i < a[x.Y].size(); i++)
		 {
		 	  ii tmp = a[x.Y][i];
		 	  if (d[tmp.X] > tmp.Y + d[x.Y])
				{
					  d[tmp.X] = tmp.Y + d[x.Y];
					  que.push(ii(-d[tmp.X],tmp.X));
				}
		 }
	}
	sl = 0;
	nn = (floor(st.size() / 2)) + 1;
	istringstream s (st,istringstream::in);
	while (s>>val)
	{
		  ans[++sl] = d[val];
	}
	sort(ans+1,ans+sl+1);
	cout << ans[int(sl/2)+1];
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}