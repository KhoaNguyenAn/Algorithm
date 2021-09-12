//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "differ"
#define maxn 1000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, s[maxn], a[maxn], X[maxn], Y[maxn];
long long F[maxn], G[maxn];

void Calc(long long T[]){
    int top = 0;
    s[0] = 0;
    for (int i = 1; i <= n+1; i++){
        while (a[i] > a[s[top]]) Y[s[top--]] = i;// khong can top>0 vi s[0] = 0, a[0] = -oo
        X[i] = s[top];
        s[++top] = i;
    }
    for (int i = 1; i <= n; i++) T[i] = ((long long) i - X[i]) * (Y[i] - i);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen("WEIGHT.INP", "r", stdin);
    freopen("WEIGHT.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n+1] = 2e9;
    Calc(F);
    for (int i = 1; i <= n; i++) a[i] = -a[i];
    Calc(G);
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res = res + (G[i] - F[i]) * a[i];
    cout << res;
    return 0;
}
