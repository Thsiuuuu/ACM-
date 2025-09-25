#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


const int N=1e5+10;

vector<int> e[N];
queue<int> que;
bool visited[N];
int depth[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,d;
    cin>>n>>d;

    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    depth[1]=0;
    que.push(1);
    int sum=0;
    while(!que.empty()){
        if(depth[que.front()]>d){
            break;
        }
        sum++;
        int u=que.front();
        que.pop();
        visited[u]=true;
        for(int v:e[u]){
            if(!visited[v]){
                depth[v]=depth[u]+1;
                que.push(v);
            }
        }
    }
    cout<<sum-1;
    return 0;
}