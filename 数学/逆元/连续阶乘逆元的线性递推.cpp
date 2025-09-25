#include <iostream>
#include <algorithm>

using namespace std;

const int N=1000000007;
const int limit=1000;

int fac[limit+1];//fac表示i!在mod下的余数
int inv[limit+1];//inv表示i!在mod下的逆元

int  qmi(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%Mod;
        b>>=1;
    }
    return ans;
}


void build(){
    fac[1]=1;
    for(int i=2;i<=limit;i++){
        fac[i]=(i*fac[i-1])%mod;
    }

    inv[limit]=qmi(fac[limit],mod-2);
    for(int i=limit-1;i>=0;i--){
        inv[i]=((i+1)*inv[i+1])%mod;
    }
}

