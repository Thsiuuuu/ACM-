#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
/*

    先想必败态，必败态一定是每个点都是0，那么延伸类比一下，每个点之间没有相互作用
    每个点的状态是独立的，那就可以分开来看，每个点的sg值异或和都是0，才是必败，否则必胜
    或者说这几个点只是碰巧在一张图上而已

*/
const int N=2025;
vector<int>e[N];
int f[N];
int n,m,k,res=0;

int sg(int u){
    if(-1^f[u]) return f[u];//记忆化搜索，如果之前已经访问过该节点，就直接返回sg值就可以

    set<int> S;
    for(int v:e[u]){
        S.insert(sg(v));
    }
    for(int i=0;;i++){
        if(!S.count(i)) return f[u]=i;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        e[u].push_back(v);
    }
    memset(f,-1,sizeof(f));
    for(int i=0,num;i<k;i++){
        scanf("%d",&num);
        res^=sg(num);
    }
    if(res) printf("win");
    else printf("lose");
    return 0;
}