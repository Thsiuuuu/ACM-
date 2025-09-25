#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

/*

    拓扑排序，排完序还有度的点，答案就是自己
    剩下的dfs即可


*/

const int N=1010;
vector<int> e[N];
vector<int> deg(N,0),ans(N);
int n;

int dfs(int u){
    if(deg[u]){
        return u;
    }
    for(int v:e[u]){
        return ans[u]=dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1,v;i<=n;i++){
        cin>>v;
        e[i].push_back(v);
        deg[v]++;
    }

    queue<int> que;
    for(int i=1;i<=n;i++){
        if(!deg[i]){
            que.push(i);
        }
    }
    while(!que.empty()){
        int t=que.front();
        que.pop();
        for(int v:e[t]){
            if(--deg[v]==0){
                que.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(deg[i]){
            ans[i]=i;
        }else{
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}