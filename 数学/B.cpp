#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

/*

    这个题可以预估一下数据范围，
    因为找5的个数，每隔5至少会出现一个5
    也就是5e8以内必然会出现答案
    然后二分答案就可以找到最小的n，因为5的数量单调不减


*/

int cnt(int n){
    int ans=0,num=5;
    while(num<=n){
        ans+=(n/num);
        num*=5;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int t;
    scanf("%lld",&t);
    for(int i=1;i<=t;i++){
        int q;
        scanf("%lld",&q);
        int l=5,r=500000100;
        while(l<r){
            int mid=(l+r)>>1;
            if(cnt(mid)<q){
                l=mid+1;
            }else if(cnt(mid)>q){
                r=mid-1;
            }else{
                r=mid;
            }
        }
        printf("Case %lld: ",i);
        if(cnt(l)==q){
            printf("%lld\n",l);
        }else{
            printf("impossible\n");
        }
    }

    return 0;
}