///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "QTGIFT1"
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
const ll N = 1e6 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,k,a[N];
long long F[N], S = 0, mmin;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
int main()
{
		read(n); read(k);
		for (int i = 1; i <= n; i++)
		{
			read(a[i]);
			S += a[i];
		}
		deque <int> Q;
		Q.push_back(0); F[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			  while (!Q.empty() && Q.front() < i-k) Q.pop_front();
			  if (!Q.empty()) F[i] = F[Q.front()] + a[i];
			  else F[i] = a[i];
			  while (!Q.empty() && F[Q.back()] >= F[i]) Q.pop_back();
				Q.push_back(i);
		}
		mmin = INF64;
		for (int i = n-k+1; i <= n; i++) mmin = min(mmin,F[i]);
		write(S-mmin);
		return 0;
}
/**Code written by AnkhoaGD**/