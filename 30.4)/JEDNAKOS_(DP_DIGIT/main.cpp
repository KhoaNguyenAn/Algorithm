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
int k,b[N],i,tmp
bool kt;
string st;
int main()
{
	FastRead;
	cin >> st;
	kt = false;
	k = 1;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '=') kt = true;else
		if (kt == false) b[++sl1] = int(st[i]-'0');
		  else k = (k!=1)*10+int(st[i]-'0');
	}
	i = 0; tmp = 0;
	while (i <= sl1)
	{
		 i++;
		 tmp++;
		 if (b[i] == 0)
     {
     	  while (i <= sl1)
				{
					i++;
					if (b[i] != 0) break;
				}
				c[tmp] = b[i];
				while (tmp < i) c[++tmp] = b[i];
     }
     else
		 c[tmp] = b[i];
	}
	for (int i = sl1; i >= 1; i--)
	{
		for (int j = 1; j <= 4; j++)
		 for (int v = 1; v <= k; v++)
		   	f[c[j]][j] = f[b[j]][j]
	}
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}0