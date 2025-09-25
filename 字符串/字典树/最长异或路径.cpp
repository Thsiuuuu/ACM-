#include <iostream>
#include <algorithm>


using namespace std;


/*

    因为任意两点间路径的异或和可以表示为它们到根节点路径异或和再异或起来
    所以这里对每个节点到根节点的异或值建一颗树

*/

const int N=100010;

int n;
int head[N],to[N<<1],val[N<<1],nxt[N<<1],tot=0;
int dis[N];
int trie[N<<4][2],cnt=1;

void add(int u,int  v,int w){
    to[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    val[tot]=w;
}

void dfs(int u,int fa){
    for(int e=head[u],v,w;e;e=nxt[e]){
        v=to[e],w=val[e];
        if(v!=fa){
            dis[v]=w^dis[u];
            dfs(v,u);
        }
    }
}//计算出一个点到根节点的边权

void insert(int x){
    int p=1;
    for(int i=31;i>=0;i--){
        int num=((x>>i)&1);
        
        if(!trie[p][num]){
            trie[p][num]=++cnt;
        }
        p=trie[p][num];
        
    }
}//按照一个点到根节点的边权进行建树

int find(int num){
    int p=1;
    int sum=0;
    for(int i=31;i>=0;i--){
        int x=((num>>i)&1);
        if(trie[p][x^1]){
            sum+=(1<<i),p=trie[p][x^1];
        }else{
            p=trie[p][x];
        }
    }
    return sum;
}



int main(){
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    dis[1]=0;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        insert(dis[i]);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=max(sum,find(dis[i]));
    }
    printf("%d",sum);
    return 0;
}