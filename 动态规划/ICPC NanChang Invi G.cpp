#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define int long long  
/*


    首先注意到数据范围，因为体力值是1e9的范围，所以说走30次之后一定会走完
    也就是说对于每个查询，30步之内一定可以解决答案，但是如果一次查询查一次时间复杂度太大，
    考虑预处理出每个点走30步以内，每个步数情况下能走的边的权重值，
    从小到大枚举，如果权重值要大于当前的体力，那么这个答案就是最小值

*/

const int N=2e5+10;
int n,q,m;
vector<pair<int,int>> e[N];
vector<array<int,31>> dp(N);

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        e[u].push_back({v,d});
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=31;j++){
        for(int i=1;i<=n;i++){
            for(auto& [v,w]:e[i]){
                dp[i][j]=max(dp[i][j],dp[v][j-1]*w);
                // dp[i][j]=min(dp[i][j],(int)INT_MAX);
            }
        }
    }
    while(q--){
        int x,p;
        cin>>p>>x;
        for(int i=1;i<=30;i++){
            if(dp[p][i]>x){
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}