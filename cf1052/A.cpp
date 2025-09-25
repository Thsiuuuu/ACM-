#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int t;

// struct node{
//     int idx,num;
// }

void sol(){
    int n;
    cin>>n;
    int mx=-1145141;
    map<int,int> mp;
    multiset<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        
        // st.insert(x);
        mp[x]++;
    }
    for(auto [a,b]:mp){
        st.insert(b);
    }
    int l=0;
    for(int x:st){
        mx=max(mx,(int)x*((int)st.size()-l));
        l++;
    }

    cout<<mx<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}