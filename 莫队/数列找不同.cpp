#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


const int N=1e5+10;
int vis[N],num[N],blo[N],res[N],ans;
int l=1,r=0;
int n,m;
struct node{
    int l,r,id;
}p[N];

bool cmp1(const node&a,const node&b){
    return blo[a.l]!=blo[b.l]?a.l<b.l:(blo[a.l]%2==0)?a.r>b.r:a.r<b.r;
}

void add(int x){
    vis[num[x]]++;
    if(vis[num[x]]==1){
        ans++;
    }
}

void sub(int  x){
    vis[num[x]]--;
    if(!vis[num[x]]){
        ans--;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    int block=n/sqrt(m);
    for(int i=1;i<=n;i++){
        blo[i]=(i-1)/block+1;
    }
    for(int i=1;i<=m;i++){
        cin>>p[i].l>>p[i].r;
        p[i].id=i;
    }
    sort(p+1,p+1+m,cmp1);
    for(int i=1;i<=m;i++){
        while(l<p[i].l) sub(l++);
        while(l>p[i].l) add(--l);
        while(r<p[i].r) add(++r);
        while(r>p[i].r) sub(r--);
        res[p[i].id]=((ans^(r-l+1))?0:1);
    }
    for(int i=1;i<=m;i++){
        if(res[i]){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }

    return 0;
}