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
bool seen[N];
long long n,p,u,v,f[300][300],c[N],k = 0,ans,sl = 0,d[N];
vector <long long> a[N];
void dfs(int u)
{
	  seen[u] = true;
	  for (int i = 0; i < a[u].size(); i++)
		{
			 int v = a[u][i];
			 if (seen[v] == false)
			 {
				 dfs(v);
				 for (int j = 1; j <= p;j++)
				  for (int k = 1; k < j; k++)
				   {
				     if (f[u][j] < f[v][k]+f[u][j-k])
						 	  f[u][j] = f[v][k]+f[u][j-k];
					 }
					if (f[u][p] > k)
					{
						  k = f[u][p];
						  ans = u;
					}
			 }
		}
}
void dfs1(int ans)
{
	seen[ans] = true;
	d[++sl] = ans;
	for (int i = 0; i < a[ans].size(); i++)
		 {
		 	int v = a[ans][i];
			for (int j = 1; j <= p;j++)
			{
				if (seen[v] == true) break;
				for (int k = 1; k < j; k++)
				{
					if (f[ans][j] == f[v][k]+f[ans][j-k])
								dfs1(v);
				}
			}
		 }
}
int main()
{
	FastRead;
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n ;i++)
	{
		  cin >> u >> v;
		  a[u].push_back(v);
		  a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	 for (int j = 1; j <= p; j++) f[i][j] = -INF;
	for (int i = 1; i <= n; i++) f[i][1] = c[i];
	memset(seen,false,sizeof seen);
	dfs(1);
	memset(seen,false,sizeof seen);
	dfs1(ans);
	sort(d+1,d+p+1);
	for (int i = 1; i <= p; i++) cout << d[i] << " ";
	return 0;
}
