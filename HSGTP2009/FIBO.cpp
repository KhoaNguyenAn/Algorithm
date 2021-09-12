///Kaze
#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#define taskname "FIBO"
#define Eureka cerr << "Eureka"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 3e6 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 31;
queue <int> que;
long long n,n1,n2;
string st,T,f1,f2;
long long hashT[N],target,power[N];
inline long long gethash(int L,int R)
{
	 return (hashT[R]-(hashT[L-1]*power[R-L+1])%MOD+MOD) %MOD;
}
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		#ifndef Kaze
		 freopen(taskname".INP","r",stdin);
		 freopen(taskname".OUT","w",stdout);
		#endif // Kaze
		cin >> n;
		cin >> st;
		f1 = "A";
		f2 = "B";
		for (int i = 1; i <= n-2; i++)
		{
			 T = f1 + f2;
			 f1 = f2;
			 f2 = T;
		}
		int n1 = T.size();
		int n2 = st.size();
		st = '#' + st;
		T = '#' + T;
		int res = 0;
		power[0] = 1;
		for (int i = 1; i <= n1; i++)
		  power[i] = (power[i-1]*base) % MOD;
		target = 0;
		for (int i = 1; i <= n2; i++)
			 target = (target*base+st[i]-'A'+1)%MOD;
		hashT[0] = 0;
		for (int i = 1; i <= n1; i++)
			hashT[i] = (hashT[i-1]*base+T[i]-'A'+1)%MOD;
		for (int i = 1; i <= n1-n2+1; i++)
			if (target == gethash(i,i+n2-1)) res++;
    cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/