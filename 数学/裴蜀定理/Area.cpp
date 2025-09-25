#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

int gcd(int  a,int b){
    return b?gcd(b,a%b):a;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        scanf("%lld",&n);
        int edges=0;
        double area=0;
        for(int j=1,x=0,y=0,dx,dy;j<=n;j++){
            scanf("%lld%lld",&dx,&dy);
            edges+=gcd(abs(dx),abs(dy));
            area+=x*(y+dy)-(x+dx)*y;
            x+=dx;
            y+=dy;
        }
        area/=2;
        int inners=(area)-edges/2+1;
        printf("Scenario #%lld:\n%lld %lld %.1f\n\n",i,inners,edges,area);
    }
    return 0;
}