#include <iostream>
#include <vector>

using namespace std;

const int N=1e4+10;

/*

    强连通分量缩点

*/


vector<int> e[N];
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],cnt;
int din[N],dout[N];


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
            y=stk[top--];
            instk[y]=0;
            scc[y]=cnt;
        }while(y!=x);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1,a;i<=n;i++){
        while(cin>>a,a)
        e[i].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }

    for(int x=1;x<=n;x++){
        for(int y:e[x]){
            if(scc[x]!=scc[y]){
                din[scc[y]]++;
                dout[scc[x]]++;
            }
        }
    }

    int a=0,b=0;
    for(int i=1;i<=cnt;i++){
        if(!din[i]){
            a++;
        }
        if(!dout[i]){
            b++;
        }
    }
    cout<<a<<"\n";
    if(cnt==1){
        cout<<"0\n";
    }else{
        cout<<max(a,b);
    
    }
    return 0;
}