#include <iostream>
#include <algorithm>

using namespace std;


#define int long long 

const int maxn=2510;

int dp[maxn],tme[maxn],sum[maxn]={0};

signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tme[i];
    }

    sum[1]=tme[1];
    for(int i=2;i<=n;i++){
        sum[i]=(tme[i]+sum[i-1]);
    }
    for(int i=1;i<=n;i++) sum[i]+=2*m;

    //for(int i=0;i<=n;i++) cout<<sum[i]<<" ";
    //cout<<"\n";


    for(int i=0;i<=n;i++) dp[i]=1145141919; 
    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            //cout<<i<<" "<<j<<" "<<sum[i-j]<<" "<<dp[i]<<"\n";
            dp[i]=min(dp[i],dp[j]+sum[i-j]);
        }
        
    }


    //for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
    cout<<dp[n]-m;
    return 0;

}