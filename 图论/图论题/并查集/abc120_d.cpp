#include <iostream>
#include <vector>
#include <cmath>    
#include <algorithm>
using namespace std;

/*

    首先一定是n-1条边开始，才对答案有影响的
    上面是错的，如果开始就删掉一个大支干了也不行
    别的没有
    然后从逆向考虑，如果两条边相连，一定是增加两个点联通块数量的
    末尾答案一定是C2 n


*/

#define int long long 
struct node{
    int a,b;
};
const int N=1e5+10;
int fa[N];
vector<node> Edge(N);
int siz[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy){
        if(siz[fx]<siz[fy]){
            swap(fx,fy);
        }
        siz[fx]+=siz[fy];
        fa[fy]=fx;
    }
}

signed  main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        siz[i]=1;
        fa[i]=i;
    }
    for(int i=0;i<m;i++){
        cin>>Edge[i].a>>Edge[i].b;
    }
    int res=n*(n-1)/2;
    vector<int> ans;
    ans.push_back(res);
    for(int i=m-1;i>=1;i--){
        auto [a,b]=Edge[i];
        int fx=find(a),fy=find(b);
        if(fx^fy){
            res-=(siz[fx]*siz[fy]);
            unite(fx,fy);
            ans.push_back(res);
        }else{
            ans.push_back(res);
        }
    }
    reverse(ans.begin(),ans.end());
    for(int x:ans){
        cout<<x<<'\n';
    }
    return 0;
}