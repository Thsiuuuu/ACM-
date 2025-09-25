#include <iostream>
#include <algorithm>
#include <vector>

using  namespace std;

/*

    所有节点跑一遍dfs，递归处理最大值即可

*/

const int N=1e5+10;

vector<int> e[N];
int mx[N];

void dfs(int u,int fa){
    mx[u]=u;
    for(int v:e[u]){
        if(v!=fa){
            dfs(v,u);
            mx[u]=max(mx[u],mx[v]);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m;
    cin>>n>>m;
    fill(mx,mx+1+n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!mx[i]){
            dfs(i,0);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<mx[i]<<" ";
    }
    
    return 0;
}