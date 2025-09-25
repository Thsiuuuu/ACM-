#include <iostream>
#include <vector>


const int N=5e5+10;

int head[N],to[N],nxt[N],wght[N];
int n;
int d,last[N],dist[N];
int end;
int cnt;
void addEdge(int u,int v,int w){
    nxt[++cnt]=head[u];
    to[cnt]=v;
    wght[cnt]=w;
    head[u]=cnt;
}

void dfs(int u,int fa,int w){
    last[u]=fa;
    dist[u]=dist[fa]+w;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=fa){
            dfs(v,u,wght[e]);
        }
    }
}

void query(){
    dfs(1,0,0);
    int start=1;
    for(int i=2;i<=n;i++){
        if(dist[i]>dist[start]){
            start=i;
        }
    }
    dfs(start,0,0);
    end=1;
    for(int i=2;i<=n;i++){
        if(dist[i]>dist[end]){
            end=i;
        }
    }
    d=dist[end];
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
    query();
    cout<<d;
    return 0;
}
