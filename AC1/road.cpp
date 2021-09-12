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
const int N = 1e6+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
#define       FastRead             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair <int,int> ii;
int b[N],c[N],p[N],s[N],n,ok,ans,ok1,xx,yy,zz,kk,tmp1,tmp2,smax;
int e[5005][5005];
int l[5005][5005];
int d[5005][5005];
map <int,int> o;
struct mang
{
    int x;
    int y;
    int w;
};
mang a[N];

bool comp(mang a, mang b)
{
    return a.w > b.w;
}
int main()
{
		freopen("road.inp","r",stdin);
		freopen("road.out","w",stdout);
		FastRead;
    cin >> n;
    ok = -30000;
    smax = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].w;
        tmp1 = o[a[i].x];
        tmp2 = o[a[i].y];
        if (o[a[i].x] == 0)
				{
					 smax++;
					 tmp1 = smax;
					 o[a[i].x] = smax;
				}
				if (o[a[i].y] == 0)
				{
					 smax++;
					 tmp2 = smax;
					 o[a[i].y] = smax;
				}
        ok = max(ok,a[i].w);
        d[tmp1][tmp2] = a[i].w;
        d[tmp2][tmp1] = a[i].w;
        e[tmp1][tmp2] = 1;
        e[tmp2][tmp1] = 1;
        a[i].x = tmp1;
        a[i].y = tmp2;
    }
    if (ok <= 0)
		{
			cout << 0;
			return 0;
		}
    sort(a+1,a+n+1,comp);
    c[a[1].x] = 1;
    c[a[1].y] = 1;
    b[1] = 1;
    ans = a[1].w;
    l[a[1].x][a[1].y] = 1;
    l[a[1].y][a[1].x] = 1;
    for (int i = 2; i <= n; i++)
		{
			if (b[i] == 0)
			{
				 if (c[a[i].x] == 1 || c[a[i].y] == 1)
				 {
					if (a[i].w >= 0)
					{
							c[a[i].x] = 1;
							c[a[i].y] = 1;
							b[i] = 1;
							ans+=a[i].w;
							l[a[i].x][a[i].y] = 1;
							l[a[i].y][a[i].x] = 1;
					}
				 }
				 else
				 {
				 	 if (a[i].w > 0)
					 {
						l[a[i].x][a[i].y] = 1;
						l[a[i].y][a[i].x] = 1;
				 	  ok = -30000;
						ok1 = 0;
				 	  for (int j = 1; j <= n; j++)
						if (b[j] == 0 && j != i)
						{
							 xx = a[i].x;
							 yy = a[i].y;
							 zz = a[j].x;
							 kk = a[j].y;
							 if (d[xx][zz] > ok && e[xx][zz] == 1 && l[xx][zz] == 0)
							 {
							 	   ok = d[xx][zz];
							 	   ok1 = j;
							 }
							 if (d[xx][kk] > ok && e[xx][kk] == 1 && l[xx][kk] == 0)
							 {
							 	   ok = d[xx][kk];
							 	   ok1 = j;
							 }
							 if (d[yy][zz] > ok && e[yy][zz] == 1 && l[yy][zz] == 0)
							 {
									ok = d[yy][zz];
									ok1 = j;
							 }
							 if (d[yy][kk] > ok && e[yy][kk] == 1 && l[yy][kk] == 0)
							 {
									ok = d[yy][kk];
									ok1 = j;
							 }
						}
						if (ans + a[i].w + ok >= ans)
						{
							 c[a[ok1].x] = 1;
							 c[a[ok1].y] = 1;
							 b[ok1] = 1;
							 l[a[ok1].x][a[ok1].y] = 1;
							 l[a[ok1].y][a[ok1].x] = 1;
							 ans = ans + a[i].w + ok;
						}
				 }
			}
		}
		}
    cout << ans;
	  return 0;
}

