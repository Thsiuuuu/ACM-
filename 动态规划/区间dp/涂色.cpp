#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


#define int long long 

const int maxn=55;

int dp[55][55];

int n;
string s;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>s;
    n=s.size();
    s=" "+s;

    memset(dp,0x3f3f3f,sizeof(dp));
    

    for(int  i=n;i>0;i--){
        for(int  j=i;j<=n;j++){
            if(i==j) dp[i][j]=1;
            else if(s[i]==s[j]){
                dp[i][j]=dp[i][j-1];
            }else{
                for(int k=0;k<j-i;k++){
                    dp[i][j]=min(dp[i][j],dp[i][i+k]+dp[i+k+1][j]);
                }
            }
        }
    }

    cout<<dp[1][n];
    return 0;

}