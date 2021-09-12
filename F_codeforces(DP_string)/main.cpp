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
// link:
//https://codeforces.com/problemset/problem/1132/F?fbclid=IwAR1TowGTJrqc3_JCmT427E4Bp13IQteaPvKjZeoHeGAxv4JW6ELVgoTiRgs
int memo[3000][3000],dp[3000][3000],n;
string st;
//giai thich: goi dp[l][r] la min buoc de xoa het xau tu l den r
// TH1: xoa moi 1 minh thang st[l]
// => dp[l][r] = 1 + cal(l+1,r)
// TH2: xoa 1 thang st[l] ket hop voi 1 thang st[i] (l+1<=i<=r)
//=> dp[l][r] = cal(l+1,i-1)+cal(i,r)
// xet vi du: aaa
// voi i = 2; cal(i,r) se giup tinh duoc chi phi tu r den i bao gom ca thang tai i
// do vay cal(l+1,i-1) == 0 la hien nhien trong truong hop do
// xet vi du: aba
// voi i = 3; cal(i,r) = cal(3,3) = 1;
// cal(l+1,i-1) = cal(2,2) = 1; => 2;
// nhan thay : cal(i,r) da xu li cal tai (l,l) nen do do moi co cal(l+1,i-1);
int cal(int l,int r)
{
	 if (l == r) return 1;
	 if (l > r) return 0;
	 if (memo[l][r] == 1) return dp[l][r];
	 memo[l][r] = 1;
	 int res = 1 + cal(l+1,r);
	 for (int i = l+1; i <= r; i++)
	 if (st[l]==st[i])
	 	 res = min(res,cal(l+1,i-1)+cal(i,r));
	 dp[l][r] = res;
	 return res;
}
int main()
{
	FastRead;
	cin >> n;
	cin >> st;
	cout << cal(0,n-1);
	return 0;
}