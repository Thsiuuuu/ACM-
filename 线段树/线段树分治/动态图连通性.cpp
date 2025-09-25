#include <iostream>
#include <algorithm>

using namespace std;

const int  N=5001,M=500001,T=5000001;

int n,m;

int op[M],u[M],v[M];

int last[N][N];

int father[N],siz[N],rollback[N][2];
int opsize=0;

int head[M<<2];
int nxt[T],tox[T],toy[T];
int cnt=0;

bool ans[M];

void addEdge(int i,int x,int y){
    nxt[++cnt]=head[i];
    tox[cnt]=x;
    toy[cnt]=y;
    head[i]=cnt;
}

int find(int i){
    while(i!=father[i]){
        i=father[i];
    }
    return i;
}

void unite(int x,int y){
    int  fx=find(x);
    int fy=find(y);

    if(siz[fx]<siz[fy]){
        swap(fx,fy);
    }
    father[fy]=fx;
    siz[fx]+=siz[fy];
    rollback[++opsize][0]=fx;
    rollback[opsize][1]=fy;//0是合并到的，1是被合并的
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
    int unioncnt=0;
    for(int e=head[i],x,y,fx,fy;e;e=nxt[e]){
        x=tox[e];
        y=toy[e];
        fx=find(x);
        fy=find(y);
        if(fx!=fy){
            unite(fx,fy);
            unioncnt++;
        }
    }
    if(l==r){
        if(op[l]==2){
            ans[l]=find(u[l])==find(v[l]);
        }
    }else{
        int mid=(l+r)>>1;
        dfs(l,mid,i<<1);
        dfs(mid+1,r,i<<1|1);
    }
    for(int j=1;j<=unioncnt;j++){
        undo();
    }
}

void prepare(){
    for(int i=1;i<=n;i++){
        father[i]=i;
        siz[i]=1;
    }
    for(int i=1,t,x,y;i<=m;i++){
        t=op[i];
        x=u[i];
        y=v[i];
        if(!t){
            last[x][y]=i;
        }else if(t==1){
            add(last[x][y],i-1,x,y,1,m,1);
            last[x][y]=0;
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=x+1;y<=n;y++){
            if(last[x][y]){
                add(last[x][y],m,x,y,1,m,1);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1,t,x,y;i<=m;i++){
        cin>>t>>x>>y;
        op[i]=t;
        u[i]=min(x,y);
        v[i]=max(x,y);
    }
    prepare();
    dfs(1,m,1);
    for(int i=1;i<=m;i++){
        if(op[i]==2){
            if(ans[i]){
                cout<<"Y\n";
            }else{
                cout<<"N\n";
            }
        }
    }
    return 0;
}