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
inline ll sqr(ll a) {return a*a;}
struct mang
{
     int x,y,r,m;
};
mang a[N];
ii b[N];
bool c[N];
long long ans,s,n,d;
bool check(int u,int v ,int k)
{
        long double aa,bb,cc,p,s,h;
        aa = sqrt(sqr(b[u].X-b[v].X)+sqr(b[u].Y-b[v].Y));
        bb = sqrt(sqr(b[u].X-a[k].x)+sqr(b[u].Y-a[k].y));
        cc = sqrt(sqr(b[v].X-a[k].x)+sqr(b[v].Y-a[k].y));
        if (sqr(cc) > sqr(bb) + sqr(aa))
            {
                aa = sqrt(sqr(b[u].X-a[k].x)+sqr(b[u].Y-a[k].y));
                long double ok = (a[k].r+d)*1.0;
                if (aa <= ok) return true; else return false;
            }
            else
            if (sqr(bb) > sqr(aa)+sqr(cc))
            {
                aa = sqrt(sqr(b[v].X-a[k].x)+sqr(b[v].Y-a[k].y));
                long double ok = (a[k].r+d)*1.0;
                if (aa <= ok) return true; else return false;
            }
            else
            {
                p = (aa+bb+cc) / 2;
                s = sqrt(p*(p-aa)*(p-bb)*(p-cc));
                h = (2*s) / aa;
                long double ok = (a[k].r+d)*1.0;
                if (h <= ok) return true; else return false;
            }
        return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> n >> d;
    for (int i = 1; i <= s; i++)    cin >> a[i].x >> a[i].y >> a[i].r >> a[i].m;
    for (int i = 1; i <= n; i++) {int xx,yy; cin >> xx; cin >> yy; b[i] = ii(xx,yy);}
    b[0] = ii(0,0);
    ans = 0;
    memset(c,false,sizeof c);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= s; j++)
        if (check(i-1,i,j)==true && c[j] == false)
        {
            c[j] = true;
            ans+= a[j].m;
        }
    for (int j = 1; j <= s; j++)
        if (check(n,0,j)==true && c[j] == false)
        {
            c[j] = true;
            ans+= a[j].m;
        }
    cout << ans;
    return 0;
}