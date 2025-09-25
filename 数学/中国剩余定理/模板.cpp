#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int N=11;
int num[N];
int r[N];

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        return x=1,y=0,a;
    }
    int r=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}

int crt(int  n){

    int lcm=1,ans=0;
    for(int i=1;i<=n;i++){
        lcm*=num[i];
    }

    for(int i=1;i<=n;i++){
        __int128 res=lcm/num[i];
        int x,y;
        exgcd(res,num[i],x,y);
        ans=ans+r[i]*res*x%lcm;
    }
    return (ans%lcm+lcm)%lcm;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>r[i];
    }
    
    cout<<crt(n);

    return 0;

}