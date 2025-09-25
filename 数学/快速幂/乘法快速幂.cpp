#include <iostream>
#include <algorithm>


using namespace std;
#define int long long 



/*

    求a的b次方，可以把b拆成二进制形式的数
    拆完之后，可以搞成二进制下各个a的2的对应次方的乘积
    这里需要a的二的等比次方,1,2,4,8等等，直接对a进行乘方即可


*/

int qmi(int a,int b,int p){
    int ans=1;
    while(b){
        if((b&1)==1){
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int a,b,p;
    scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,qmi(a,b,p));
    return 0;

}   