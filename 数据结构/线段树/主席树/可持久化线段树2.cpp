#include <iostream>
#include <algorithm>

using namespace std;

const int N=2e5+10;
const int T=N*22;
int n,m,s;
int arr[N],sorted[N],root[N],ls[T],rs[T],siz[T],cnt;

int kth(int num){
    int l=1,r=s,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(sorted[mid]<=num){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    
    }
    return ans;
}

int build(int l,int r){
    int rt=++cnt;
    siz[rt]=0;
    if(l<r){
        int mid=(l+r)>>1;
        ls[rt]=build(l,mid);
        rs[rt]=build(mid+1,r);
    }
    return rt;
}

int insert(int jobi,int l,int r,int i){
    int rt=++cnt;
    ls[rt]=ls[i];
    rs[rt]=rs[i];
    siz[rt]=siz[i]+1;
    if(l<r){
        int mid=(l+r)>>1;
        if(jobi<=mid){
            ls[rt]=insert(jobi,l,mid,ls[rt]);
        }else{
            rs[rt]=insert(jobi,mid+1,r,rs[rt]);
        }
    }
    return rt;
}

void prepare(){
    cnt=0;
    for(int i=1;i<=n;i++){
        sorted[i]=arr[i];
        
    }
    sort(sorted+1,sorted+1+n);
    s=1;
    for(int i=2;i<=n;i++){
        if(sorted[s]!=sorted[i]){
            sorted[++s]=sorted[i];
        }
    }
    root[0]=build(1,s);
    for(int i=1,x;i<=n;i++){
        x=kth(arr[i]);
        root[i]=insert(x,1,s,root[i-1]);
    }
}

int query(int jobk,int l,int r,int u,int v){
    if(l==r){
        return l;
    }
    int lsiz=siz[ls[v]]-siz[ls[u]];
    int mid=(l+r)>>1;
    if(lsiz>=jobk){
        return query(jobk,l,mid,ls[u],ls[v]);
    }else{
        return query(jobk-lsiz,mid+1,r,rs[u],rs[v]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    prepare();
    for(int i=1,l,r,k,rank;i<=m;i++){
        cin>>l>>r>>k;
        rank=query(k,1,s,root[l-1],root[r]);
        cout<<sorted[rank]<<'\n';
    }
    return 0;
}