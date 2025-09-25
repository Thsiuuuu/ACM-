#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*

    考虑线性dp
    因为只有1和2两种，并且有翻转和不翻转两种状态

*/

const int N=2010;
int dp[5],x;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        dp[1]=(dp[1]+(x==1));
        dp[2]=max(dp[1],dp[2]+(x==2));
        dp[3]=max(dp[2],dp[3]+(x==1));
        dp[4]=max(dp[3],dp[4]+(x==2));
    }
    cout<<dp[4];
    return 0;

}