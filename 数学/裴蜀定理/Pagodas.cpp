#include <iostream>
#include <algorithm>

using namespace std;

/*

    开局选两个，那么之后一定是他们的线性组合
    又根据裴蜀定理，任意的x,y,都有gcd(a,b)|ax+by成立
    所以说每个点都可以被弄出来

*/

int gcd(int  a,int b){
    return b?gcd(b,a%b):a;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int mid=gcd(a,b);
        if(((n)/mid)&1){
            printf("Case #%d: Yuwgna\n",i);
        }else{
            printf("Case #%d: Iaka\n",i);
        }
    }
    return 0;
}

