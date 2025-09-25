#include <iostream>

using namespace std;

#define int long long 

const int N=1e15;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        double n,x;
        cin>>n>>x;
        double  sum=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            sum+=a;
        }
        if(sum/n==x) cout<<"yes\n";
        else cout<<"no\n";
    }z

    return 0;
}