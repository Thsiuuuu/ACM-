#include <iostream>
#include <vector>

/*

    tarjan求强连通分量
    如果最后出度为0的点只有一个的话，那它的大小就是明星奶牛的数量

*/

using namespace std;

const int  N=10010;
vector<int> e[N];
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;
int dout[N];


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
    if(low[x]==dfn[x]){
        int y;++cnt;
        do{
            y=stk[top--];
            instk[y]=0;
            scc[y]=cnt;
            ++siz[cnt];
        }while(y!=x);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);

    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int x=1;x<=n;x++){
        for(int y:e[x]){
            if(scc[x]!=scc[y]){
                ++dout[scc[x]];
            }
        }
    }
    int sum=0,zeros=0;
    for(int i=1;i<=cnt;i++){
        if(!dout[i]){
            sum=siz[i];
            ++zeros;
        }
    }
    if(zeros>1) sum=0;
    cout<<sum;
    return 0;
}