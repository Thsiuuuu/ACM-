#include <iostream>
#include <algorithm>

using namespace std;
#define int long long 

const int mod=998244353;
const int  N=5e6+10;

int fac[N],inv[N];

int qmi(int a,int  b){
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

void build(){

    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<=N-1;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    
    inv[N-1]=qmi(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--){
        inv[i]=((i+1)*inv[i+1])%mod;
    }
}

int c(int n,int m){
    int  ans=fac[n];
    ans=(ans*inv[m])%mod;
    ans=(ans*inv[n-m])%mod;
    return ans%mod;
}

int sol(){
    int n,m;
    cin>>n>>m;
    return c(n,m);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int ans=0;
    int  t,x;
    cin>>t>>x;
    build();
    while(t--){ 
        ans^=sol();
    }
    cout<<ans%mod;
    return 0;
}