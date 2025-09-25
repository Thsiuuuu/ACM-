#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=1010;

int pl[maxn],pr[maxn],num[maxn<<2],poster[maxn<<4];

bool visited[maxn];


int collect(int m){
    sort(num+1,num+m+1);
    int size=1;
    for(int i=2;i<=m;i++){
        if(num[size]!=num[i]) num[++size]=num[i];
    }
    int cnt=size;
    for(int i=2;i<=size;i++){
        if(num[i-1]+1<num[i]) num[++cnt]=num[i-1]+1;
    }
    sort(num+1,num+cnt+1);
    return cnt;
}

int rk(int l,int r,int v){
    int m;
    int ans=0;
    while(l<=r){
        m=(l+r)>>1;
        if(num[m]>=v){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    return ans;
}


void down(int i){
    if(poster[i]!=0){
        poster[i<<1]=poster[i];
        poster[i<<1|1]=poster[i];
        poster[i]=0;
    }
}

void build(int l,int r,int i){
    if(l<r){
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
    }
    poster[i]=0;
}

void update(int  jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        poster[i]=jobv;
    }else{
        down(i);
        int mid=(l+r)>>1;
        if(jobl<=mid) update(jobl,jobr,jobv,l,mid,i<<1);
        if(jobr>mid)  update(jobl,jobr,jobv,mid+1,r,i<<1|1);
    }
}

int query(int jobl,int jobr,int l,int r,int i){
    if(l==r){
        if(poster[i]!=0&&!visited[poster[i]]){
            visited[poster[i]]=true;
            return 1;
        }else return 0;
    }else{
        down(i);
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
}

signed main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    int size=0;
    num[++size]=n;
    for(int i=1;i<=m;i++){
        cin>>pl[i]>>pr[i];
        num[++size]=pl[i];
        num[++size]=pr[i];
    }
    size=collect(size);

    build(1,size,1);
    for(int i=1,jobl,jobr;i<=m;i++){
        jobl=rk(1,size,pl[i]);
        jobr=rk(1,size,pr[i]);
        update(jobl,jobr,i,1,size,1);
    }

    cout<<query(1,rk(1,size,n),1,size,1);
    return 0;
}