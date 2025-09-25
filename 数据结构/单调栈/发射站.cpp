#include <iostream>
#include <stack>

using namespace std;

#define int long long 



const int maxn=1e6+10;
int h[maxn],v[maxn],ans[maxn];


stack<int> stand;



signed main(){

     ios::sync_with_stdio(0);
     cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i]>>v[i];

        while(!stand.empty()&&h[stand.top()]<h[i]){
            ans[i]+=v[stand.top()];
            stand.pop();
        }
        if(!stand.empty()){
            if(h[stand.top()]!=h[i]){
                ans[stand.top()]+=v[i];
            }
        }
        stand.push(i);

       // cout<<"1\n";

    }

    //cout<<"1\n";
   

    //for(int i=0;i<n;i++) cout<<ans[i]<<" ";

    int mx=-1;
    for(int i=0;i<n;i++){
        mx=max(mx,ans[i]);
    }
    cout<<mx;

    return 0;

}