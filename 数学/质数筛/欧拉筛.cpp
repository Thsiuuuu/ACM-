#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    bool visit[n+1];
    int prime[n/2+1];
    int cnt=0;
    //每个数都一定由自己最小的质因数被除掉
    //但是要判断一下如果一个数能够被当前的因子整除的话
    //那么到了他们之间的质因子时，就不是一个数被最小的质因数整除了，因为大的数可以被拆解为它的因子
    for(int i=2;i<=n;i++){
        if(!visit[i]){
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>n){
                break;
            }
            visit[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    cout<<cnt;
}