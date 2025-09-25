#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;
#define int long long


const int num=403;
int n;
int a[num],b[num],dp[num][num];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }

    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++) dp[i][i]=0;

    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+b[j]-b[i-1]);            
            }
        }
    }

    cout<<dp[1][n];
    return 0;
}