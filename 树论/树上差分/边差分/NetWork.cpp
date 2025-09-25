#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/*

    对于这道题，如果不联通
    切老边的时候有三种情况
    可以先从第一种情况推广，一刀就断的情况，也就是老边不在一个回路里面，这个时候有新边m的方案数
    第二种情况，在一个回路里面，这个时候就是切一条老边同时切形成回路的新边
    第三种情况，在多个回路里面，这个时候没办法切断，方案数为0
    那么怎么知道一个边有多少回路包含它呢，可以利用新边打标记，但是打标记时间复杂度比较大，所以说我们应该采用边差分的方式快速修改

*/

const int N=100001,limit=17;

int power;
int log2(int n){
    int ans=0;
    while((1<<ans)<=(n>>1)){
        ans++;
    }
    return ans;
}

int n,m,w,num[N],head[N],nxt[N<<1],to[N<<1],cnt,deep[N],stjump[N][limit],ans;

void build(){
    power=log2(n);
    cnt=1;
    ans=0;

}

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

void dfs1(int u,int f){
    deep[u]=deep[f]+1;
    stjump[u][0]=f;
    for(int i=1;i<=power;i++){
        stjump[u][i]=stjump[stjump[u][i-1]][i-1];
    }
    for(int e=head[u];e;e=nxt[e]){
        if(to[e]^f){
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
        if(stjump[a][p]!=stjump[b][p]){
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
            w=num[v];//边加上连得节点的数值
            if(w==0){
                ans+=m;

            }else if(w==1){
                ans+=1;
            }else{
                ans+=0;
            }
            num[u]+=num[v];//父节点收集子节点数值
        }
    }
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);

    scanf("%d%d",&n,&m);
    build();
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs1(1,0);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        int lc=lca(u,v);
        num[u]+=1;
        num[v]+=1;
        num[lc]-=2;
    }
    dfs2(1,0);
    printf("%d",ans);
    return 0;
}