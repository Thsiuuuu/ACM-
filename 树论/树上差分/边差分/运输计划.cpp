#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/*


    首先最大值最小考虑二分，这里对答案进行二分，
    如果一个值是符合题意的，那么比它大的一定符合题意，不用管
    比它小的有可能符合题意，需要找一下

    然后对于一个值，怎么知道这样是合法的，也就是说能不能构造出这样的情况
    因为它是最大值，所以说任何一个超过这个值的代价的路径一定要削减
    并且说削减的这条边也一定要是包含在所有非法路径的里面

    这个时候二分的时间复杂度是O(log(nt))的时间复杂度，最大不超过30
    然后考虑如何找出这一条边
    所有非法路径进行覆盖的情况下，例如这个时候为cnt,那么cnt一定等于其中某一条线段的覆盖数
    并且在这条线段被删掉的情况下，非法最大值是一定要小于枚举的最大值的，不然不行
    那么怎么快速打标记就是一个问题了，因为遍历一棵树的时间复杂度是O(n)的时间复杂度
    快速打标记就是需要边差分来解决了

    那么这里漏掉了一部分东西，比如u<->v，这样一条双向边进行边差分的时候，num[v]是表示对u和v之间的边的权值的修改值
    在这个题意里面+1也就可以理解为u到v的双向边是被覆盖过一次的


*/

const int N=3e5+10;
int n,m;

int num[N],headEdge[N],edgeTo[N<<1],edgeNext[N<<1],edgeWeight[N<<1],tcnt;
int headQuery[N],queryTo[N<<1],queryNext[N<<1],queryIndex[N<<1],qcnt;
bool visited[N];
int unionfind[N],quesu[N],quesv[N],dist[N],lca[N],cost[N],mxc,obj,cnt;

void build(){
    tcnt=qcnt=1;
    for(int i=1;i<=n;i++){
        visited[i]=false;
        unionfind[i]=i;
        quesu[i]=0;
        quesv[i]=0;
    }
}

void addEdge(int u,int v,int w){
    edgeNext[tcnt]=headEdge[u];
    edgeTo[tcnt]=v;
    edgeWeight[tcnt]=w;
    headEdge[u]=tcnt++;
}

void addQuery(int u,int v,int i){
    queryNext[qcnt]=headQuery[u];
    queryTo[qcnt]=v;
    queryIndex[qcnt]=i;
    headQuery[u]=qcnt++;
}

int find(int i){
    return unionfind[i]^i?unionfind[i]=find(unionfind[i]):i;
}

void tarjan(int u,int f,int w){
    visited[u]=true;
    dist[u]=dist[f]+w;
    for(int e=headEdge[u],v;e;e=edgeNext[e]){
        v=edgeTo[e];
        if(v!=f){
            tarjan(v,u,edgeWeight[e]);
        }
    }
    for(int e=headQuery[u],v;e;e=queryNext[e]){
        v=queryTo[e];
        if(visited[v]){
            int i=queryIndex[e];
            lca[i]=find(v);
            cost[i]=dist[u]+dist[v]-2*dist[lca[i]];
            mxc=max(mxc,cost[i]);
        }
    }
    unionfind[u]=f;
}

bool dfs(int u,int f,int w){
    for(int e=headEdge[u],v;e;e=edgeNext[e]){
        v=edgeTo[e];
        if(v^f){
            if(dfs(v,u,edgeWeight[e])){
                return true;
            }
            num[u]+=num[v];
        }
    }
    return (num[u]==cnt&&w>=obj);
}

bool f(int limit){
    obj=mxc-limit;
    for(int i=1;i<=n;i++){
        num[i]=0;

    }
    cnt=0;
    for(int i=1;i<=m;i++){
        if(cost[i]>limit){
            num[quesu[i]]++;
            num[quesv[i]]++;
            num[lca[i]]-=2;
            cnt++;
        }
    }
    if(!cnt){
        return true;
    }
    return dfs(1,0,0);
}

int compute(){
    tarjan(1,0,0);
    int l=0,r=mxc;
    int ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(f(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    build();
    cin>>m;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        quesu[i]=u;
        quesv[i]=v;
        addQuery(u,v,i);
        addQuery(v,u,i);
    }
    cout<<compute();
    return 0;
}

