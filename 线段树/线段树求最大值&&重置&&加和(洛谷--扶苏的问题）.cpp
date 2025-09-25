// 线段树同时支持范围重置、范围增加、范围查询
// 维护最大值
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=1e6+10;

int arr[maxn],mx[maxn<<2],add[maxn<<2],change[maxn<<2];
bool update[maxn<<2];

void up(int i){
    mx[i]=max(mx[i<<1],mx[i<<1|1]);
}

void updatelazy(int i ,int v){
    mx[i]=v;
    add[i]=0;
    change[i]=v;
    update[i]=true;
}

void addlazy(int i,int v){
    mx[i]+=v;
    add[i]+=v;
}

void down(int i){
    if(update[i]){
        updatelazy(i<<1,change[i]);
        updatelazy(i<<1|1,change[i]);
        update[i]=false;
    }
    if(add[i]!=0){
        addlazy(i<<1,add[i]);
        addlazy(i<<1|1,add[i]);
        add[i]=0;
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
    add[i]=0;
    change[i]=0;
    update[i]=false;
}

void upd(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr) updatelazy(i,jobv);
    else{
        int mid=(l+r)>>1;
        down(i);
        if(jobl<=mid) upd(jobl,jobr,jobv,l,mid,i<<1);
        if(jobr>mid) upd(jobl,jobr,jobv,mid+1,r,i<<1|1);
        up(i);
    }
}

void adg(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr) addlazy(i,jobv);
    else{
        int mid=(l+r)>>1;
        down(i);
        if(jobl<=mid) adg(jobl,jobr,jobv,l,mid,i<<1);
        if(jobr>mid)  adg(jobl,jobr,jobv,mid+1,r,i<<1|1);
        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr) return mx[i];
    int mid=(l+r)>>1;
    down(i);
    int ans=-1145141919810;
    if(jobl<=mid) ans=max(ans,query(jobl,jobr,l,mid,i<<1));
    if(jobr>mid)  ans=max(ans,query(jobl,jobr,mid+1,r,i<<1|1));
    return ans;
}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,n,1);
    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            int x;
            cin>>x;
            upd(l,r,x,1,n,1);
        }else if(op==2){
            int x;
            cin>>x;
            adg(l,r,x,1,n,1);
        }else if(op==3){
             cout<<query(l,r,1,n,1)<<"\n";
        }
    }
    return 0;
}