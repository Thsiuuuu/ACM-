#include <iostream>
#include <algorithm>

using namespace std;


#define int long long  


/*





*/


const int N=500001;

int head[N],nxt[N<<1],to[N<<1],tcnt;

int headQuery[N],queryNext[N<<1],queryTo[N<<1],queryIndex[N<<1],qcnt;

bool visited[N];
int father[N],ans[N];


void build(int n){
    tcnt=qcnt=1;
    fill(head,head+n+1,0);
    fill(headQuery,headQuery+1+n,0);
    fill(visited,visited+1+n,false);
    for(int  i=1;i<=n;i++){
        father[i]=i;
    }
}

void addEdge(int u,int v){
    nxt[tcnt]=head[u];
    to[tcnt]=v;
    head[u]=tcnt++;
}

void addQuery(int u,int v,int i){
    queryNext[qcnt]=headQuery[u];
    queryTo[qcnt]=v;
    queryIndex[qcnt]=i;
    headQuery[u]=qcnt++;
}

int find(int i){
    return i==father[i]?i:father[i]=find(father[i]);
}

void tarjan(int u,int f){
    visited[u]=true;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=f){
            tarjan(v,u);
            father[v]=u;
        }
    }

    for(int e=headQuery[u],v;e;e=queryNext[e]){
        v=queryTo[e];
        if(visited[v]){
            ans[queryIndex[e]]=find(v);
        }
    }
}


signed main(){
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
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        addQuery(u,v,i);
        addQuery(v,u,i);
    }
    tarjan(root,0);
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}