#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>


using namespace std;

#define int long long 

/*

    开一个小根堆存储，当比堆顶大的时候，弹出，并观察堆顶左右能否放进去


*/


typedef pair<int,int> pii;
const int N=3e6+10;

bool st[N];
int a[N];

void sol(){

    priority_queue<int,vector<pii>,greater<pii>> que;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(st,false,sizeof(st));
    for(int i=0;i<n;i++){
        if(que.empty()&&a[i]>0){
            que.push({a[i],i});
            continue;
        }
        if(!que.empty()){
            if(que.top().first<=a[i]){
                if(que.top().second+1==i){
                    que.pop();
                    que.push({a[i],i});
                }
            }
        }

    }


}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    sol();
    return 0;

}
