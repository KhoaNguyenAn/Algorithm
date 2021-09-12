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
int n,sum,res,f[3000][3000],a[5000],t1,t2;
int main()
{
	FastRead;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sum = 0;
	for (int i = 1; i <= n-1; i++)
	 for (int j = i+1; j <= n;j++)
			if (a[i] > a[j]) sum++;
	// goi f[i][j] la khi doi cho i va j thi so cap nghich the duoc tang bao nhieu va giam bao nhieu
	//=> khi doi cho i,j(i<j) => so luong i da phan la giam, va j la tang
	//=> tinh truoc mang f[i][j]
	for (int i = 1; i <= n; i++)
	{
		 t1=t2=0;
		 for (int j = i-1; j >= 1; j--)
		 {
		 	 if (a[j] > a[i]) t1++; // sl giam nghich the
		 	 if (a[j] < a[i]) t2++; // sl tang nghich the
		 	 f[i][j] = t2-t1; // sl tang = sl tang - slbutru
		 }
		 t1=t2=0;
		 for (int j = i+1; j <= n; j++)
		 {
		 	 if (a[j] > a[i]) t1++; // sl giam nghich the
		 	 if (a[j] < a[i]) t2++; // sl tang nghich the
		 	 f[i][j] = t1-t2; // sl giam = sl giam - slbutru
		 }
	}
	res = sum;
	// chu y: do f[i][j] la tinh i va j khi chua doi cho j
	// => phai them 2 dk cuoi
	// Vi neu a[i] > a[j] thi f[i][j] se bi giam qua di 1 don vi nen khi doi cho i,j phai tang len lai 1
	for (int i = 1; i <= n-1; i++)
	 for (int j = i+1; j <= n; j++)
	   res = min(res,sum+f[i][j]+f[j][i]-(a[i] < a[j])+(a[i] > a[j]));
	cout << res;
	return 0;
}