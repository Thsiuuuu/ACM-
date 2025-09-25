#include <iostream>
#include <algorithm>

using namespace std;

#define int long  long 


/*

    求逆元模板题
    ax和1同余，在modb的情况下，意味着a和b互质
    那这里就采用扩展欧几里得算法

*/

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        return x=1,y=0,a;
    }

    int r=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int a,b,x,y;
    cin>>a>>b;
    exgcd(a,b,x,y);
    cout<<(x%b+b)%b;//取模运算一定会把数压缩到(-b,b)区间，所以说能得到最小逆元
    return 0;
    
}