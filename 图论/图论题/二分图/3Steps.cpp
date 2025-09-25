#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
/*

    首先这个题要想到什么时候能连边，3个的时候一定能连边，
    原始3个是一定可以的，如果包含新生成的呢，新生成其实是在原来的基础上减少两条边的产物
    也就是说任意的包含新边构成的三个边的组合当中，是通过原有走过的边减了很多的2导致的
    减2并不会改变奇偶性，退化到原始3，也就是说任意的奇数都是可以的

    怎么知道有多少路径长度是奇数的点呢，可以联想到二分图
    二分图情况下对立集合的任意两点路径都是奇数
    但是不是二分图，就会有奇环，可以通过走奇环的方式构成一个完全图，任意两点都是可连接的

*/
#define int long long 

const int N=1e5+10;
vector<int> e[N];
int col[N];
int sum[3];
int n,m;
int ans=0;
bool flag;

bool dfs(int u,int c){
    col[u]=c;
    sum[col[u]]++;
    for(int v:e[u]){
        if(!col[v]){
            if(dfs(v,3-c)){
                return true;
            }
        }
        else if(col[v]==c){
            return true;
        }
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!col[i]){
            flag=dfs(i,1);
            if(flag){
                break;
            }
        }
    }

    if(flag){
        ans+=(n*(n-1)/2);
    }else{
        ans+=(sum[1]*sum[2]);
    }
    cout<<ans-m;
    return 0;
}