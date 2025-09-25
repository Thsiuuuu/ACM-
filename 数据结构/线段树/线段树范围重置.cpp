#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=1e6+10;

int arr[maxn],sum[maxn<<2],change[maxn<<2];
bool st[maxn<<2];

void up(int i){
    sum[i]=sum[i<<1]+sum[i<<1|1];
}


void lazy(int i,int v,int n){
    sum[i]=v*n;
    change[i]=v;
    st[i]=true;
}



void down(int i,int ln,int rn){
    if(st[i]){
        lazy(i<<1,change[i],ln);
        lazy(i<<1|1,change[i],rn);
        st[i]=false;
    }
}  


void update(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        lazy(i,jobv,r-l+1);
    }else{
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);
        if(jobl<=mid){
            update(jobl,jobr,jobv,1,mid,i<<1);
        }
        if(jobr>mid){
            update(jobl,jobr,mid+1,r,i<<1|1);
        }
        up(i);
    }
}

void build(int l,int r,int i){
    if(l==r) sum[i]=arr[l];
    else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
    change[i]=0;
    st[i]=false;
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return sum[i];
    }
    int mid=(l+r)>>1;
    down(i,mid-l+1,r-mid);
    int ans=0;
    if(jobl<=mid){
        ans+=query(jobl,jobr,l,mid,i<<1);
    }
    if(jobr>mid){
        ans+=query(jobl,jobr,mid+1,r,i<<1|1);
    }
    return ans;
}