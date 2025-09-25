#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=50001,limit=16;
int power;

int num[N],head[N],to[N<<1],nxt[N<<1];
int cnt;
int deep[N];
int stjump[N][limit];
int n,m;

int  log2(int n){
    int ans=0;
    while((1<<ans)<=(n>>1)){
        ans++;
    }
    return ans;
}

void build(int n){
    power=log2(n);
    cnt=1;
}

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

void dfs1(int  u,int  f){
    deep[u]=deep[f]+1;
    stjump[u][0]=f;
    for(int p=1;p<=power;p++){
        stjump[u][p]=stjump[stjump[u][p-1]][p-1];
    }
    for(int e=head[u];e;e=nxt[e]){
        if(to[e]!=f){
            dfs1(to[e],u);
        }
    }
}

int lca(int a,int b){
    if(deep[a]<deep[b]){
        swap(a,b);
    }
    for(int p=power;p>=0;p--){
        if(deep[stjump[a][p]]>=deep[b]){
            a=stjump[a][p];
        }
    }
    if(a==b){
        return a;
    }
    for(int p=power;p>=0;p--){
        if(stjump[a][p]^stjump[b][p]){
            a=stjump[a][p];
            b=stjump[b][p];
        }
    }
    return stjump[a][0];
}

void dfs2(int u,int f){
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v^f){
            dfs2(v,u);
            num[u]+=num[v];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    build(n);
    cin>>m;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs1(1,0);
    for(int i=1,u,v,lc,lcafather;i<=m;i++){
        cin>>u>>v;
        lc=lca(u,v);
        lcafather=stjump[lc][0];
        num[u]++;
        num[v]++;
        num[lc]--;
        num[lcafather]--;
    }
    dfs2(1,0);
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,num[i]);
    }
    cout<<mx;
    return 0;
}

