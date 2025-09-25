#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*

    和上一个枚举一样的思路，算一下时间复杂度就好

*/

#define int long long

int qmi(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        b>>=1;
        a*=a;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int ans=0;
        for(int a=1;3*qmi(a,2)<=n&&3*a<=x;a++){
            for(int b=a;qmi(b,2)<=n&&2*b<=x;b++){
                for(int c=b;a*b+a*c+b*c<=n&&a+b+c<=x;c++){
                    if(a==b&&b==c) ans++;
                    else if(a<b&&b<c) ans+=6;
                    else ans+=3;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}