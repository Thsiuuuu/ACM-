#include <iostream>
#include <algorithm>


using namespace std;

#define int long long 


/*

    拓扑排序判断有无自环即可


*/

const int  N=110;
int head[N],to[2*N],ne[2*N],deg[N],que[N];
int n,m,l,r;
int cnt;

void build(){
    memset(head,0,sizeof(head));
    memset(to,0,sizeof(to));
    memset(ne,0,sizeof(ne));
    memset(deg,0,sizeof(deg));
    memset(que,0,sizeof(que));
    l=r=0;
    cnt=1;
}


void add(int u,int v){
    ne[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);



    while(cin>>n>>m){

        if(!n) break;

        build();

        int x,y;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            add(y,x);
            deg[x]++;
        }
        
        for(int i=0;i<n;i++){
            if(!deg[i]){
                que[r++]=i;
            }
        }

        while(l<r){
            int u=que[l++];
            for(int e=head[u],v;e>0;e=ne[e]){
                v=to[e];
                if(--deg[v]==0){
                    que[r++]=v;
                }
            }
        }
        if(n==r) cout<<"YES\n";
        else cout<<"NO\n";
    }
}