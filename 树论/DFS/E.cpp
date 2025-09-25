#include <iostream>
#include <algorithm>
#include <vector>
/*

    树形dp，然后尝试换多个根


    换根dp
    为什么能想到dp
    两种途径
    第一种自顶向下，我肯定要知道自己节点有多少个，我才能知道自己有多少个
    第二种自底向上，如果知道了最底层的，那么我的上一层也肯定能推出来

*/

using namespace std;
#define int long long 
struct son{
    int v;
    int st;
};//st为0代表指向自己，为1代表指向对方

const int N=2e5+10;
vector<son> e[N];
int n;
int ans[N];
vector<int> dp(N,0);
void dfs1(int u,int fa){
    for(auto [v,st]:e[u]){
        if(v!=fa){
            dfs1(v,u);
            if(!st){
                dp[u]+=(dp[v]+1);
            }else{
                dp[u]+=dp[v];
            }
        }
    }
}

void dfs2(int u,int fa){
    ans[u]=dp[u];
    for(auto [v,st]:e[u]){
        if(v!=fa){
            int oldu=dp[u],oldv=dp[v];
            if(st==1){
                dp[v]=oldu+1;
            }else{
                dp[v]=oldu-1;
            }
            dfs2(v,u);
            dp[u]=oldu;
            dp[v]=oldv;
        }
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[v].push_back({u,0});
        e[u].push_back({v,1});
    }

    int  mn=1145141919;
    dfs1(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        mn=min(mn,ans[i]);
    }
    cout<<mn<<"\n";


    // for(int i=1;i<=n;i++){
    //     cout<<ans[i]<<" ";
    // }

    for(int i=1;i<=n;i++){
        if(ans[i]==mn){
            cout<<i<<" ";
        }
    }
    return 0;
}