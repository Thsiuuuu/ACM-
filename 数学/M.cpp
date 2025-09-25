#include <iostream>
#include <algorithm>

using namespace std;

/*

    可以从数学上转换一下
    因为原始公式相当于每个分子相同的加在一起，换一下序
    就相当于先求同分母的，再求同分子的

    用前缀和预处理一下
    上面的想法不对，因为没看到下取整

    
    这个东西可以拿整数分块做

    每个数做分母的时候，分子只需要从自己开始算就可以了
    所以可以换一下序
    然后分子相同的情况下，例如整数i作分母，最多有i个值使得j/i相同
    然后可以分成一段一段的
    利用一个数做因子的时候，有长度相同的循环节来计算
    总的时间复杂度是O(n)
*/
#define int long long 


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            int len=n-i+1,num=len/i;
            ans+=(num*(num+1)*i/2+(len-num*i)*(num+1));
        }
        cout<<ans<<'\n';
    }
    return 0;
}