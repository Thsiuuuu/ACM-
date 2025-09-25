#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/*

    二分图判断
    因为对于每一个联通块，如果可以被染色的话，那一定是一边一个颜色，所以转化成二分图判断的问题

*/

const int N=210;
int head[N],to[N<<1],nxt[N<<1],cnt=1;
int color[N];
int n,m;
int flag;

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;//链式前向星写错了!!!
}
int dfs(int u,int c){
    color[u]=c;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(!color[v]){
            if(dfs(v,3-c)){
                return 1;
            }
        }
        else if(color[v]==c){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n>>m,n){
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            addEdge(u,v);
            addEdge(v,u);
        }

        for(int i=0;i<n;i++){
            if(!color[i]){
                flag=dfs(i,1);
                if(flag){
                    cout<<"NOT BICOLORABLE.\n";
                    break;
                }
            }
        }
        if(!flag){
            cout<<"BICOLORABLE.\n";
        }
        memset(head,0,sizeof(head));
        memset(to,0,sizeof(to));
        memset(nxt,0,sizeof(nxt));
        memset(color,0,sizeof(color));
        cnt=1;
        flag=0;
    }
    return 0;
}