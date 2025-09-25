#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

/*

    这个题数据范围过大，过大的可以考虑会不会有重复，有重复可以减掉
    显然以10007作为模数，那么超过10007的数与在1~10007范围内对应的数是同余的，所以超过10007的数可以直接用1~10007范围内的数计算

*/

const int mod=10007;
int  qmi(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        int ans=0;
        if(n<=10007){
            for(int i=1;i<=n;i++){
                ans=(ans+qmi(i,k))%mod;
            }
        }else{
            for(int i=1;i<=10007;i++){
                ans=(ans+qmi(i,k))%mod;
            }
            int res=n%10007;
            ans=(ans*(n/10007)%mod)%mod;
            for(int i=1;i<=res;i++){
                ans=(ans+qmi(i,k))%mod;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}