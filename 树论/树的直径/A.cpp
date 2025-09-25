#include <iostream>
#include <algorithm>
#include <vector>
using  namespace std;

/*


    首先如果随意取点，那么会有走回头路的情况，不如从一个树的底部出发
    那么我以什么为结尾呢，怎么结尾能够让长度最长呢，那就是直径了
    实际是两个操作，一个是走直径，还有一个走分叉，和鱼骨形状差不多


*/


const int N=2e5+5;

vector<int> t[N];

int dep[N],fa[N],vis[N];

void diameter(int x,int f,int &p){
    dep[x]=dep[f]+1,fa[x]=f;
    if(dep[x]>dep[p])p=x;
    for(int i=0;i<t[x].size();i++){
        int j=t[x][i];
        if(j==f) continue;
        diameter(j,x,p);
    }
}

int ans[N<<2],cnt=0;

bool print(int x,int f,int &rest){
    if(!vis[x]){
        if(!rest) return false;
        rest--;
    }
    ans[++cnt]=x;
    int tag=0;
    for(int i=0;i<t[x].size();i++){
        int j=t[x][i];
        if(j==f) continue;
        if(vis[j]){
            tag=j;
            continue;
        }
        bool f1=print(j,x,rest);
        if(f1) ans[++cnt]=x;
    }
    if(tag) print(tag,x,rest);
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int l;
    cin>>l;
    while(l--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            t[u].push_back(v),t[v].push_back(u);
        }
        int a=0,b=0;
        diameter(1,0,a);
        diameter(a,0,b);
        for(int i=b;i;i=fa[i]) vis[i]=1;
        int depth=dep[b],rest=k;
        print(a,0,rest);
        cout<<cnt<<"\n";
        for(int i=1;i<=cnt;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        cnt=0;
        for(int i =1;i<=n;i++){
            t[i].clear(),vis[i]=dep[i]=fa[i]=0;
        }
    }
    return 0;
}