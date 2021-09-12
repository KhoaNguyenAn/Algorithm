#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define pb push_back
#define getbit(x, pos) ((x >> (pos - 1)) & 1)
#define sz(x) (int)x.size()

const int Nmax = 100100;
vector<int> ad[Nmax];
int n, m, c1 = 0, cnt = 0, num[Nmax], low[Nmax], child[Nmax], root,
Count, bridge;
bool Free[Nmax];
// DFS để đếm thành phần liên thông cũng như tìm các cầu.

void visit(int p, int i) {
    if (Count == 1) c1++;
    num[i] = ++cnt;
    low[i] = num[i];
    child[i] = 1;
    Free[i] = 1;
    FOR(j, 0, sz(ad[i]) - 1) if (ad[i][j] != p) {
        if (Free[ad[i][j]] == 0) {
         visit(i, ad[i][j]);
            child[i] += child[ad[i][j]];
            low[i] = min(low[i], low[ad[i][j]]);
        } else low[i] = min(low[i], num[ad[i][j]]);
    }
    if (root != i && low[i] == num[i]) bridge++;
}
int main() {
	  ios_base::sync_with_stdio(0);
	  cin.tie(0);
	  cout.tie(0);
	  freopen("REFORM.INP","r",stdin);
	  freopen("REFORM.OUT","w",stdout);
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        ad[x].pb(y);
        ad[y].pb(x);
    }
    Count = 0;
    memset(Free, 0, sizeof Free);
    FOR(i, 1, n) if (Free[i] == 0) {
        root = i;
        Count++;
        visit(0, i);
    }
    // trường hợp đồ thị có >= 3 thành phần liên thông, kết quả là 0
    if (Count >= 3) {
        cout << 0;
        return 0;
    }
    ll res;
    if (Count == 2) {
    // trường hợp đầu tiên.
        res = (ll)(m - bridge) * c1 * (n - c1);
    } else {
        res = (ll)(m - bridge) * ((ll)n * (n - 1)/2 - m);
    // cố định cầu bằng cách cố đỉnh các đỉnh từ 2 tới n và cha của các đỉnh tương ứng.
    // low[i] == num[i] nghĩa là i - cha[i] là cầu
        FOR(i, 2, n) if (low[i] == num[i])
            res += (ll)child[i] * (n - child[i]) - 1;
        }
    cout << res;
     return 0;
}