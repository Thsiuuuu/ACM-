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





void sol(){

    int  n;
    cin>>n;
    vector<int> num(n);

    priority_queue<int,vector<int>,greater<int>> que;
    for(int i=0;i<n;i++){
        cin>>num[i];
        que.push(num[i]);
    }
    int ans=0;
    while(que.size()>1){
        int a=que.top();
        que.pop();
        int b=que.top();
        que.pop();
        // cout<<a<<" "<<b<<"\n";
        // cout<<ans<<"\n";
        ans+=(a+b);
        que.push(a+b);
    }
    cout<<ans;
    
    
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}