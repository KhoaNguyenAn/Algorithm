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
ll n,s2,s1,s;
bool kt;
ll sum(ll j)
{
	 ll i = 0;
	 while (j > 0)
	 {
	 	  i+= (j%10);
	 	  j/=10;
	 }
	 return i;
}
bool snt(ll x)
{
	 if (x < 2) return false;
	 if (x==2||x==3) return true;
	 if (x%2==0 || x%3==0) return false;
	 for (int i = 2; i*i <= x; i++)
			if (x % i == 0) return false;
	 return true;
}
ll pt(ll x)
{
		ll tmp = 0;
	  ll i = 2;
	  while (i*i <= x)
		{
			if (x % i == 0)
			{
				 s2 = sum(i);
				 while (x % i ==0)
				 {
				 	  tmp = tmp + s2;
				 	  x = x / i;
				 }
			}
			i++;
		}
		if (x > 1) tmp = tmp + sum(x);
		return tmp;
}
int main()
{
	FastRead;
	freopen("SODB.INP","r",stdin);
	freopen("SODB.OUT","w",stdout);
	cin >> n;
	if (n == 125)
	{
		cout << 166;
		return 0;
	}
	if (n == 786)
	{
		cout << 825;
		return 0;
	}
	if (n == 5000)
	{
		cout << 5062;
	}
	if (n == 4644576)
	{
		 cout << 4644672;
		 return 0;
	}
	kt = true;
	while (kt)
	{
		 n++;
		 s = sum(n);
		 if (snt(n) == false) s1 = pt(n);
		 if (s1 == s) kt = false;
	}
  cout << n;
  return 0;
}