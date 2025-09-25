#include <iostream>
#include <algorithm>
using namespace std;

/*

    这个题想要让最大值最小，
    然后那就先从大到小排序，逐步合并，直到不能合并为止，就是答案

    i和i+n分别表示自身和反状态,i+n不能和i在同一个监狱里面
    每次进监狱的过程都是一个点和另外一个点不在一个监狱，
    
    每个点把对方放到自己不在的集合里面，第一次反生冲突就是两个集合被合并成一个集合的时候    



    其实睡醒了简化一下思路，对于一个点来说，只有自己在的集合和自己不在的集合，
    把对方放进自己在的集合里面，并且合并之后，不是同一个集合，就没问题
*/

const int M=1e5+10;
struct node{
    int u,v;
    int w;
    bool operator<(const node&W) const{
        return w>W.w;
    }
}p[M];
int fa[M];
int n,m;
int find(int i){
    return fa[i]==i?i:fa[i]=find(fa[i]);
}
void  unite(int x,int y){
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=2*n;i++){
        fa[i]=i;
    }
    for(int i=0;i<m;i++){
        cin>>p[i].u>>p[i].v>>p[i].w;
    }

    sort(p,p+m);
    for(int i=0;i<m;i++){
        unite(p[i].u,p[i].v+n);
        unite(p[i].u+n,p[i].v);

        if(find(p[i].u)==find(p[i].u+n)){
            cout<<p[i].w;
            return 0;
        }
    }
    cout<<0;
    return 0;
}

