#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


#define int long long 

const int N=2e5+10;
bool vis[N]={false};
struct node{
    int idx;
    int cost;
    int cur;
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    queue<node> que;
    que.push({0,0,0});
    vis[0]=true;
    while(!que.empty()){
        auto [idx,cost,cur]=que.front();
        // cout<<idx<<" "<<cost<<" "<<cur<<'\n';
        que.pop();
        if(idx==x){
            cout<<cost;
            return 0;
        }
        if(!vis[(idx+a[idx]+cur)%n]){
            // cout<<"hel1\n";
            vis[(idx+a[idx]+cur)%n]=true;
            que.push({(idx+a[idx]+cur)%n,cost+1,0});
        }
        if(cur<n){
            // cout<<"hel2\n";
            que.push({idx,cost+1,cur+1});
        }
    }
    return 0;
}