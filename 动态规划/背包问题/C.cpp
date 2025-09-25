#include <iostream>
#include <algorithm>

using namespace std;


#define int long long 

const int maxn=510;
int n,m,b,mod;
int bug[maxn],dp[maxn][maxn]={0};//dp2[maxn][maxn]={0};
//dp1数量数组，dp2限制数组
//第一维总行数，第二维总bug数
//滚动数组进行优化

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>m>>b>>mod;
    for(int i=1;i<=n;i++){
        cin>>bug[i];
    }


    dp[0][0]=1;

    //i是总人数
    //j是当前总行数
    //k是当前可写行数
    //l是当前bug数

    /*
    for(int k=1;k<=j-i;k++){
                for(int l=1;l<=b;l++){
                    dp[j][l]
                }
            }
                */

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(bug[i]<=b){
                for(int k=bug[i];k<=b;k++){
                    dp[j][k]=dp[j-1][k-bug[i]]%mod+dp[j][k]%mod;
                    dp[j][k]=dp[j][k]%mod;
                }
            }
        }
    }


    /*
    for(int i=1;i<=m;i++){
        for(int j=1;j<=b;j++){
            cout<<dp[i][j]<<"\n";
        }
    }*/

    int ans=0;
    for(int l=0;l<=b;l++){
        ans=(ans+dp[m][l])%mod;
    }


    cout<<ans;


    return 0;

}