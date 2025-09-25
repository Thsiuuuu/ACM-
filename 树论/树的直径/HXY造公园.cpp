#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N=3e5+10;

int father[N],d[N];
vector<int> e[N];
int dp[N];
int n,m,q;
// bool vis[N];

int find(int x){
    return father[x]==x?x:father[x]=find(father[x]);
}

void dfs(int u,int fa){
    
    // vis[u]=true;
    for(int v:e[u]){
        if(v!=fa){
            dfs(v,u);
            d[u]=max({d[u],dp[u]+dp[v]+1,d[v]});
            dp[u]=max(dp[u],dp[v]+1);      
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);e[y].push_back(x);

        int fx=find(x),fy=find(y);
        if(fx!=fy){
            father[fy]=fx;
        }
    }

    for(int i=1;i<=n;i++){
        if(father[i]==i){
            dfs(i,0);
        }
    }

    while(q--){

        int op,x,y;
        cin>>op;

        if(op==1){
            cin>>x;
            cout<<d[find(x)]<<'\n';
        }else{
            cin>>x>>y;
            int fx=find(x),fy=find(y);
            if(fx!=fy){
                d[fx]=max({d[fx],d[fy],(d[fx]+1)/2+(d[fy]+1)/2+1});
                father[fy]=fx;
            }
        }
    }
    return 0;
}