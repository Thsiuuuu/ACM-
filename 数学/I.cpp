#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

/*


    思路:
    可以将a=k1*n,b=k2*n
    则lcm(a,b)=m=a*b/gcd(a,b)=a*b/n=k1*k2*n
    m/n=k1*k2，
    所以这里k1,k2一定是m/n的因子，筛选质因子即可求出k1+k2最小值
    然后注意这里gcd(k1,k2)=1
*/

int gcd(int a,int b){
    return !b?a:gcd(b,a%b);
}

void sol(){
    int m,n;
    cin>>m>>n;

    int con=n/m;
    int ans=114514519191;
    for(int i=1;i*i<=con;i++){
        if((con%i==0)&&(gcd(i,con/i)==1)){
            ans=min(ans,i+(con/i));
        }
    }
    cout<<ans*m<<'\n';


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}