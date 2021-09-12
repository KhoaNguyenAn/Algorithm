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
#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define base 27ll
#define MAXN 1000010
#define MOD 998244353

using namespace std;
const int N = 1e6+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <long long,long long> ii;
map <int,int> lua;
long long sl,n,i,j,ans,cur,sub;
long long factor(long long  a)
{
    if(a == 0) return 1;
    return (a*factor(a-1))%MOD;
}
long long power(long long a,long long b)
{
    if ( b == 0 )return 1;
    long long p = power(a, b >> 1) % MOD;
    p = (p * p) % MOD;
    return (b % 2 == 0)? p : (a * p) % MOD;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if( n == 1)
	{
			cout << 1;
			return 0;
	}
	else
	if( n == 2)
	{
			cout << 2;
			return 0;
	}
	ans = n-1;
	cur = power(factor(n-1),MOD-2)%MOD;
	sub = cur;
	for( i = n-2 ; i >= 2; i--)
	{
		cur = (cur*(i+1))%MOD;
		sub = (sub + cur + MOD)%MOD;
	}
	ans =(ans-sub+MOD)%MOD;
	ans =(ans*factor(n))%MOD;
	cout << ans;
}

