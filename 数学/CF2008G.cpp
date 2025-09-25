#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long 

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void sol(){
    int n,k;
    cin>>n>>k;
    if(n==1){
        int x;
        cin>>x;
        if(x>=0&&x<=k-1) cout<<k<<'\n';
        else cout<<k-1<<'\n';
    }else{
        int g=0;//因为gcd函数为0的时候返回a，所以当第一项输入的时候得到的还是第一项
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            g=gcd(g,x);
        }
        k--;
        int c=1;
        for(int i=0;i<n;i++){
            if(i<(n-1)&&k>=(g-1)) k-=(g-1);
            else{
                cout<<c+k<<'\n';
            }
            c+=g;
        }
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
    return 0;
}