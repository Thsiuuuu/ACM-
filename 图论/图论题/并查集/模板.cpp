#include <iostream>

using namespace std;

const int  N=1e6+10;

int fa[N],siz[N];
int n,m,x,y;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return ;
    if(siz[fx]>siz[fy]){
        swap(fx,fy);
    }
    fa[fx]=fy;
    siz[fy]+=siz[fx];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        siz[i]=1;
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int op;
        cin>>op>>x>>y;
        
        if(op==1){
            unite(x,y);
        }else{
            if(find(x)^find(y)){
                cout<<"N\n";
            }else{
                cout<<"Y\n";
            }
        }

    }
    return 0;
}