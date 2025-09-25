#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=1e6+10;

int arr[maxn],sum[maxn<<2],add[maxn<<2],mul[maxn<<2];
int m;

void up(int i){
    sum[i]=(sum[i<<1]+sum[i<<1|1])%m;
}


void lazy1(int i,int v,int n){
    sum[i]=(sum[i]+v*n)%m;
    add[i]=(add[i]+v)%m;
}

void lazy2(int i,int k,int n){
    sum[i]=(sum[i]*k)%m;
    mul[i]=(mul[i]*k)%m;
    add[i]=(add[i]*k)%m;
}

void down(int i,int ln,int rn){
    
    sum[i<<1]=(sum[i<<1]*mul[i]+add[i]*ln)%m;
    sum[i<<1|1]=(sum[i<<1|1]*mul[i]+add[i]*rn)%m;
    mul[i<<1]=(mul[i<<1]*mul[i])%m;
    mul[i<<1|1]=(mul[i<<1|1]*mul[i])%m;
    add[i<<1]=(add[i<<1]*mul[i]+add[i])%m;
    add[i<<1|1]=(add[i<<1|1]*mul[i]+add[i])%m;

    add[i]=0,mul[i]=1;

}

void build(int l,int r,int i){
    if(l==r) sum[i]=arr[l]%m;
    else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
    add[i]=0;
    mul[i]=1;
}

void getadd(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr) lazy1(i,jobv,r-l+1);
    else{
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);
        if(jobl<=mid){
            getadd(jobl,jobr,jobv,l,mid,i<<1);
        }
        if(jobr>mid){
            getadd(jobl,jobr,jobv,mid+1,r,i<<1|1);
        }
        up(i);
    }
}


void getmul(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr) lazy2(i,jobv,r-l+1);
    else{
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);
        if(jobl<=mid){
            getmul(jobl,jobr,jobv,l,mid,i<<1);
        }
        if(jobr>mid){
            getmul(jobl,jobr,jobv,mid+1,r,i<<1|1);
        }
        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return sum[i];
    }

    int mid=(l+r)>>1;
    down(i,mid-l+1,r-mid);
    int ans=0;
    if(jobl<=mid){
        ans+=query(jobl,jobr,l,mid,i<<1)%m;
    }
    if(jobr>mid){
        ans+=query(jobl,jobr,mid+1,r,i<<1|1)%m;
    }
    return ans%m;
}

signed main(){
    int n,q;
    cin>>n>>q>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(1,n,1);
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x,y,k;
            cin>>x>>y>>k;
            getmul(x,y,k,1,n,1);
        }else if(op==2){
            int x,y,k;
            cin>>x>>y>>k;
            getadd(x,y,k,1,n,1);
        }else{
            int x,y;
            cin>>x>>y;
            cout<<query(x,y,1,n,1)<<"\n";
        }
    }

    return 0;
}