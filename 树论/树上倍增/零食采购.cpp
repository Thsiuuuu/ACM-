#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

    这个题看到数据量不大，首先应该想到状态压缩可不可以解决
    然后我们很容易知道，这个是要求lca的，因为这个路径必定会通过lca

    然后直接查询的话很容易会超时
    可以想一下能不能进行预处理
    这里可以在倍增的过程当中，就顺便处理了

    这个也可以用树链剖分+线段树解决
    因为都是树上的区间查询

    但是根源一定要想到状态压缩

*/

const int limit=20,N=1e5+5;
int n,q,val[N],fa[N][limit],buc[N][limit],dep[N];

vector<int> g[N];
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    buc[u][0]=(1<<(val[u]-1));
    if(f){
        buc[u][0]|=(1<<(val[f]-1));
    }
    for(auto v:g[u]){
        if(v!=f){
            dfs(v,u);
        }
    }
}

int lca(int x,int y){
    int ret=0;
    if(x==y) return 1;
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    for(int k=15;k>=0;k--){
        if(dep[fa[x][k]]>=dep[y]){
            ret|=buc[x][k];
            x=fa[x][k];
        }
    }
    if(x==y) return ret;
    for(int k=15;k>=0;k--){
        if(fa[x][k]!=fa[y][k]&&fa[x][k]!=0&&fa[y][k]!=0){
            ret|=buc[x][k];
            ret|=buc[y][k];
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    ret|=(buc[x][0]|buc[y][0]);
    return ret;
}

int count (int x){
    int ret=0;
    while(x){
        if(x%2==1){
            ret++;
        }
        x/=2;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int k=1;k<=15;k++){
        for(int i=1;i<=n;i++){
            fa[i][k]=fa[fa[i][k-1]][k-1];
            buc[i][k]=(buc[i][k-1]|buc[fa[i][k-1]][k-1]);
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<count(lca(x,y))<<'\n';
    }
    return 0;
}