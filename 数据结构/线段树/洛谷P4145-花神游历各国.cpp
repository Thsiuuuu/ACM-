#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=1e6+10;

int arr[maxn],sum[maxn<<2],mx[maxn<<2];


void up(int i){
    sum[i]=sum[i<<1]+sum[i<<1|1];
    mx[i]=max(mx[i<<1],mx[i<<1|1]);
}

void build(int l,int r,int i){
    if(l==r){
        sum[i]=arr[l];
        mx[i]=arr[l];
    }else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
}


void sqr(int jobl,int jobr,int l,int r,int i){
    if(l==r){
        sum[i]=mx[i]=sqrt(mx[i]);
    }else{
        int mid=(l+r)>>1;
        if(jobl<=mid&&mx[i<<1]>1){
            sqr(jobl,jobr,l,mid,i<<1);
        }
        if(jobr>mid&&mx[i<<1|1]>1){
            sqr(jobl,jobr,mid+1,r,i<<1|1);
        }
        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return sum[i];
    }
    int mid=(l+r)>>1;
    int ans=0;
    if(jobl<=mid){
        ans+=query(jobl,jobr,l,mid,i<<1);
    }
    if(jobr>mid){
        ans+=query(jobl,jobr,mid+1,r,i<<1|1);
    }
    return ans;
}

signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(1,n,1);

    cin>>m;
    while(m--){
        int k,l,r;
        cin>>k>>l>>r;
        if(l>r) swap(l,r);
        if(!k){
            sqr(l,r,1,n,1);
        }else{
            cout<<query(l,r,1,n,1)<<"\n";
        }
    }
    return 0;

}
