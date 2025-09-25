#include <iostream>

using namespace std;

/*

    分类讨论：
    1.只有1，奇数个先手必败，偶数先手必胜

    2.只有一堆大于1，其余小于等于1，则先手可以通过选一堆或一堆-1的数量调节使得自己必胜
    3.多堆大于1，这个时候观察异或值
    如果异或值不为0，则可以让对手异或值为0，而我们知道
    对于多堆石子，异或值为0的情况下，无法一步转移到状态1
    只能转化为异或值不为0的情况，而这些异或值不为0的情况当中，一定会转移到状态2
    也就是说，先手异或值不为0，必赢，否则必输

*/


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            sum+=(x==1?1:0);
            ans^=x;
        }
        if(sum==n){
            if((sum&1)==1) cout<<"Brother\n";
            else cout<<"John\n";
        }else if(ans!=0){
            cout<<"John\n";
        }else cout<<"Brother\n";
    }
    return 0;
}