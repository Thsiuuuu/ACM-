#include <iostream>
#include <algorithm>

using namespace std;

/*

    思想：
    >=2的偶数一定是合数
    只需要从>=3的奇数当中剔除合数，那么剩下的一定是质数

*/

int main(){
    int n;
    cin>>n;
    if(n<=1){
        cout<<0;
        return 0;
    }

    bool visit[n+1];
    int cnt=(n+1)/2;
    for(int i=3;i*i<=n;i++){
        if(!visit[i]){
            for(int j=i*i;j<=n;j+=2*i){//因为+i之后一定是偶数，偶数不需要判断，所以每次+2判断奇数即可
                if(!visit[j]){
                    visit[j]=true;
                    cnt--;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}