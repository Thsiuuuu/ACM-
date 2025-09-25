#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <vector>

using namespace std;

int ans=0;
const int N=1e6+10;
struct node{
    int l,r;
}tree[N];

void dfs(int id,int depth){
    if(id==0) return ;
    ans=max(ans,depth);
    dfs(tree[id].l,depth+1);
    dfs(tree[id].r,depth+1);
}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tree[i].l>>tree[i].r;
    }
    dfs(1,1);
    cout<<ans;

    return 0;
}