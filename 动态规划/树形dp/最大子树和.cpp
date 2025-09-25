#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long  


const int maxn=16010;

int n;
vector<int> e[maxn],num(maxn),f(maxn);

void dfs(int u,int fa){
    f[u]=num[u];
    for(int i=0;i<e[u].size();i++){
        int t=e[u][i];
        if(t!=fa){
            dfs(t,u);
            if(f[t]>0) f[u]+=f[t];
        }
    }
}


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }

    for(int i=0;i<n-1;i++){
        int  a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1,0);
    int ans=-1145141919;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;

}