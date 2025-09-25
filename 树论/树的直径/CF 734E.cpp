#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*

    首先缩点想到了，然后感性的想一下，缩完点之后一定是黑白交错的
    也就是说选定一个点，必然会同化到与它距离为1的点构成的区域里面
    那么选哪个点呢，一定是优先选直径中间的点，这个应该是一个基本不等式的东西，
    在两头的话最后是对答案没有影响的，还会多了一次次数，显然不是最优的

*/

const int N=2e5+10;

int head[N],to[N<<1],nxt[N<<1],cnt=1;

int n;
int fa[N],x[N],y[N];
int col[N],mx,id;

int find(int x){
    return fa[x]^x?fa[x]=find(fa[x]):x;
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(col[fx]==col[fy]) fa[fy]=fx;
}

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

void dfs(int u,int f,int dep){
    if(dep>mx){
        mx=dep;
        id=u;
    }
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v^f){
            dfs(v,u,dep+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>col[i];
        fa[i]=i;
    }
    for(int i=1;i<n;i++){
        cin>>x[i]>>y[i];
        unite(x[i],y[i]);
    }
    for(int i=1;i<=n;i++){
        fa[i]=find(fa[i]);
    }
    for(int i=1;i<=n;i++){
        if(fa[x[i]]^fa[y[i]]){
            addEdge(fa[x[i]],fa[y[i]]);
            addEdge(fa[y[i]],fa[x[i]]);
        }
    }
    dfs(fa[1],0,0);
    dfs(id,0,0);
    cout<<(mx+1)/2;
    return 0;
}