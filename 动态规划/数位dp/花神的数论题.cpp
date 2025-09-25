#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

#define int long long 
const int mod=1e7+7;

int a[55];
int dp[55][55];
int n;

/*

    dp第一维：已经走过的长度，用len表示
    dp第二维：已经有的1的个数，用sum表示


    st表示

*/

int qmi(int a,int b){
    int res=1;
    while(b){
        res=res*(b&1?a:1)%p,
        a=a*a%p,
        b>>=1;
    }
    return res;
}

int dfs(int cur,int limit,int tmp,int sum){
    if(dp[len][sum]!=-1) return dp[len][sum];

    if(free==1){

    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    
}