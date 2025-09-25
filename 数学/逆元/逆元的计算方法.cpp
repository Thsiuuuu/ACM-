#include <iostream>
#include <algorithm>

using namespace std;

/*

    可以使用逆元的条件

    (1)a/b可以整除
    (2)mod是质数
    (3)b和mod的最大公约数是1


*/



#define int long long 


int qmi(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
}

signed main(){
    int a,b;
    mod=41;

    cin>>a>>b;
    int inv=qmi(b,mod-2,mod);
    cout<<inv//逆元
    cout<<((a%mod)*inv)/mod;//利用逆元的除法

    return 0;
}