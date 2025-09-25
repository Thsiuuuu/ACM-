#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define int long long 


const int maxn=110;
int a[maxn][maxn];

struct node{

    int s;
    int step=0;

};

int n,m;
bool vis[1026];
queue<node> q;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>m;
    for(int i=1;i<=m;i++) 
        for(int j=1;j<=n;j++)
            cin>>a[i][j];

    
    memset(vis,false,sizeof(vis));

    q.push({(1<<n)-1,0});
    vis[(1<<n)-1]=true;
    int  ans=-1;

    while(!q.empty()){
        auto u=q.front();
        if(u.s==0){
            ans=u.step;
            break;
        }

        int mod;
        for(int i=1;i<=m;i++){

            mod=u.s;
            for(int j=1;j<=n;j++){
                if(a[i][j]==1&&(mod&(1<<(j-1)))){
                    mod^=(1<<(j-1));
                }else if(a[i][j]==-1&&!(mod&(1<<(j-1)))){
                    mod^=(1<<(j-1));
                }
            
            }
        
             if(!vis[mod]){
                 vis[mod]=true;
                 q.push({mod,u.step+1});
            }
            
        }
        q.pop();


    }

    cout<<ans;
    return 0;


}