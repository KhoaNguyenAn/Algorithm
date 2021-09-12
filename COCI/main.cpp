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
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define base 27ll
#define MAXN 1000010
#define MOD 1000000007ll

using namespace std;
const int N = 1e5+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;
map <int,int> lua;
int n,l[N],r[N],t[N],b[N];
bool kt;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= n; i++) cin >> r[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	kt = true;
	for (int i = 1; i <= n; i++)
	{
		if (l[i] == -1 && r[i] == -1) continue;
		if (l[i] == 1 && r[i] == -1) {kt = false; break;}
		if (r[i] == 1 && l[i] == -1) {kt = false; break;}
		if (n-l[i]-1>=r[i]) continue;
		if (n-r[i]-1>=l[i]) continue;
		kt = false; break;
	}
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == -1 && t[i] == -1) continue;
		if (b[i] == 1 && t[i] == -1) {kt = false; break;}
		if (t[i] == 1 && b[i] == -1) {kt = false; break;}
		if (n-b[i]-1>=t[i]) continue;
		if (n-t[i]-1>=b[i]) continue;
		kt = false; break;
	}
	if (kt==false) cout << "NE"; else cout << "DA";
	return 0;
}




