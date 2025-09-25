#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define  int long long 


/*


    考虑树形dp
    dp[u]表示第u层时需要去掉的叶子结点数量

    dp[u]=dp[u-1]- +


    按层划分，低于自己的要删掉其所在子树，高于自己的直接删节点，用前缀和维护
    这个是怎么设计的呢，
    因为要去掉上一层的子树，和下一层的所有节点
    为了方便查询，降低时间复杂度，不难想到前缀和维护
    分别维护以某一层结尾的子树的数量的前缀和，和某一层一下的后缀和·


*/



const int N=5e5+10;
int t;

vector<int> e[N];
int dep[N],depcnt[N],mxdep[N],mxcnt[N],summx[N],h,sumdep[N];
int mx;

void dfs(int u,int fa){
    depcnt[dep[u]]++;
    mxdep[u]=dep[u];
    for(auto v:e[u]){
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        mxdep[u]=max(mxdep[u],mxdep[v]);
    }
    mxcnt[mxdep[u]]++;
}


void solve(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        e[i].clear();
        e[i].shrink_to_fit();//强制调整容量为与当前大小相等，释放内存

    }

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        
    }

    for(int i=1;i<=n;i++){
        dep[i]=mxdep[i]=depcnt[i]=mxcnt[i]=summx[i]=sumdep[i]=0;
    }
    sumdep[n+1]=0;
    dfs(1,0);
    h=mxdep[1];
    for(int i=1;i<=h;i++){
        summx[i]=summx[i-1]+mxcnt[i];
    }
    for(int i=h;i;i--){
        sumdep[i]=sumdep[i+1]+depcnt[i];
    }
    int ans=1145141919;
    for(int i=1;i<=h;i++){
        ans=min(ans,sumdep[i+1]+summx[i-1]);
    }
    cout<<ans<<"\n";

}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>t;
    while(t--){
        solve();


    }
    return 0;
}