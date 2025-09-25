#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long 


const int N=310;

int dp[N][N];
/*

    最后肯定是有两堆石头，左右合并
    有很多可能的端点（代表左右合并的情况）
    dp[0][n]=min(dp[0][l]+dp[l+1][r])  l∈{0,1,...,r-1};
    需要处理前缀和
*/

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n;
    cin>>n;
    vector<int> stone(n+1),sum(n+1,0);
    
    for(int i=1;i<=n;i++){
        cin>>stone[i];
        sum[i]=(sum[i-1]+stone[i]);
    }

    memset(dp,0x3f3f3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int l=n-1;l>=1;l--){
        for(int r=l+1;r<=n;r++){
            for(int k=l;k<r;k++){
                dp[l][r]=min(dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1],dp[l][r]);
            }
        }
    }//注意这里枚举最小值的时候一定要把前缀和放在里面，不然会重复计算，如果说有多次dp[l][r]都取最小值的情况下


    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[1][n];
    return 0;
}