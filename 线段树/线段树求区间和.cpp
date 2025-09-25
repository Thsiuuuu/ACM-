#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxn=1e6+10;

int arr[maxn],sum[maxn<<2],add[maxn<<2];

void up(int i){
    sum[i]=sum[i<<1]+sum[i<<1|1];
}

// 当前来到l~r范围，对应的信息下标是i，范围上数字的个数是n = r-l+1
	// 现在收到一个懒更新任务 : l~r范围上每个数字增加v
	// 这个懒更新任务有可能是任务范围把当前线段树范围全覆盖导致的
	// 也有可能是父范围的懒信息下发下来的
	// 总之把线段树当前范围的sum数组和add数组调整好
	// 就不再继续往下下发了，懒住了
void lazy(int i,int v,int n){
    sum[i]+=v*n;
    add[i]+=v;
}

void down(int i,int ln,int rn){
    if(add[i]){
        lazy(i<<1,add[i],ln);
        lazy(i<<1|1,add[i],rn);
        add[i]=0;
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
    add[i]=0;
}

void getadd(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr) lazy(i,jobv,r-l+1);
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

signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(1,n,1);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x,y,k;
            cin>>x>>y>>k;
            getadd(x,y,k,1,n,1);
        }else if(op==2){
            int x,y;
            cin>>x>>y;
            cout<<query(x,y,1,n,1)<<"\n";
        }
    }

    return 0;
}