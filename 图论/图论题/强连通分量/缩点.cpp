#include <iostream>


using  namespace std;

/*

    缩点，毕竟是缩点模板题，然后按缩点之后的点重构图进行dp

*/


const int N=10010;
int n,m;
vector<int> e[N],ne[N];
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],cnt;
int w[N],nw[N],dp[N];

void tarjan(int x){
    dfn[x]=low[x]=++tot;
    stk[++top]=x,instk[x]=1;
    for(int y:e[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(instk[y]){
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(low[x]==dfn[x]){
        int y;++cnt;
        do{
            y=stk[top--];
            instk[y]=0;
            scc[y]=cnt;
        }while(y!=x);
    }
}

int main(){
    int a,b,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        e[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int x=1;x<=n;x++){
        nw[scc[x]]+=w[x];
        for(int y:e[x]){
            a=scc[x],b=scc[y];
            if(a!=b){
                ne[a].push_back(b);
            }
        }
    }

    for(int x=cnt;x>0;x--){
        if(dp[x]==0){
            dp[x]=nw[x];
        }
        for(int y:ne[x]){
            dp[y]=max(dp[y],dp[x]+nw[y]);
        }
    }

    for(int i=1;i<=cnt;i++){
        ans=max(ans,dp[i]);
    }

    cout<<ans;
    return 0;
}