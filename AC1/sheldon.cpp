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
const int N = 1e5+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
#define       FastRead             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair <int,int> ii;
map <int,int> lua;

void app(long long& n,long long t,long long k,long long m)
{
    for (int i=1; i <= t; ++i)
    {
        n = n*2+k;
        if (n > m) return;
    }
}

long long cal(long long m)
{
    long long s;
    long long res = 0;
    for(int i = 1; i <= 63; ++i)
    {
        long long p = 0;
        app(p,i,1,m);
        if (p > m) break;
        ++res;
        for(int j = 1; j <= 63; ++j)
        {
            s = p;
            app(s,j,0,m);
            if (s > m)break;
            ++res;
            while (s <= m)
            {
                app(s,i,1,m);
                if (s > m) break;
                ++res;
                app(s,j,0,m);
                if (s > m) break;
                ++res;
            }
        }
    }
    return res;
}

int main()
{
    freopen("sheldon.inp","r",stdin);
    freopen("sheldon.out","w",stdout);
    long long a,b;
    cin >> a >> b;
    if (a == 0) a++;
    cout << cal(b)-cal(a-1);
    return 0;
}
