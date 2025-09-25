#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define int __int128
const int N=1e5+10;
int m[N],r[N];

int n;
int x,y;

int read(){
    int x=0;
    int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

void print(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int exgcd(int a,int b,int& x,int& y){
    if(!b) return a,x=1,y=0;
    int r=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}

int excrt(int n){
    int tail=0,lcm=1,tmp,b,c,x0;
    for(int i=1;i<=n;i++){
        b=m[i];
        c=((r[i]-tail)%b+b)%b;
        int d=exgcd(lcm,b,x,y);
        if(c%d){
            return -1;
        }

        x0=(x*(c/d))%(b/d);
        if(x0<0) x0+=(b/d);
        tmp=lcm*(b/d);
        
        tail=(tail+lcm*x0)%tmp;
        lcm=tmp;
    }
    return tail;
}

signed main(){
    // ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    n=read();
    for(int i=1;i<=n;i++){
        m[i]=read();
        r[i]=read();
    }
    print(excrt(n));
    return 0;
}