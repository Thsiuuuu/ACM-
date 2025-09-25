#include <iostream>
#include <algorithm>

using namespace std;

#define int long  long 

/*

    对于每组样例进行分解质因数

    想简单了，因为这个数可能有多个因子并且还是一个乘方的形式
    那这里
    首先一个因子的幂次，可以被分解为相等的幂次的因子份的数
    能把这些因子分解出来，那么一定是它的公约数，
    p最多的时候就是他们的最大公约数

    注意负数的情况
    负数只能这个p次方是奇数次才能得到负数


*/

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    scanf("%lld",&t);
    for(int j=1;j<=t;j++){
        int n;
        scanf("%lld",&n);

        int ans=0,cnt=0;

        for(int i=2;i*i<=abs(n);i++){
            while(abs(n)%i==0&&abs(n)>1){//没有检查除完之后还能不能被整除
                n/=i;
                cnt++;
            }
            ans=gcd(cnt,ans);
            cnt=0;
        }
        if(abs(n)>1){
            ans=1;
        }
        while(n<0&&((ans&1)==0)){
            ans/=2;
        }
        printf("Case %lld: %lld\n",j,ans);
    }
    return 0;
}

