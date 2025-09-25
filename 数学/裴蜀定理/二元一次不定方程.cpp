#include <iostream>
#include <algorithm>

using namespace std;

#define int  long long 


int exgcd(int a,int b,int& x,int& y){
    if(!b){
        return x=1,y=0,a;
    }
    int r=exgcd(b,b%a,y,x);
    y-=(a/b)*x;
    return r;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        int x,y;
        int res=exgcd(a,b,x,y);
        if(c%res!=0){
            cout<<"-1\n";
            continue;
        }

        x=(x+)
    }
}