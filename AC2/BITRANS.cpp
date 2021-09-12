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
priority_queue <iii> que;
int n,sl;
ll f[3000];
string st,st2;
int main()
{
	freopen("BITRANS.INP","r",stdin);
	freopen("BITRANS.OUT","w",stdout);
	int a = 0;
	int b = 0;
	f[1] = 0;
	for (int i = 2; i <= 1002; i++)
	{
		 int c = a;
		 a = a+b;
		 b = b+c;
		 if (i&1) ++a;
		 f[i] = a;
	}
	while (cin >> n)
	{
	if (n <= 20)
	{
	sl = 0;
	st = "1";
	for (int i = 1; i <= n; i++)
	{
		 st2 = "";
		 for (int j = 0; j < st.size(); j++)
		 if (st[j] == '1')
		 {
		 	 st2 = st2 + "01";
		 } else st2 = st2 + "10";
		 st = st2;
	}
	for (int i = 1; i < st.size(); i++)
		if (st[i] == '0' && st[i-1] == '0') sl++;
	cout << sl << endl;
	}
	else cout << f[n+1] << endl;
	}
	return 0;
}