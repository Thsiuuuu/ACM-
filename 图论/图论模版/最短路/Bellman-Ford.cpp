#include <vector>
#include <iostream>
#include <climits>
using namespace std;


const int N=510,M=10010;

struct Edge{
    int a,b,c;
}edges[M];

int n,m,k;
int dist[N];
int last[N];

void bellman_ford()
{
    memset(dist,0x3f,sizeof dist);

    dist[1]=0;
    for(int i=0;i<k;i++){
        memcpy(last,dist,sizeof dist);
        for(int j=0;j<m;j++){
            auto e=edges[j];
            dist[e.b]=min(dist[e.b],last[e.a]+e.c);
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i]={a,b,c};
    }

    bellman_ford();
    if(dist[n]>0x3f3f3f3f/2) puts("impossible");
    else cout<<dist[n]<<endl;
    return 0;
}