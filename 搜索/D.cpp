#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
struct opt
{
    char str[25];
    long long cost;
    bool operator <(opt a)const
    {
        return cost>a.cost;
    }
}op[35];
struct node
{
    int now[25];
    long long cost;
    bool operator <(node a)const
    {
        return cost>a.cost;
    }
}p;
int n,nop,nw;
int beg[25],goal[25];
int vis[2100000];
int hash(int now[])
{
    int h=0;
    for(int i=0;i<n;i++)
        h=(h<<1)+now[i];
    return h;
}
long long bfs()
{
    priority_queue<node> q;
    memset(vis,-1,sizeof vis);
    int h;
    h=hash(beg);
    vis[h]=0;
    memcpy(p.now,beg,n*sizeof(int));
    p.cost=0;
    q.push(p);
    while(!q.empty())
    {
        node top=q.top(); q.pop();
        if(memcmp(top.now,goal,n*sizeof(int))==0) return top.cost;
        for(int i=0;i<nop;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(op[i].str[j]=='N') p.now[j]=top.now[j];
                else if(op[i].str[j]=='F') p.now[j]=!top.now[j];
                else if(op[i].str[j]=='S') p.now[j]=1;
                else if(op[i].str[j]=='C') p.now[j]=0;
            }
            h=hash(p.now);
            p.cost=top.cost+op[i].cost;
            if(vis[h]!=-1 && vis[h]<=p.cost) continue;
            vis[h]=p.cost;
            q.push(p);
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&nop,&nw);
        for(int i=0;i<nop;i++)
            scanf("%s%lld",op[i].str,&op[i].cost);
        for(int i=0;i<nw;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%1d",&beg[j]);
            for(int j=0;j<n;j++)
                scanf("%1d",&goal[j]);
            long long f=bfs();
            if(i) printf(" ");
            if(f==-1) printf("NP");
            else printf("%lld",f);
        }
        printf("\n");
    }
    return 0;
}