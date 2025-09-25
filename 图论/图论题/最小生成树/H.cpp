#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

#define int long  long 
#define pii pair<int,int>
#define Edge pair<int,pii>
/*

    稠密图问题常考虑能否减少需要考虑的边数，特别是MST问题

    然后分别枚举x和y即可

*/

struct UnionFind{
    vector<int> par;
    UnionFind(int n):par(n,-1){}//构造函数
    int root(int x){
        if(par[x]<0) return x;
        else return par[x]=root(par[x]);
    }
    bool issame(int x,int y){
        return root(x)==root(y);
    }
    void merge(int x,int y){
        x=root(x);y=root(y);
        if(x==y) return ;
        if(-par[x]<-par[y]) swap(x,y);
        par[x]+=par[y];
        par[y]=x;
    }
};


signed main(){
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];

    vector<Edge> edges;
    vector<int> ids(n);
    iota(ids.begin(),ids.end(),0);
    sort(ids.begin(),ids.end(),[&](int i,int j){return x[i]<x[j];});//按照x排序记录他们各自的索引
    for(int i=0;i+1<(int)ids.size();i++){
        int u=ids[i],v=ids[i+1];
        edges.push_back(Edge(x[v]-x[u],pii(u,v)));
    }

    sort(ids.begin(),ids.end(),[&](int i,int j){return y[i]<y[j];});
    for(int i=0;i+1<(int)ids.size();i++){
        int u=ids[i],v=ids[i+1];
        edges.push_back(Edge(y[v]-y[u],pii(u,v)));//构造函数
    }

    sort(edges.begin(),edges.end());
    UnionFind uf(n);
    int res=0;
    for(auto e:edges){
        int u=e.second.first,v=e.second.second;
        int cost=e.first;
        if(uf.issame(u,v)) continue;
        uf.merge(u,v);
        res+=cost;
    }
    cout<<res;
    return 0;
}