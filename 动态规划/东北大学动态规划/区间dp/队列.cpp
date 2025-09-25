#include <algorithm>
#include <iostream>


using namespace std;
#define int long long

int n,ans,sum[3005],a[3005],dp[3005][3005];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    for(int i=1;i<=n;i++) dp[i][i]=a[i];
    for(int len=2;len<=n;len++){
        for(int l=1,r=l+len-1;r<=n;r++,l++){
            dp[l][r]=max(sum[r]-sum[l-1]-dp[l+1][r],sum[r]-sum[l-1]-dp[l][r-1]);
        }
    }

    cout<<dp[1][n]-(sum[n]-dp[1][n]);
    return 0;
}