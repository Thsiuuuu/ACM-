#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int N=5010,M=5e5+10,mod=80112002;
int head[N],ne[M],to[M],que[N],deg[N],lines[N];

/*

    这个题用拓扑排序
    每次弹出一个节点就更新一次它能走到的节点
    类似树形dp

*/


int  cnt=1,n,m;
void add(int u,int v){
    ne[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>m;
    memset(deg,0,sizeof(deg));
    memset(lines,0,sizeof(lines));
    memset(head,0,sizeof(head));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
        deg[y]++;
    }


    int l=0,r=0;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            que[r++]=i;
            lines[i]=1;
        }
    }
    int ans=0;
    while(l<r){
        int u=que[l++];
        if(!head[u]){
            ans=(ans+lines[u])%mod;
        }else{
            for(int e=head[u],v;e>0;e=ne[e]){
                v=to[e];
                lines[v]=(lines[v]+lines[u])%mod;
                if(--deg[v]==0){
                    que[r++]=v;
                }
            }
        }
    }
    cout<<ans;

}