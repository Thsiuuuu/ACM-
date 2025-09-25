#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

#define int long long 
const int N=1e6+10;
int siz[N],sum[N],dp[N],n;
vector<int> e[N];
/*


    换根dp
    这个可以先把以1为根的所有节点的深度和计算出来
    这个怎么计算呢
    可以想如果一个节点的所有子节点的深度和计算出来了
    那么从这个子节点的所有子节点的深度和，变成到这个节点的深度和，只需要每个点的深度都+1即可
    所以如果深度和求了出来，只需要在深度和上+包含自己在内的子节点数，就可以转换到父节点上面的贡献

    然后考虑换根
    一个父节点的dp值求了出来，可以分成两段
    第一段是以它的一个子节点为根的树，另一段是这个树上的另外一部分
    对于第一段而言，每个节点的深度都-1，所以总共减掉的数量是siz[子节点]
    对于第二段而言，每个节点的深度都+1，所以总共加上的数量是n-siz[子节点]

*/


void dfs1(int u,int fa){
    sum[u]=0;
    siz[u]=1;
    for(auto v:e[u]){
        if(v^fa){
            dfs1(v,u);
            siz[u]+=siz[v];
            sum[u]+=(sum[v]+siz[v]);
        }
    }
}

void dfs2(int u,int fa){
    for(auto v:e[u]){
        if(v^fa){
            dp[v]=dp[u]-siz[v]*2+n;
            dfs2(v,u);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    dfs1(1,0);
    dp[1]=sum[1];
    dfs2(1,0);
    pair<int,int> pii={0,INT_MIN};
    for(int i=1;i<=n;i++){
        if(pii.second<=dp[i]) pii.second=dp[i],pii.first=i;
    }
    cout<<pii.first;
    return 0;
}