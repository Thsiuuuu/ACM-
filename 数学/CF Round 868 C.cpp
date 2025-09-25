#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
/*

    考虑对每一个a数进行正整数分解，
    分解成若干质因子
    两个相同的质因子，可以构造出一个强合数
    两个不同的质因子，不能构造，因为2个质因子，一个合因子（自身）
    优先选两个的，然后剩下的单个的质因子以三为单位进行构造

    自己写的代码的时间复杂度是O(t*(m^(n/2)))
    不如直接跑得快
    

*/
#define int  long long 
// map<int,int> cnt;//map对时间复杂度有影响
int t;

// void check(int n){
//     cnt.clear();
//     num.clear();
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0){
//             num.push_back(i);
//             while(n%i==0){
//                 cnt[i]++;
//                 n/=i;
//             }
//         }
//     }
//     if(n>1) cnt[n]++;
//     num.push_back(n);
// }

void sol(){
    int n;
    cin>>n;


    map<int,int> a;
    int ans=0,ret=0,tmp=0;//ret统计落单的数字个数
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int i=2;i*i<=x;i++){
            while(x%i==0){
                a[i]++;
                x/=i;
            }
        }
        if(x>1) a[x]++;
    }

    for(auto [num,cnt]:a){
        ans+=(cnt/2);
        ret+=(cnt%2);
    }
    
    ans+=(ret/3);//三个数一组进行构造
    if(!ans){//ans为0，只有可能质因子数量<=2.任意大于等于3数量的质因子都可以对ans有一个贡献
        cout<<"0\n";
    }else{
        cout<<ans<<"\n";
    }
    
}

signed main(){
    cin>>t;
    while(t--){
        sol();
    }
}
