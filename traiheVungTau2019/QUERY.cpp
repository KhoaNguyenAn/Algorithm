#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5+1;
int n,m,tree[2*N];
void update(int p, int value)
{
    tree[p+n] = value;
    p = p+n;
    for (int i=p; i > 1; i >>= 1)
        tree[i>>1] = max(tree[i],tree[i^1]);
}
inline int get(int l, int r)
{
    int res = -1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res = max(res,tree[l++]);
        if (r&1)
            res = max(res,tree[--r]);
    }
    return res;
}
inline int Readint()
    {
        char c;
        while (c = getchar(), c < '0' || c > '9');
        int x = c - '0';
        while (c = getchar(), c >= '0' && c <= '9')
            x=(x<<3)+(x<<1)+c-'0';
        return x;
    }
inline char Readchar()
{
    char c;
    while (c = getchar(), c != 'Q' && c != 'S');
    return c;
}
void Write(int x)
{
    if (x > 9) Write(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("QUERY.INP","r",stdin);
    freopen("QUERY.OUT","w",stdout);
    n = Readint();
    m = Readint();
    int u,v;
    while (m--)
    {
        char k = Readchar();
			  if (k == 'S')
				{
					u = Readint();
					v = Readint();
				  update(u,v);
				}
				else
				{
				  u = Readint();
				  v = Readint();
					Write(get(u,v+1));
					putchar('\n');
				}
    }
    return 0;
}