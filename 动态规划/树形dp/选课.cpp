#include <iostream>
#include <algorithm>

using  namespace std;

#define int long long 

const int maxn=303;

int num[maxn],head[maxn],nxt[maxn],to[maxn],dp[maxn][maxn],len[maxn],val[maxn];


int cnt=1,dfncnt=0,n,m;


void build(){
    memset(head,0,sizeof(head));
    memset(dp,0,sizeof(dp));
}

void add(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

int f(int u){
    int i=++dfncnt;
    val[i]=num[u];
    len[i]=1;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        len[i]+=f(v);
    }
    return len[i];
}


int query(){
    f(0);
    for(int i=n+1;i>=2;i--){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i+len[i]][j],val[i]+dp[i+1][j-1]);
        }
    }

    return num[0]+dp[2][m];
}

signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        add(s,i);
        cin>>num[i];
    }

    cout<<query();
    return 0;

}