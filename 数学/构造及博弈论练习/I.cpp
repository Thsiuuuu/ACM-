#include <iostream>
#include <map>
using namespace std;

#define int long long 

/*

    首先要让每一个都不等
    
    但是也要考虑到区间和的问题，
    所以这里可以让每个值都变为排序后它的下一个的位置
    那么这个时候最大值只能对上最小值了，但是这个时候仍然满足题意

*/

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> num(n),b(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
        b[i]=num[i];
    }

    sort(b.begin(),b.end());
    map<int,int> mp;
    for(int  i=0;i<n;i++){
        mp[b[i]]=b[(i+1)%n];
    }
    for(int  i=0;i<n;i++){
        cout<<mp[num[i]]<<" ";
    }

}