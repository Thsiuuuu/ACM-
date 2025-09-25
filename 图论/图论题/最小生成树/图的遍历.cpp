#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

const int maxn=1e5+10;


int n,m;
vector<int> g[maxn];
bool visited[maxn];


int dfs(int x,int cur,int mx){

    
    visited[x]=true;

    for(int i=0;i<g[x].size();i++){
        if(!visited[g[x][i]]){
            dfs(g[x][i],cur+1,mx);
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


    for(int i=1;i<n;i++){
        int mx=1;

    }
}