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

    十进制转二进制
    十进制不断除以2，每次余数从低到高放入二进制位
    商继续除以2，直到商为0为止

*/

/*
    >>1和/2等价，都是除以二向下取整
*/

/*

  思路：
  找到第一个异或值为1的状态
  r是上限，l是下限，找到从高位到低位第一个异或值为1的状态
  根据贪心（类似于数位dp）的思想
  其余的低位就可以构造出异或值都为1的状态
*/


void sol(){

    int l,r;
    cin>>l>>r;

    int x=l^r;//显然直接异或上更省力
    int  ans=0;
    while(x){
        x>>=1;
        ans++;
    }
    cout<<(1LL<<ans)-1;//更快计算二的幂次
    
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}