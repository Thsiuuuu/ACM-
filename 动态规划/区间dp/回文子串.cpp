#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


#define int long long 

/*

    dp[l][r]表示左右端点分别为l，r时所需最小变成的次数
    s[l]==s[r],dp[l][r]=dp[l+1][r-1]
    s[l]!=s[r],dp[l][r]=min(dp[l+1][r],dp[l][r-1])

*/

const int N=1010;
int dp[N][N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string s;
    cin>>s;
    memset(dp,0,sizeof(dp));
    int len=s.size();
    for(int i=0;i<len;i++){
        dp[i][i]=0;
    }
    for(int i=1;i<len;i++){
        if(s[i]!=s[i-1]) dp[i-1][i]=1; 
    }
    for(int l=len-3;l>=0;l--){
        for(int r=l+2;r<len;r++){
            if(s[l]==s[r]){
                dp[l][r]=dp[l+1][r-1];
            }else{
                dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
            }
        }
    }
    cout<<dp[0][len-1];
    return 0;

}