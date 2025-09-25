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

    int n;
    cin>>n;
    int  sum1=0,sum2=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;i++){
        if(i%2==0) sum1+=a[i];
        else sum2+=a[i];
    }
    cout<<sum1-sum2;

}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}