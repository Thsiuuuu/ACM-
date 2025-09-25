#include <iostream>
#include <set>

using namespace std;


#define int long long 

struct node{
    int m,idx;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m;
    cin>>n>>m;
    vector<node> pro(n+1);
    for(int i=1;i<=n;i++){
        cin>>pro[i].m;
        pro[i].idx=i;
    } 


    
}