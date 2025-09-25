#include <iostream>

using namespace std;


#define int  long long 


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int  n,l,r;
    cin>>n>>l>>r;
    bool st=true;
    for(int  i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%(l+r)==0){
            st=false;
        }
    }
    if(st) cout<<"Second\n";
    else cout<<"First\n";
    return 0;
}