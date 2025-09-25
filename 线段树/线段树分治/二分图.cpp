#include <iostream>
#include <algorithm>

using namespace std;

const int  N=100001,T=3000001;
int n,m,k;

int father[N<<1],siz[N<<1],rollback[N<<1][2],opsize=0;

int head[N<<2],nxt[T],tox[T],toy[T],cnt=0;

bool ans[N];

void addEdge(int i,int  x,int y){
    nxt[++cnt]=head[i];
    tox[cnt]=x;
    toy[cnt]=y;
    head[i]=cnt;
}


int find(int  i){
    while(i!=father[i]){
        i=father[i];
    }
    return i;
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(siz[fx]<siz[fy]){
        swap(fx,fy);
    }
    father[fy]=fx;
    siz[fx]+=siz[fy];
    rollback[++opsize][0]=fx;
    rollback[opsize][1]=fy;
}

void undo(){
    int fx=rollback[opsize][0];
    int fy=rollback[opsize--][1];
    father[fy]=fy;
    siz[fx]-=siz[fy];
}

void add(int jobl,int jobr,int jobx,int joby,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        addEdge(i,jobx,joby);
    }else{
        int mid=(l+r)>>1;
        if(jobl<=mid){
            add(jobl,jobr,jobx,joby,l,mid,i<<1);
        }
        if(jobr>mid){
            add(jobl,jobr,jobx,joby,mid+1,r,i<<1|1);
        }
    }
}

void dfs(int l,int r,int i){
    bool check=true;
    int unioncnt=0;
    for(int e=head[i];e;e=nxt[e]){
        int x=tox[e],y=toy[e],fx=find(x),fy=find(y);
        if(fx==fy){
            check=false;
            break;
        }else{
            unite(x,y+n);
            unite(y,x+n);
            unioncnt+=2;
        }

    }
    if(check){
        if(l==r){
            ans[l]=true;
        }else{
            int mid=(l+r)>>1;
            dfs(l,mid,i<<1);
            dfs(mid+1,r,i<<1|1);
        }
    }else{
        for(int k=l;k<=r;k++){
            ans[k]=false;
        }
    }
    for(int k=1;k<=unioncnt;k++){
        undo();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n*2;i++){
        father[i]=i;
        siz[i]=1;
    }
    for(int i=1,x,y,l,r;i<=m;i++){
        cin>>x>>y>>l>>r;
        add(l+1,r,x,y,1,k,1);
    }
    dfs(1,k,1);
    for(int i=1;i<=k;i++){
        if(ans[i]){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}