#include <iostream>
#include <algorithm>

using  namespace std;

const int N=500001;
const int  LIMIT=20;

int  power;
int log2(int n){
    int ans=0;
    while((1<<ans)<=(n>>1)){
        ans++;
    }
    return ans;
}

int head[N],to[N<<1],nxt[N<<1];
int cnt,deep[N],stjump[N][LIMIT];

void build(int n){
    power=log2(n);
    cnt=1;
    fill(head,head+1+n,0);
}

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

void dfs(int  u,int fa){
    deep[u]=deep[fa]+1;
    stjump[u][0]=fa;//根节点怎么跳都是0
    for(int p=1;p<=power;p++){
        stjump[u][p]=stjump[stjump[u][p-1]][p-1];//如果走到根节点再向上走的话，那么就会走到根节点的st状态，这个时候不会越界，怎么走都是0
    }
    for(int e=head[u];e;e=nxt[e]){
        if(to[e]!=fa){
            dfs(to[e],u);
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
    if(a==b) return a;
    for(int p=power;p>=0;p--){
        if(stjump[a][p]!=stjump[b][p]){
            a=stjump[a][p];
            b=stjump[b][p];
        }
    }
    return stjump[a][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m,root;
    cin>>n>>m>>root;
    build(n);
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(root,0);
    for(int i=1,a,b;i<=m;i++){
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
    return 0;
}