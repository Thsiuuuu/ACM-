#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
const int N=100010,M=500010;

/*

    每次选出最小的未加入确定最短路集合的点，并加入确定的集合
    然后进行松弛


*/



struct edge{
    int  to,dis,next;
};

edge e[M];
int head[N],dis[N],cnt;
bool vis[N];
int  n,m,s;

void add(int u,int v,int d){
    cnt++;
    e[cnt].dis=d;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}

struct node{
    int dis;
    int pos;
    bool operator<(const node&x)const{
        return x.dis<dis;
    } 
};

std::priority_queue<node>q;

void dijkstra(){
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int x=tmp.pos,d=tmp.dis;
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i;i=e[i].next){
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].dis){
                dis[y]=dis[x]+e[i].dis;
                if(!vis[y]){
                    q.push((node){dis[y],y});
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;i++) dis[i]=0x7fffffff;
    for(int i=0;i<m;i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        add(u,v,d);
    }
    dijkstra();
    for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    return 0;
}