#include <iostream>

using namespace std;

#define int long long 

/*

    超过N输，就是谁先拿到N-1，谁必赢

*/


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,k;
    while(cin>>n>>k){
        if(n==k&&!n){
            break;
        }else if((n-1)%(k+1)){
            cout<<"Tang\n";
        }else cout<<"Jiang\n";
    }
}