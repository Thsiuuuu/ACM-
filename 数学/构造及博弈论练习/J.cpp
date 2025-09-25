#include <iostream>
#include <vector>
using namespace std;

#define int long  long 

/*

    首先可以尝试画一下什么样的可以
    发现每个两个这样摆都是可以的

    那怎么证呢，
    题目里已经给出了一个长度范围存在的情况
    尝试在这个基础上进行推理
    任取一个点，如果放在原有的塔上面，一定会覆盖这个塔
    如果不在原有的塔的上面，也会覆盖其周围的塔，周围必存在一个塔

    那这样，我们任取一个点出发，每次做一个并取未被覆盖的部分
    则每次一定会覆盖一个之前未存在的原有的塔并还原这个塔的覆盖范围
    因此结论成立

*/

const int N=1e6+10;

int to[N<<1],nxt[N<<1],head[N];

int cnt=0;
void add(int u,int  v){
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}

bool vis[N];
vector<int> ans;
void dfs(int u,int fa,int dep){
    // if(vis[u]) return ;
    vis[u]=true;
    if(dep>=2){
        return ;
    }
    
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u,dep+1);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i,0,0);
        ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}