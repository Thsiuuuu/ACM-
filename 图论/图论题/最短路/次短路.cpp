#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

#define int long long 

/*

    怎么求次短路呢，
    次短路和最短路一定有一条边不是共有的
    所以一次删去最短路径上每一条边，分别跑一遍最短路并取最小值即可


*/

#define pdi pair<double,int>

struct Node{
    double x,y;
    int head;
    double dis;
    int prev;
}node[205];

struct Edge{
    int next,to;
    double len;
}edge[50005];

int n,m,cnt;
double ans=INT_MAX;

double calc(double a,double b,double c,double d){
    return (double)sqrt(double(a-c)*double(a-c)+double(b-d)*double(b-d));
}

void add(int u,int v,double w){
    edge[++cnt].len=w;
    edge[cnt].to=v;
    edge[cnt].next=node[u].head;
    node[u].head=cnt;
}

void dijkstra(int x,int y){
    for(int i=1;i<=n;i++){
        node[i].dis=INT_MAX;
    }

    node[1].dis=0;
    priority_queue<pdi,vector<pdi>,greater<pdi>> q;
    q.push({0,1});
    while(q.size()){
        pdi tmp=q.top();
        q.pop();
        double d=tmp.first;
        int u=tmp.second;
        if(node[u].dis!=d) continue;
        for(int e=node[u].head;e;e=edge[e].next){
            int v=edge[e].to;
            if((u==x&&v==y)||(u==y&&v==x)) continue;
            if(node[v].dis<=d+edge[e].len) continue;
            if(x==-1&&t==-1) node[v].prev=u;
            node[v].dis=d+edge[e].len;
            q.push({node[v].dis,v});
        }
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>node[i].x>>node[i].y;
    }
   
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        double w=calc(node[u].x,node[u].y,node[v].x,node[v].y);
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra(-1,-1);
    for(int i=n;i!=1;i=node[i].prev){
        dijkstra(i,node[i].prev);
        ans=min(ans,node[n].dis);
    }

    if(ans>=INT_MAX) cout<<"-1";
    else cout<<fixed<<setprecision(2)<<ans;
    return 0;

}