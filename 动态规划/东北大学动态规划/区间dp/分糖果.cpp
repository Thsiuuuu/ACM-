#include <iostream>
#include <string>
#include <algorithm>

#define int long long

const int mod=1e9+7;
const int MK=1e5+5;
const int MN=105;

using namespace std;

int a[MN],dp[MN][MK],sum[MN][MK],n,k;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1][0]=sum[1][0]=1;
    for(int i=1;i<=k;i++) dp[1][i]=(i<=a[1]),sum[1][i]=dp[1][i]+sum[1][i-1];
    for(int i=2;i<=n;i++){
        dp[i][0]=sum[i][0]=1;
        for(int j=1;j<=k;j++){
            if(j<=a[i]) dp[i][j]=sum[i-1][j]%mod;
            else dp[i][j]=(sum[i-1][j]-sum[i-1][j-a[i]-1]+mod)%mod;
            sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
        }
    }
    cout<<dp[n][k];
} 
