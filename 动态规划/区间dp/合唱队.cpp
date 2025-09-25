#include <iostream>
#include <vector>


#define int long long  


using namespace std;
/*

    从结果倒退，任意一个排队不是在它的左边加就是右边加
    然后可以采用类似dfs的方式从右向左递推

*/

const int mod=19650827;

int dp[1010][1010][2];

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n;
    cin>>n;
    vector<int> num(n+1);

    for(int i=1;i<=n;i++) cin>>num[i];

    memset(dp,0,sizeof(dp));
    for(int l=n-1;l>=1;l--){
        if(num[l]<num[l+1]){
            dp[l][l+1][0]=1;
            dp[l][l+1][1]=1;
        }else{
            dp[l][l+1][0]=0;
            dp[l][l+1][1]=0;
        }
    }

    for(int l=n-2;l>=1;l--){
        for(int r=l+2;r<=n;r++){
            if(num[l]<num[l+1]){
                dp[l][r][0]+=(dp[l+1][r][0])%mod;
            }
            if(num[l]<num[r]){
                dp[l][r][0]+=(dp[l+1][r][1])%mod;
            }
            if(num[r]>num[r-1]){
                dp[l][r][1]+=(dp[l][r-1][1])%mod;
            }
            if(num[r]>num[l]){
                dp[l][r][1]+=(dp[l][r-1][0])%mod;
            }
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%mod;
    return 0;

}