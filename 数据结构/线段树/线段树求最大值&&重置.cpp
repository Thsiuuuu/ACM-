#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=1e6+10;

int arr[maxn],mx[maxn<<2],change[maxn<<2],update[maxn<<2];


void up(int i){
    mx[i]=max(mx[i<<1],mx[i<<1|1]);
}



void lazy(int i,int v){
    mx[i]=v;
    change[i]=v;
    update[i]=true;
}


void down(int i){
    if(update[i]){
        lazy(i<<1,change[i]);
        lazy(i<<1|1,change[i]);
        update[i]=false;
    }
}

void build(int l,int r,int i){
    if(l==r) mx[i]=arr[l];
    else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
    change[i]=0;
    update[i]=false;
}


void update(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        lazy(i,jobv);
    }else{
        down(i);
        int mid=(l+r)>>1;
        if(jobl<=mid){
            update(jobl,jobr,jobv,l,mid,i<<1);
        }
        if(jobr>mid){
            update(jobl,jobr,jobv,mid+1,r,i<<1|1);
        }
        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return mx[i];
    }
    down(i);
    int mid=(l+r)>>1;
    int ans=INT_MIN;
    if(jobl<=mid){
        ans=max(ans,query(jobl,jobr,l,mid,i<<1));
    }
    if(jobr>mid){
        ans=max(ans,query(jobl,jobr,mid+1,r,i<<1|1));
    }
    
    return ans;
}

