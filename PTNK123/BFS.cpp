#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
const ll MAX=1e6+5,MAXC=1e18;
ll n,m,s,t,u,v,trace[MAX];
bool seen[MAX];
vector<ll>a[MAX];
// F khoang cach
// S.F vi tri v
// S.S trace
struct cmp{
    bool operator()(iii x,iii y){
        return x.F<y.F||(x.F==y.F&&((x.S.F==y.S.F&&x.S.S<y.S.S)||(x.S.F<y.S.F)));
    }
};
priority_queue < iii,vector<iii> ,cmp > heap;
int main()
{
    freopen("BFS.inp","r",stdin);
    freopen("BFS.out","w",stdout);
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        a[u].pb(v);
    }
    memset(seen,0,sizeof seen);
    for(int i=1;i<=n;i++)sort(a[i].begin(),a[i].end());
    heap.push(iii(0LL,ii(s,0LL)));
    while(!heap.empty()){
        iii x=heap.top();
        heap.pop();
        u=x.S.F;
        if(seen[u])continue;
        trace[u]=x.S.S;
        if(u==t){
            //cout << x.F << endl;
            break;
        }
        seen[u]=1;
        for(int i=0;i<a[u].size();i++){
            v=a[u][i];
            if(!seen[v])heap.push(iii(x.F+1,ii(v,u)));
        }
    }
    stack<ll>Q;
    while(t){
        Q.push(t);
        t=trace[t];
    }
    while(!Q.empty()){
        cout << Q.top() << " ";
        Q.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
8 12 1 8
1 2
1 3
2 3
2 4
3 1
3 5
3 7
4 6
6 2
6 8
7 8
7 6
*/
