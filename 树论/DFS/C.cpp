#include <iostream>
#include <algorithm>
#include <vector>


using namespace  std;


/*


    这道题是树，首先画树的时候应该画一个方便自己解题的结构

    因为走到终点，所以拿终点作为树的顶点更方便观察
    那么这里转换之后，我们可以发现，这个树如果走到顶点
    是一个不断向上的过程

    那么这些点如果先选上面的点，会有下面的点拖着
    可以先从底层考虑，底层走完了之后也可以用上层调整

    这个点如果在一层的话，并且下层已经走完的情况下，一定不会深度再增加
    因为不是停在这一层，就是会有别的同一层的点拖着它往上走，依次类推
    势必会走到顶点处，所以说根据深度从深往浅输出即可


*/


/*

    树的结构不好观察的时候，要学会调整树的结构
    可以尝试自底向上考虑

*/
int n,t,s,e,d[100005];
vector<int> g[100005];
vector<int> dis[100005];

void dfs(int u,int fa){
    d[u]=d[fa]+1;
    dis[d[u]].push_back(u);
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>t;
    while(t--){
        cin>>n>>s>>e;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(e,0);
        for(int i=n;i>=1;i--){
            for(auto v:dis[i]){
                cout<<v<<" ";
            }
            
        }
        cout<<"\n";
        for(int i=1;i<=n;i++){
            g[i].clear();
            dis[i].clear();
        }
    }
    return 0;
}