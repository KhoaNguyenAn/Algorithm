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
#define MOD 1000000007ll

using namespace std;
const int N = 2*1e3+5;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;
map <int,int> lua;
long long n,k;
stack <int> stk;
struct cmp
{
		bool operator() (const ii&A1, const ii&B1)
		{
			 return (A1.X < B1.X) || (A1.Y==B1.Y);
		}
};

int a[100005];
bool ans[N][N] = {false};
bool cmp(int x, int y)
{
	 return x <= y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//mt19937 rng(time(NULL));
	srand(time(NULL));
	int n = 100000;
	for (int i = 1;i <= n; i++) a[i] = i/10;
	random_shuffle(a,a+n+1,rand);
	sort(a+1,a+n+1,cmp);
	for (int i = 1; i < n; i++) assert(a[i] <= a[i+1]);
	return 0;
}