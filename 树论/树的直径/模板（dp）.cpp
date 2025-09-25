#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

const  int N=5e5+10;;
int n ;
int  head[N],nxt[N<<1],to[N<<1],wght[N<<1],cnt;

int  dist[N],ans[N];

void addEdge(int u,int v,int w){
    nxt[++cnt]=head[u];
    to[cnt]=v;
    wght[cnt]=w;
    head[u]=cnt;
}

void dfs(int u,int fa){
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=fa){
            dfs(v,u);
        }
    }
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=fa){
            ans[u]=max(ans[u],dist[u]+dist[v]+wght[e]);
            dist[u]=max(dist[u],dist[v]+wght[e]);
        }
    }
}

int  main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    dfs(1,0);
    int d=INT_MIN;
    for(int i=1;i<=n;i++){
        d=max(d,ans[i]);
    }
    cout<<d;
    return 0;
}