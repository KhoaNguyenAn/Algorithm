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
const int N = 3e5+6;
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
char x;
int n,a[N],tmp,ans,s,k;
vector <int> b;
bool bns(int l,int r,int v,int m)
{
	 while (l < r)
	 {
	 	 int mid = (l+r) >> 1;
	 	 if (a[mid] >= v && a[mid] <= m) return true;
	 	 if (a[mid] < v) l = mid+1;
	 	 if (a[mid] > m) r = mid-1;
	 }
	 if (a[l] > m) return false;
	 if (a[l] >= v) return true;
	 return false;
}
int main()
{
	FastRead;
	freopen("ANDO.INP","r",stdin);
	freopen("ANDO.OUT","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++)
	{
		tmp = a[i];
		for (int j = 1; tmp > 0; j++)
		{
			 b.push_back(tmp%2);
			 tmp >>= 1;
		}
		tmp = 0;
		for (int j = b.size()-1; j >= 0;j--)
		{
			if (b[j] == 1)
			{
			 s = (tmp | (1 << (j)));
			 k = (1 << j) - 1;
			 if (i-1 != 0 && bns(1,i-1,s,s+k)== true) tmp = s;
			}
		}
		b.clear();
		ans = max(ans,(a[i]&tmp));
	}
	cout << ans;
	return 0;
}