#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int ans,dp[100010],n,m,x,y,i,cnt,head[100010];

struct edge{
    int next,to;
}e[100010];

void add(int x,int y){
    e[++cnt]={head[x],y};
    head[x]=cnt;
}

void dfs(int u){
    if(dp[u]) return;
    int i,v;dp[u]=-1;
    for(i=head[u];i;i=e[i].next){
        v=e[i].to;
        dfs(v);
        dp[u]=max(dp[u],dp[v]);
    }
    ++dp[u];
    ans=max(ans,dp[u]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        add(x,y);
    }
    for(int i=1;i<=n;i++) dfs(i);
    cout<<ans;
    return 0;
}
