#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;
const int N=2e5+10;

int blo[N],num[N],vis[N],ans[N],cnt[N];


// int mn[N<<2];
// void up(int i){
//     mn[i]=min(mn[i<<1],mn[i<<1|1]);
// }

// void build(int l,int r,int i){
//     if(l==r) mn[i]=num[l];
//     else{
//         int mid=(l+r)>>1;
//         build(l,mid,i<<1);
//         build(mid+1,r,i<<1|1);
//         up(i);
//     }
// }

// int query(int jobl,int jobr,int l,int r,int i){
//     if(jobl<=l&&r<=jobr){
//         return mn[i];
//     }
//     int mid=(l+r)>>1;
//     int ans=INT_MAX;
//     if(jobl<=mid){
//         ans=min(ans,query(jobl,jobr,l,mid,i<<1));
//     }
//     if(jobr>mid){
//         ans=min(ans,query(jobl,jobr,mid+1,r,i<<1|1));
//     }
//     return ans;
// }

/*


    同时采用莫队分块和数值分块进行优化
    数值分块避免了逐个的遍历，分成一块一块进行，单次时间复杂度为O(2*sqrt(k,2))


*/

struct node{
    int l,r;
    int id;
    bool operator<(const node&w) const{
        if(blo[l]!=blo[w.l]) return l<w.l;
        return (blo[l]&1)?r<w.r:r>w.r;
    }
}p[N];

int n,m,block;
int l=1,r=0;
const int K=448;

void add(int x){
    vis[x]++;
    if(vis[x]==1){
        cnt[x/K]++;
    }
}
void sub(int x){
    vis[x]--;
    if(vis[x]==0){
        cnt[x/K]--;
    }   
}

void check(int x){
    for(int i=1;i<=K;i++){
        if(cnt[i-1]!=K){
            for(int j=(i-1)*K;j<i*K;j++){
                if(!vis[j]){
                    ans[p[x].id]=j;
                    return ;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    cin>>n>>m;
    block=n/sqrt(m);
    

    for(int i=1;i<=n;i++){
        cin>>num[i];
    }

    for(int i=1;i<=n;i++){
        blo[i]=(i-1)/block+1;
    }

    for(int i=1;i<=m;i++){
        cin>>p[i].l>>p[i].r;
        p[i].id=i;
    }
    
    sort(p+1,p+1+m);
    for(int i=1;i<=m;i++){
        while(l<p[i].l){
            sub(num[l++]);
        }
        while(l>p[i].l){
            add(num[--l]);
        }
        while(r<p[i].r){
            add(num[++r]);
        }
        while(r>p[i].r){
            sub(num[r--]);
        }
        check(i);
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}