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

    异或
    考虑每一位的贡献

    一直贴着上界的情况下且当前位置为1的情况下，有两种选法

    选0或者选1,所有数0多的情况下选1，否则选0,
    
    假设贪心不能得到最优解，那一定是有1选了0
    这个时候贪心做法最差比最优多了1，说明贪心得到的就是最优解
    

    
*/

const int N=45;
int num[N];
bool st=true;
int n,k,x,cnt1=0,cnt0=0,res=0;


void sol(){


   memset(num,0,sizeof(num));
   cin>>n>>k;
   for(int i=0;i<n;i++){
        cin>>x;
        for(int j=41;j>=0;j--){
            if((x>>j)&1) num[j]++;
        }
   }


   for(int i=41;i>=0;i--){

        cnt1=num[i],cnt0=n-num[i];

        if(!st){
            res+=(1LL<<i)*(max(cnt1,cnt0));
            continue;
        }

        if((k>>i)&1){
            if(cnt1>cnt0){
                st=false;
                res+=(1LL<<i)*cnt1;
            }
            else res+=(1LL<<i)*cnt0;
        }else{
            res+=(1LL<<i)*cnt1;
        }

   }
    
   cout<<res;
    
    
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}