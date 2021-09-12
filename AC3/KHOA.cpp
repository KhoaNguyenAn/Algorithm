#include <iostream>
#include <vector>
#include <cstdio>

#define pp push_back
using namespace std;
const int N = 5005;

int ok[N];
int num[N],low[N],p[N],g[N];
vector<int> e[N],q;
int all=0,z=0;

void dfs(int s){
    ok[s]=1;
    low[s]=num[s]=++all;
    q.pp(s);
    for(int i=0;i<e[s].size();++i){
        int y=e[s][i];
        if(ok[y]==0){
            dfs(y);
            low[s]=min(low[s],low[y]);
        }else if(ok[y]==1){
            low[s]=min(low[s],num[y]);
        }
    }
    ok[s]=2;
    if(num[s]==low[s]){
        ++z;
        while(q.back()!=s){
            p[q.back()]=z;
            q.pop_back();
        }
        p[s]=z;q.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("KHOA.INP","r",stdin);
    freopen("KHOA.OUT","w",stdout);
    int n,k;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>k;
        e[k].pp(i);
    }
    for(int i=1;i<=n;++i){
        if(!ok[i])dfs(i);
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<e[i].size();++j){
            int y=e[i][j];
            if(p[y]!=p[i])++g[p[y]];
        }
    }
    int ans=0;
    for(int i=1;i<=z;++i)if(!g[i])++ans;
    cout<<ans;
    return 0;
}
