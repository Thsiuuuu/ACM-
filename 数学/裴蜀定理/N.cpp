#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

/*


    追击问题
    走了t时间后恰好相遇，
    那么有x+mt-(y+nt)=l*k
    移项可得l*k+(n-m)*t=x-y；
    也就是要求t的最小正整数解，所以就是一个

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

    int x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    
    int tr1,tr2;
    int a=n-m,b=x-y;
    if(a<0){
        a=-a,b=-b;
    }
    int g=exgcd(a,l,tr1,tr2);
    if((b)%g!=0||n==m){
        cout<<"Impossible";
    }else{
        tr1=tr1*(b)/g;
        cout<<(tr1%(l/g)+l/g)%(l/g);
    }
    return 0;
}