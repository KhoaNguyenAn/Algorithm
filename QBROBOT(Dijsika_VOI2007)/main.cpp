//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "TRUTIN_NTU"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e5 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,a[N],L[N],R[N];
string st;
bool dd[N];

struct data {
	int dis,id1,id2;
};

struct cmp {
	bool operator () (data a, data b) {
		if (a.dis != b.dis) return a.dis < b.dis;
		if (a.id1 != b.id1) return a.id1 < b.id1;
		return a.id2 < b.id2;
	}
};
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n;
		cin >> st;
		st = '#'+st;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		multiset <data, cmp> S;
		for (int i = 1; i <= n; i++)
		{
			 if (i != n && st[i]!=st[i+1])
			 	 S.insert( { abs(a[i]-a[i+1]),i,i+1 } );
			 L[i] = i-1;
			 R[i] = i+1;
		}
		ll res = 0;
		vector <ii> ans;
		memset(dd, true, sizeof dd);
		while (!S.empty())
		{
			 int i1 = (*S.begin()).id1, i2 = (*S.begin()).id2;
			 S.erase(S.begin());
			 if (dd[i1]&&dd[i2])
			 {
				ans.push_back(ii(i1, i2));
				dd[i1] = false; dd[i2] = false;
				R[L[i1]]=R[i2];
				L[R[i2]]=L[i1];
				if (L[i1] >= 1 && R[i2] <= n && st[L[i1]]!=st[R[i2]])
				{
			 	  S.insert( { abs(a[R[i2]]-a[L[i1]]),L[i1], R[i2] } );
				}
			 }
		}
		cout << ans.size();
		for (auto it : ans) cout << it.first << " " << it.second << endl;
		return 0;
}
/**Code written by AnkhoaGD**/
