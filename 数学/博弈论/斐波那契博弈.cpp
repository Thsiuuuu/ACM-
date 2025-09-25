#include <iostream>

using namespace std;

#define int long long 

const int N=1e15;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;

    
    while(n){
        if(n==1){cout<<1;break;
        else if(n==2) cout<<2;break;}
        else{
            int a=1,b=2,c=3;
            while(c<n){
                a=b,b=c,c=b+a;
            }
            if(c==n){
                cout<<c;
                break;
            }
            n-=b;
        }
    }

    return 0;
}