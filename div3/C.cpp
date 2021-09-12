#include <bits/stdc++.h>
#include <iostream>
#define taskname "NAME"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e6 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
        multiset <int> d;
        for (int i = 1; i <= 4; i++) d.insert(i);
        d.insert(10);
        d.insert(1);
        //
        multiset <int>::iterator it;
        for (it = d.begin(); it != d.end(); it++) cout << *it << " ";
        cout << endl;
        ///
        multiset <int>::reverse_iterator x;
        for (x = d.rbegin(); x != d.rend();x++) cout << *x << " ";
        ///
        cout << endl;
        multiset <int>::iterator tmp;
        tmp = d.upper_bound(4);
        cout << distance(d.begin(),tmp);
		return 0;
}



