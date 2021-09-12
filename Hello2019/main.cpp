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
const int INF = 1e9 + 10;
const int N = 1e6+4;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;

void f(string& st){
    string x = "";
    for(int i = 0 ;i < st.size(); i++)
		{
			if(st[i] == '(') x.push_back(st[i]);
			else if(x.size() > 0 && x.back() == '(') x.pop_back();
			else x.push_back(st[i]);
    }
    st = x;
}
int n,ans;
string tmp[N];
map <int,int> mp;
bool x;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n ;i++)
	{
		cin >> tmp[i];
		f(tmp[i]);
		x = true;
		if(tmp[i].size() == 0)
		{
			mp[0]++;
			continue;
		}
		for(int j = 0 ;j < tmp[i].size();j++)
		{
			if(tmp[i][j] != tmp[i][0])
			{
				x = false;
				break;
			}
		}
		if(!x) continue;
	  if(tmp[i][0] == '(') mp[tmp[i].size()]++; else mp[-tmp[i].size()]++;
	}
	ans = 0;
	for(auto i:mp)
	{
		if(mp.count(-i.X) == 0) continue;
		ans += min(i.Y, mp[-i.X]);
	}
	cout << (ans >> 1);
	return 0;
}
