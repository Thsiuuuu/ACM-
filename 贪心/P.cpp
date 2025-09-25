#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>


using namespace std;

#define int long long 

/*

    这里因为2的幂次很特殊

    能够构成三角形的有二种：
    1、三个一样长度的
    2、两个大的，一个小的

    
    这两个哪个优先去算呢，如果数据很散，那方法2能够得到更多的三角形


    所以优先考虑二，其次考虑一

*/





void sol(){


   int n,ans=0,sum=0;
   cin>>n;
   vector<int> num(n);
   for(int i=0;i<n;i++){
        cin>>num[i];
        if(sum<num[i]/2){
            ans+=(sum+num[i])/3;
            sum=(sum+num[i])%3;
        }else{
            ans+=(num[i])/2;
            sum=(sum-num[i]/2+num[i]%2);
        }
   }

   cout<<ans;

}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}