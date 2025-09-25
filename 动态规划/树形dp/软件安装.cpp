#include <iostream>
#include <vector>
#include <stack>

/*

    需要考虑很多的一道题
    首先是这个制约关系，制约关系有可能是一个环，这种情况下要不然整个都选，要不然都不选
    所以这个相当于一个新的点，采用tarjan算法缩点

    然后是建立虚拟节点
    然后是树形dp

*/

using namespace std;
#define int long long 


int n,m,w[110],v[110],f[110][510];
int low[110],dfn[110],ori[110],tim;
int n2,w2[110],v2[110];
bool vis[110],in[110];

int siz[110];
vector<int> G[110],G2[110];
stack<int> st;

void dfs(int pos){
    int tsiz=w2[pos];
    for(auto i:G2[pos])
        dfs(i),tsiz+=siz[i];
    for(int i=w2[pos];i<=min(m,tsiz);i++){
        f[pos][i]=v2[pos];
    }
    siz[pos]=w2[pos];
    for(auto i:G2[pos]){
        for(auto j=min(m,siz[pos]+siz[i]);j>w2[pos];j--){
            for(int k=max((int)0,j-siz[pos]),lim=min(siz[i],j-w2[pos]);k<=lim;k++){
                f[pos][j]=max(f[pos][j],f[i][k]+f[pos][j-k]);
            }
        }
        siz[pos]+=siz[i];
    }
}

void tarjan(int x){
    low[x]=dfn[x]=++tim;
    st.push(x);
    vis[x]=1;
    for(auto i:G[x]){
        if(!dfn[i]){
            tarjan(i);
            low[x]=min(low[x],low[i]);
        }else if(vis[i]){
            low[x]=min(low[x],dfn[i]);
        }
    }
    if(dfn[x]==low[x]){
        ++n2;
        while(1){
            int t=st.top();
            ori[t]=n2;
            st.pop();
            vis[t]=0;
            v2[n2]+=v[t];
            w2[n2]+=w[t];
            if(t==x) break;
        }
    }
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++){
        int d;
        cin>>d;
        if(d) G[d].emplace_back(i);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++){
        int x=ori[i];
        for(auto j:G[i]){
            int y=ori[j];
            if(x==y) continue;
            G2[x].emplace_back(y);
            in[y]=1;
        }
    }
    for(int i=1;i<=n2;i++){
        if(!in[i]) G2[0].emplace_back(i);
    }
    dfs(0);
    cout<<f[0][m];
    return 0;
}





