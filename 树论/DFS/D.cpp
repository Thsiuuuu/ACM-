#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define int long long 
#define pii pair<int,int>
const int mod=998244353;

/*

    这个题开始观察到了不是选根下面一个节点
    或者不是根节点时，选择不是一个父节点底下深度+1的点

    开始是从底下考虑的，但是忘了考虑选自身的情况了，而且太麻烦
    题解是从上向下考虑的，

    状态是以某个节点为终止点下有多少种走法
    这里优化了一下时间复杂度，要不然最坏会贴近O(n2)
    然后加和，并且利用上一层减去自己父节点的状态数量实现O(1)的查询


    总时间复杂度为O(n)

    突然想到为什么自己写的很麻烦了
    因为自己写的有多个变量，在起点动的同时终点也在动
    说白了还是没想清楚这个过程，开头很显然只能从头结点向下走，变的是终点
    所以设置状态为某一点为终点时总共有多少种情况

    不要过于思维定式，这个有点思维定式导致认为答案一定是树根的dp值了


*/

const int N=3e5+5;
vector<int> G[N];
int p[N],dep[N],ans[N];

void bfs(int  n){
    map<int,int>dep_ans;
    queue<int>q;
    for(auto v:G[1]){
        dep[v]=1;
        ans[v]=1;
        q.push(v);
        dep_ans[dep[v]]+=1;
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:G[u]){
            q.push(v);
            dep[v]=dep[u]+1;
            ans[v]=(mod+dep_ans[dep[u]]-ans[u])%mod;
            dep_ans[dep[v]]+=ans[v];
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=2;i<=n;i++){
            cin>>p[i];
            G[p[i]].push_back(i);
        }
        dep[1]=0;
        ans[1]=1;
        bfs(n);
        int res=0;
        for(int i=1;i<=n;i++){
            res+=ans[i];
            res%=mod;
        }
        cout<<res<<"\n";
    }
}