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
#include <cstdlib>
#include <stack>
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define MAXN 1000010
#define MOD 1000000007ll
using namespace std;
const int N = 6*1e5+5;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;
inline ld sqr(ld a) {return a*a;}
ld xa,ya,xb,yb,xc,yc,ans;
long double cal(ld xa,ld ya,ld xb ,ld yb,ld xc,ld yc)
{
     long double aa,bb,cc,p,s,h;
     int tmp = 0;
     aa = sqrt(sqr(xb-xa)+sqr(yb-ya));
     bb = sqrt(sqr(xc-xa)+sqr(yc-ya));
     cc = sqrt(sqr(xc-xb)+sqr(yc-yb));
     ld res1 = cc;
     ld res2 = bb;
     ld res = min(res1,res2);
        if (sqr(cc) > sqr(bb) + sqr(aa)) tmp++;
				else
				if (sqr(bb) > sqr(aa) + sqr(cc)) tmp++;
				else
				{
           p = (aa+bb+cc) / 2;
           s = sqrt(p*(p-aa)*(p-bb)*(p-cc));
           h = (2*s) / aa;
           res = min(res,h);
				}
		return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("DISTANCE.INP","r",stdin);
    //freopen("DISTANCE.OUT","w",stdout);
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ans = cal(xa,ya,xb,yb,xc,yc);
    cout << fixed << setprecision(5) << ans;
    return 0;
}
