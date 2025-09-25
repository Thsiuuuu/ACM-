#include <iostream>
#include <vector>


using namespace std;

/*

    首先我们要明确
    一个点要不然是独立的一个强连通分量，要不然是跟别人一起组成强连通分量

    我们跑一遍dfs的情况下，如果无法通过自己的所有后继节点到达比自己dfn序更小的节点
    则自己一定是这条回路的祖先节点（假设是回路的情况下）
    
    因为求最大的强连通分量，所以说能小尽小，尽可能让自己到达dfn序更小的节点，扩大强连通分量的范围



*/


const int N=1e4+10;
vector<int> e[N];
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;


void tarjan(int x){
    
    dfn[x]=low[x]=++tot;
    stk[++top]=x,instk[x]=1;
    for(int y:e[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(instk[y]){
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x]){
        int y;++cnt;
        do{
            y=stk[top--];instk[y]=0;
            scc[y]=cnt;
            ++siz[cnt];
        }while(y!=x);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(siz[i]>1) ans++;
    }
    cout<<ans;
    return 0;
}