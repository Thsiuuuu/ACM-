#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long 

const int N=200010;
/*

    这个Lis问题可以用二分优化到O(n*logn)的时间复杂度
    然后要注意回溯


*/


int mod=1e9+7;
int n,m,k;
int tot,cnt;

int a[N],f[N],ans[N];
int head[N];

struct edge{
    int to,next;
}e[N<<1];


void add(int x,int y){
    e[++tot].to=y;
    e[tot].next=head[x];
    head[x]=tot;
}

void dfs(int x,int  fa){
    int last;
    int  l=1,r=ans[fa],mid;
    if(!fa) f[1]=a[x],ans[1]=1;
    else{
        while(l<=r){
            mid=(l+r)>>1;
            if(a[x]<=f[mid]) r=mid-1;
            else l=mid+1;
        }
        last=f[l];
        f[l]=a[x];
        ans[x]=ans[fa];
        if(l>ans[fa]) ans[x]++;
    }
    for(int i=head[x],v;i;i=e[i].next){
         v=e[i].to;
        if(v!=fa) dfs(v,x);
    }
    f[l]=last;
    return ;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }

    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}