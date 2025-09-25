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
        sum[i]=mx[i]=arr[l];
    }else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return sum[i];
    }
    int mid=(l+r)>>1;
    int ans=0;
    if(jobl<=mid) ans+=query(jobl,jobr,l,mid,i<<1);
    if(jobr>mid)  ans+=query(jobl,jobr,mid+1,r,i<<1|1);
    return ans;
}

void mod(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobv>mx[i]) return ;
    if(l==r){
        sum[i]%=jobv;
        mx[i]%=jobv;
    }else{
        int mid=(l+r)>>1;
        if(jobl<=mid) mod(jobl,jobr,jobv,l,mid,i<<1);
        if(jobr>mid)  mod(jobl,jobr,jobv,mid+1,r,i<<1|1);
        up(i);
    }
}

void update(int jobi,int jobv,int l,int r,int i){
    if(l==r){
        sum[i]=mx[i]=jobv;
    }else{
        int mid=(l+r)>>1;
        if(jobi<=mid){
            update(jobi,jobv,l,mid,i<<1);
        }else{
            update(jobi,jobv,mid+1,r,i<<1|1);
        }
        up(i);

    }
}

signed main(){
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,n,1);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            cout<<query(l,r,1,n,1)<<"\n";
        }else if(op==2){
            int l,r,x;
            cin>>l>>r>>x;
            mod(l,r,x,1,n,1);
        }else{

            int k,x;
            cin>>k>>x;
            update(k,x,1,n,1);
        }
    }
    return 0;
}