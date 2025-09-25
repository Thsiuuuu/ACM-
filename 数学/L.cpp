#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

/*

    数论分块，
    每个向下取整的都可以分成一块一块的
    形如Σf(i)*(n/i);的形式，需要先预处理f(i)的前缀和，降低时间复杂度
*/

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,k,ans;
    
    
    cin>>n>>k;
    ans=n*k;
    for(int l=1,r;l<=n;l=r+1){
        if(k/l){
            r=min(k/(k/l),n);//要判断边界，看看右边界会不会超过k和n
        }else{
            r=n;
        }
        ans-=((k/l)*(r-l+1)*(l+r)/2);
    }
    cout<<ans;
    return 0;
}



