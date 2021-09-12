#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = (1e5+1);
int n;
ll res;
struct TVector
{
    ll x, y;
    TVector operator -(const TVector& other) const
    {
        return {x - other.x, y - other.y};
    }
    ll operator *(const TVector& other) const
    {
        return x * other.y - y * other.x;
    }
};
using TPoint = TVector;
bool cmp(TPoint A, TPoint B)
{
    return (A.y < B.y || (A.y == B.y && A.x < B.x));
}
bool ccw(TPoint A, TPoint B, TPoint C)
{
    return (A - B) * (B - C) <= 0;
}
ll len(TPoint A, TPoint B)
{
    return (A.x - B.x)*(A.x - B.x)+(A.y - B.y)*(A.y - B.y);
}
TVector p[maxn];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("convexhull.inp", "r", stdin);
    freopen("convexhull.out", "w", stdout);
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> p[i].x >> p[i].y;
    sort(p, p+n, cmp);
    sort(p+1, p+n, [](const TPoint& A, const TPoint& B)
         {
            return (A - p[0])*(B - p[0]) > 0;
         });
    deque<TPoint> st;
    st.push_back(p[0]);
    st.push_back(p[1]);
    for (int i = 2 ; i < n ; i++)
    {
        while (st.size() >= 2 && ccw(st[st.size()-2], st[st.size()-1], p[i]))
            st.pop_back();
        st.push_back(p[i]);
    }
    TPoint O;
    O.x = 0;
    O.y = 0;
    for (int i = 1 ; i < st.size() ; i++)
        res += (O-st[i])*(O-st[i-1]);
    res += (O-st[0])*(O-st[st.size()-1]);
    cout << st.size() << "\n";
    cout << abs(res)/2;
    if (res & 1) cout << ".5"; else cout <<".0";
    cout << "\n";
    for (int i = 0 ; i < st.size() ; i++)
        cout << st[i].x << " " << st[i].y << "\n";
    return 0;
}
