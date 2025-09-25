#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define int long long 

typedef pair<int,int> pii;

map<pair<pii,int>,int> mp;
const int N=25;
int num[N][N],ans;
int n;
/*


    考虑折半搜索，然后因为折半的话，一条路径必定在右上到左下的斜对角线上有交点
    并且如果一条路径异或和为0的话，必定可以被拆成两个相等的数
    所以统计所有斜对角线上对应的数字即可

*/

void dfs1(int x,int y,int sum){
    
    if(x+y==n-1){
        mp[{{x,y},sum}]++;
        return ;
    }

    if(x+1<n)   dfs1(x+1,y,sum^num[x+1][y]);
    
    if(y+1<n)   dfs1(x,y+1,sum^num[x][y+1]);
}

void dfs2(int x,int y,int sum){
    if(x+y==n-1){
        ans+=mp[{{x,y},sum^num[x][y]}];
        return ;
    }
    if(x-1>=0)   dfs2(x-1,y,sum^num[x-1][y]);
    if(y-1>=0)   dfs2(x,y-1,sum^num[x][y-1]);
}

signed main(){

    scanf("%lld",&n);
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&num[i][j]);
        }
    }

    dfs1(0,0,num[0][0]);
    dfs2(n-1,n-1,num[n-1][n-1]);
    printf("%lld",ans);
    return 0;
}