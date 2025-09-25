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

    反悔贪心
    和k长度字符串都有类似的点
    每种都有可能
    但是我不选很大概率会漏选
    怎么办呢
    那就先都放进来，不满足题意的时候说明不是最优解，再优化


    也就是先弄出来局部最优解，再进行调整，调整出全局最优解
*/

const int N=3e5;
bool st[N];

typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,less<pii>> que;
//less:较大的值优先级更高，

void sol(){

    int n;
    cin>>n;
    vector<int> a(n),b(n);
    memset(st,false,sizeof(st));
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>=b[i]){
            sum-=b[i];
            que.push({b[i],i});
            st[i]=true;
        }else if(!que.empty()){
            if(que.top().first>b[i]){
                sum+=b[que.top().second];
                st[que.top().second]=false;
                que.pop();
                sum-=b[i];
                st[i]=true;
                que.push({b[i],i});
            }
        }
    }
    cout<<que.size()<<"\n";
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(st[i]) cout<<i+1<<" ";
    }
    
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}