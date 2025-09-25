#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
/*

    对于每一个位置而言，一定是消掉这个数或者不消，
    不消就是dp[i-1]，消掉就是max(dp[j-1]+i-j+1)
    然后这样每次都会从前到自己遍历一次，总的时间复杂度是O(n2)的
    第二层for循环实际是在筛选最大的dp[j-1]+i-j+1，i是变量，所以是dp[j-1]-j+1要最大
    每次选完之后，维护一下这个值最大的dp[j-1]-j+1是什么就可以


*/

#define int long long 

int t;
void sol(){
    int n;
    cin>>n;
    vector<int> num(n+1);
    vector<int> dp(n+1,INT_MIN),mx(n+1,INT_MIN);

    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1],mx[num[i]]+i);
        mx[num[i]]=max(mx[num[i]],dp[i-1]-i+1);
    }
    cout<<dp[n]<<'\n';
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}