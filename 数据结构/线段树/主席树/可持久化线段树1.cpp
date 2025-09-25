#include <iostream>
/*

    可持久化线段树就是在线段树的基础上
    因为每次只会修改一条从上到下路径的值，所以只对这一条路径重构即可


*/

using namespace std;

const int N=1e6+10;
const int T=N*23;
int n,m;
int  arr[N],root[N],ls[T],rs[T],value[T],cnt=0;

int build(int l,int  r){
    int rt=++cnt;
    if(l==r){
        value[rt]=arr[l];
    }else{
        int mid=(l+r)>>1;
        ls[rt]=build(l,mid);
        rs[rt]=build(mid+1,r);
    }
    return rt;
}

int update(int jobi,int jobv,int l,int r,int i){
    int rt=++cnt;
    ls[rt]=ls[i];
    rs[rt]=rs[i];
    value[rt]=value[i];
    if(l==r){
        value[rt]=jobv;
    }else{
        int mid=(l+r)>>1;
        if(jobi<=mid){
            ls[rt]=update(jobi,jobv,l,mid,ls[rt]);
        }else{
            rs[rt]=update(jobi,jobv,mid+1,r,rs[rt]);
        }
    }
    return rt;
}

int  query(int jobi,int l,int r,int i){
    if(l==r){
        return value[i];
    }
    int mid=(l+r)>>1;
    if(jobi<=mid){
        return query(jobi,l,mid,ls[i]);
    }else{
        return query(jobi,mid+1,r,rs[i]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    root[0]=build(1,n);
    for(int i=1,v,op,x,y;i<=m;i++){
        cin>>v>>op>>x;
        if(op==1){
            cin>>y;
            root[i]=update(x,y,1,n,root[v]);//从v号数组对应的线段树根节点开始更新
        }else{
            root[i]=root[v];//查询的时候直接复制根节点的编号就可以
            cout<<query(x,1,n,root[i])<<'\n';
        }
    }
    return 0;
}