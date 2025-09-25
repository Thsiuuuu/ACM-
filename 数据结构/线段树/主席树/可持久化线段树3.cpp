#include <iostream>
#include <algorithm>

using namespace std;
#define int long long 
const int N=100010;
const int T=N*70;

int n,m,t=0;
int arr[N],root[N],ls[T],rs[T],sum[T],add[T];
int cnt=0;

int clone(int i){
    int rt=++cnt;
    ls[rt]=ls[i];
    rs[rt]=rs[i];
    sum[rt]=sum[i];
    add[rt]=add[i];
    return rt;
}

void up(int i){
    sum[i]=sum[ls[i]]+sum[rs[i]];
}

void lazy(int i,int v,int n){
    sum[i]+=v*n;
    add[i]+=v;
}

void down(int i,int ln,int rn){
    if(add[i]!=0){
        ls[i]=clone(ls[i]);
        rs[i]=clone(rs[i]);
        lazy(ls[i],add[i],ln);
        lazy(rs[i],add[i],rn);
        add[i]=0;
    }
}

int build(int l,int r){
    int rt=++cnt;
    add[rt]=0;
    if(l==r){
        sum[rt]=arr[l];
    }else{
        int mid=(l+r)>>1;
        ls[rt]=build(l,mid);
        rs[rt]=build(mid+1,r);
        up(rt);;
    }
    return rt;
}

int addRange(int jobl,int jobr,int jobv,int l,int r,int i){
    int rt=clone(i);
    if(jobl<=l&&r<=jobr){
        lazy(rt,jobv,r-l+1);
    }else{
        int mid=(l+r)>>1;
        down(rt,mid-l+1,r-mid);
        if(jobl<=mid){
            ls[rt]=addRange(jobl,jobr,jobv,l,mid,ls[rt]);
        }
        if(jobr>mid){
            rs[rt]=addRange(jobl,jobr,jobv,mid+1,r,rs[rt]);
        }
        up(rt);
    }
    return rt;
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return sum[i];
    }
    int mid=(l+r)>>1;
    down(i,mid-l+1,r-mid);
    int ans=0;
    if(jobl<=mid){
        ans+=query(jobl,jobr,l,mid,ls[i]);
    }
    if(jobr>mid){
        ans+=query(jobl,jobr,mid+1,r,rs[i]);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    root[0]=build(1,n);
    string op;
    int x,y,z;
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op=="C"){
            cin>>x>>y>>z;
            root[t+1]=addRange(x,y,z,1,n,root[t]);
            t++;
        }else if(op=="Q"){
            cin>>x>>y;
            cout<<query(x,y,1,n,root[t])<<'\n';
        }else if(op=="H"){
            cin>>x>>y>>z;
            cout<<query(x,y,1,n,root[z])<<'\n';
        }else if(op=="B"){
            cin>>x;
            t=x;
        }
    }
    return 0;
}