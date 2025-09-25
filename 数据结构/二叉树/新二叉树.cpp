#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <vector>

using namespace std;


const int N=27;
struct node{
    int l,r;
    char point;
}tree[N];

void dfs(int id){
    
    if(tree[id].point=='*') return ;
    
    cout<<tree[id].point;
    dfs(tree[id].l);
    dfs(tree[id].r);

}


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tree[i].point>>tree[tree[i].l].point>>tree[tree[i].r].point;
    }

    return 0;
}