#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=10010;
int  money[maxn],dp[maxn];
int n,w,ans;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>money[i];
    }

    for(int i=1;i<=w;i++){
        dp[i]=1145141919l;
    }

    dp[0]=0;
    for(int i=1;i<=w;i++){
        for(int j=0;j<n;j++){
            if(i>=money[j]){
                dp[i]=min(dp[i],dp[i-money[j]]+1);
            }
        }
    }
    cout<<dp[w];

    return 0;

}