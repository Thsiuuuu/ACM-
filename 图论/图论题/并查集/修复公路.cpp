#include <iostream>
#include <algorithm>
using namespace std;

const  int  N=1e5+10;

int fa[N],cnt;
int m;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

struct node{
    int u,v,t;
    bool operator<(const node&a)const {
        return  t<a.t;
    }
}p[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>cnt>>m;
    for(int i=1;i<=m;i++){
        cin>>p[i].u>>p[i].v>>p[i].t;

    }
    for(int i=1;i<=cnt;i++){
        fa[i]=i;
    }
    sort(p+1,p+1+m);
    for(int i=1;i<=m;i++){
        int fx=find(p[i].u),fy=find(p[i].v);
        if(fx!=fy){
            fa[fx]=fy;
            cnt--;
        }
        if(cnt==1){
            cout<<p[i].t;
            return 0;
        }
    }
    cout<<-1;
    return 0;

}