#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=110;

int t;
int arr[maxn];
bool dp[25010];

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    
    while(t--){

        memset(dp,false,sizeof(dp));
        memset(arr,0,sizeof(arr));

        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr,arr+n);

        
        dp[0]=true;
        int ans=n;
        for(int i=0;i<n;i++){
            if(dp[arr[i]]){
                ans--;
            }else{
                for(int j=arr[i];j<=arr[n-1];j++){
                    dp[j]|=dp[j-arr[i]];
                }
            }

        }
        cout<<ans<<"\n";

    }
}