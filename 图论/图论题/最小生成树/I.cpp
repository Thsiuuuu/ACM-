#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define int long long 
#define pii pair<int,int> 
#define piii pair<int,pii> 
/*

    因为这个题实际是想建立一个联通的图

    显然如果没有自己建立点，那么就是求最小生成树，但是自己也可以建点
    那怎么解决这个问题呢，最小生成树维护的是节点之间的关系，
    自己节点选择与否可以再建立一个虚拟节点解决，这个和选课以及软件安装处理点很相似
    这里拿prim算法练练手

*/

const int N=2010;

int n,cnt,cot;
int tot;
int x[N],y[N];
int c[N],k[N],dis[N];
bool vis[N],ok[N];
vector<pii> son[N];
priority_queue<piii,vector<piii>,greater<piii>> q;


struct edge{
    int u,v;
    int w;
}ans[N];

void prim(int s){
    q.push({0,{s,0}});
    for(int i=0;i<=n;i++){
        dis[i]=1e18;
    }
    dis[s]=0;
    while(!q.empty()){
        piii it=q.top();
        q.pop();
        int u=it.second.first;
        if(vis[u]) continue;
        cnt++;
        tot+=dis[u];
        vis[u]=1;
        ans[cnt]=edge{it.second.second,it.second.first,dis[u]};

        if(it.second.second==0){
            ok[u]=1;
            cot++;
        }
        if(cnt>=n+1) return ;
        for(auto it:son[u]){
            int v=it.first;
            int w=it.second;
            if(dis[v]>w){
                dis[v]=w;
                q.push({dis[v],{v,u}});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }

    for(int i=1;i<=n;i++){
        cin>>c[i];
        son[0].push_back({i,c[i]});
    }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<i;j++){
            int dis=abs(x[i]-x[j])+abs(y[i]-y[j]);
            dis=dis*(k[i]+k[j]);
            son[i].push_back({j,dis});
            son[j].push_back({i,dis});
        }
    }
    prim(0);
    cout<<tot<<"\n"<<cot-1<<"\n";
    for(int i=1;i<=n;i++){
        if(ok[i]) cout<<i<<" ";
    }
    cout<<"\n";
    int res=0;
    for(int i=1;i<=cnt;i++){
        if(ans[i].u!=0&&ans[i].v!=0)
        res++;
        }
    cout<<res<<"\n";
    for(int i=1;i<=cnt;i++){
        if(ans[i].u!=0&&ans[i].v!=0){
            cout<<ans[i].u<<" "<<ans[i].v<<"\n";        }
    }
}