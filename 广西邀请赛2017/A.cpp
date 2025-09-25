#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define int long  long 

int qmi(int a,int b){
    int ans=0;
    while(b){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}

void sol(){
    int n;
    cin>>n;
    int lim=20;
    while(lim){
        if(qmi(lim,lim)<=n){
            cout<<lim<<'\n';
            return ;
        }
        lim--;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
}