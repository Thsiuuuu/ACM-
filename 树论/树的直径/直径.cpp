#include <iostream>
#include <algorithm>

using namespace std;

/*

    如何求公共路径，对于直径上一个点，如果它不走路径上的点走出来的最大的距离等于它到端点的距离，那么它可以再生成一条直径
    这样找到左右端点即可

*/
#define int long long 
const int N=2e5+10;

int head[N],to[N<<1],wght[N<<1],cnt,nxt[N<<1];
int last[N],dist[N];
int start,en;
int  d,l,r;
int n;
bool vis[N];
int res=0;

void addEdge(int u,int v,int  w){
    nxt[++cnt]=head[u];
    to[cnt]=v;
    wght[cnt]=w;
    head[u]=cnt;
}

int dfs1(int u,int ans) {
    vis[u]=true;
    int ans1=ans;
    for (int e=head[u],v;e;e=nxt[e]) {
        v=to[e];
        if(!vis[v]) { // 避免走父节点和直径点
            ans1 = max(ans1, dfs1(v,ans + wght[e]));
        }
    }
    return ans1;
}

void dfs2(int u,int fa){
    last[u]=fa;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=fa){
            dist[v]=dist[u]+wght[e];
            dfs2(v,u);
        }
    }
}

void find() {
    for (int i = last[en]; i != start; i = last[i]) {
        // 调用dfs1时传入父节点0
        long long maxDist = dfs1(i,0);
        if (maxDist==d-dist[i]) {
            r = i;
        }//上一个版本这里的代码错了是因为调用了两次的dfs1函数，两次的vis数组是不一样的，所以应该先预处理出来最大值
        if(maxDist==dist[i]&&l==start) {
            l = i;
        }
    }//这里有一个逻辑上的化简，因为左端点和右端点都不会超过中点，所以说逆序一次这样的遍历就可以得到左右端点的答案
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n-1;i++){
        int  a,b,c;
        cin>>a>>b>>c;
        addEdge(a,b,c);
        addEdge(b,a,c);
    }

    dfs2(1,0);
    start=1;
    en=1;
    for(int i=1;i<=n;i++){
        if(dist[start]<dist[i]){
            start=i;
        }
    }
    dist[start]=0;
    dfs2(start,0);
    for(int i=1;i<=n;i++){
        if(dist[en]<dist[i]){
            en=i;
        }
    }

    for(int i=en;i!=0;i=last[i]){
        vis[i]=true;
    }

    d=dist[en];
    l=start,r=en;
    
    find();
    // cout<<r<<' '<<l<<'\n';
    cout<<d<<'\n';
    for(int i=r;i!=l;i=last[i]){
        res++;
    }
    cout<<res;
    // cout<<l<<' '<<r<<'\n';
    // for(int i=en;i;i=last[i]){
    //     cout<<i<<' ';
    // }
    return 0;

}