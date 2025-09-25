#include <iostream>

using namespace std;

#define int long long 

/*

    裂项
    合法的解是n,n+1,n*(n+1)

*/


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    if(n==1){
        cout<<-1;
    }else{
        cout<<n<<" "<<n+1<<" "<<n*(n+1);
    }

}