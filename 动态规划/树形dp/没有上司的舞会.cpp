#include <iostream>
#include <algorithm>

using  namespace std;

#define int long long 

const int maxn=1e6+10;


int nxt[maxn],to[maxn],yes[maxn],no[maxn],head[maxn],happy[maxn],nums[maxn];
bool boss[maxn];

int n,h;
int cnt;

void build(int n){
    memset(boss,true,sizeof(boss));
    memset(head,0,sizeof(head));
    cnt=1;
}

void add(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;

}

void f(int u){
    no[u]=0;
    yes[u]=nums[u];
    for(int e=head[u],v;e>0;e=nxt[e]){
        v=to[e];
        f(v);
        no[u]+=max(no[v],yes[v]);
        yes[u]+=no[v];
    }
}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    build(n);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    for(int i=1;i<n;i++){
        int l,k;
        cin>>l>>k;
        add(k,l);
        boss[l]=false;
    }

    for(int i=1;i<=n;i++){
        if(boss[i]){
            h=i;
            break;
        }
    }

    f(h);
    cout<<max(no[h],yes[h]);

}