#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N=1e5+10;
vector<int> e[N];
int  dist[N];

int  r,n;
void dfs(int u,int fa){
    dist[u]=dist[fa]+1;
    if(dist[r]<dist[u]){
        r=u;
    }
    for(int v:e[u]){
        if(v!=fa){
            dfs(v,u);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1,0);
    dist[r]=-1;//注意dfs的时候这么写会利用到最远的起点自己
    dfs(r,r);
    cout<<dist[r];
    return 0;
}