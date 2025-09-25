#include <iostream>
#include <algorithm>
using namespace std;
/*

    考虑到用1降低问题数据大小，缩小问题规模

*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<k-3;i++){
            n--;
            cout<<1<<' ';
        }
        if(n&1){
            cout<<1<<' '<<(n-1)/2<<' '<<(n-1)/2<<'\n';
        }else if(n%4==0){
            cout<<n/2<<' '<<n/4<<' '<<n/4<<'\n';
        }else{
            cout<<2<<' '<<(n-2)/2<<' '<<(n-2)/2<<'\n';
        }
    }
    return 0;
}