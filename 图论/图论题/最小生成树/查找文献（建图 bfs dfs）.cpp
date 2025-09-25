#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


const int maxn=1e6+10;

int n,m;
vector<int> g[maxn];
queue<int> q;
bool visited[maxn];


void dfs(int x,int cur){
    visited[x]=true;
    cout<<x<<" ";
    if(cur==n) return ;
    for(int i=0;i<g[x].size();i++){
        if(!visited[g[x][i]]) dfs(g[x][i],cur+1);
    }
}


void bfs(int x){
    memset(visited,false,sizeof(visited));
    visited[x]=true;
    q.push(x);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        cout<<v<<" ";
        for(int i=0;i<g[v].size();i++){
            if(!visited[g[v][i]]){
                visited[g[v][i]]=true;
                q.push(g[v][i]);
            }
        }
    }
} 



int main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());

    dfs(1,0);
    cout<<endl;
    bfs(1);
    return 0;
    


}