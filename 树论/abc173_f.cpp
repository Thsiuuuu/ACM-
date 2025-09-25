#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long 
/*


    感觉是诈骗题，读完题会发现，两个点构成的子图，有两种情况
    一种是父子关系，这个时候联通分量数量为1
    第二种是非父子关系，这个时候联通分量数量为2
    然后dfs记录一下有多少对父子关系即可


    第一次看错题了，以为是路径集合，实际是编号集合
    这个题首先分析一下，这个大的公式如果直接去计算的话，肯定会超时
    所以必然要通过什么方法进行转化，
    然后去想，任一一对端点之间，构成的子图，一定是一个森林，
    然后我们就可以得出来，点数=边数+联通块个数
    很显然联通块个数就是我们要求的f
    那么就可以把联通块个数转化成[l,r]的范围之内，V-E的大小
    然后这个时候还是，正着想不好想，也就是任一一个区间上，出现了多少的点和边
    可以反过来统计每一个点和边对所有区间的贡献
    一个点u必然在1<=l<=u,u<=r<=n的范围内，一个点的贡献就是(u)*(n-u+1)
    一条边u,v,不妨设u<v，必然在1<=l<=u,v<=r<=n,一条边的贡献就是(u)*(n-v+1)
*/

const int N=2e5+10;
vector<int>e[N];
int n;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    
    cin>>n;
    int ans=0;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        ans+=(i*(n-i+1));
        ans-=(u*(n-v+1));
    }
    ans+=n;
    cout<<ans;
    return 0;
}