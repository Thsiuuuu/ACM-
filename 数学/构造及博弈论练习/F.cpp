#include <iostream>

using namespace std;

#define int long long 

/*

    分为三种情况，都是偶数，一奇一偶，都是奇数


    也可以这么想
    相邻每列差1，每行差m的情况下，我只需要把奇数行放在一起，偶数行放在一起，相邻差为2*m，或者m*(n-(n/2))
    然后奇数行和偶数行分别倒序排列再排在一起

*/


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int  n,m;
        cin>>n>>m;
        
        for(int i=2;i<=n;i+=2){
            for(int j=1;j<=m;j++){
                cout<<(i-1)*m+j<<" ";
            }
            cout<<"\n";
        }
        for(int i=1;i<=n;i+=2){
            for(int j=1;j<=m;j++){
                cout<<(i-1)*m+j<<" ";
            }
            cout<<"\n";
        }

    }

}