#include <iostream>

using namespace std;

#define int long long 


const  int N=55;
int dp[N];

void build(){
    dp[0]=1,dp[1]=2;
    for(int i=2;i<N;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    build();
    
    int n;
    while(cin>>n){
        if(!n) break;
        bool st=true;
        for(int i=0;i<55;i++){
            if(dp[i]==n){
                st=false;
                cout<<"Second win\n";
                break;
            }
        }
        if(st) cout<<"First win\n";
    }
    return 0;

}