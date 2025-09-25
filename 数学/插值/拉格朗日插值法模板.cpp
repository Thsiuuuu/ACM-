#include <iostream>
#include <algorithm>

using namespace std;
#define int long long 

const int mod=998244353,N=2e3+10;

int x[N],y[N];
int n,k;
int res=0;
int qmi(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }

    for(int i=1;i<=n;i++){
        
        int a=y[i],b=1;
        for(int j=1;j<=n;j++){
            if(i!=j){
                a=a*(k-x[j])%mod;
                b=b*(x[i]-x[j])%mod;
            }
        }
        res=(res+a*qmi(b,mod-2)%mod)%mod;
    }
    cout<<(res+mod)%mod;//可能出现结果是负数的情况
    return 0;
}