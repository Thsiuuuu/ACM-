#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 


const int N=3000001;
int inv[N];
int n,p;

void build(int n){
    inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=(p-inv[p%i]*(p/i)%p);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>p;

    build(n);
    for(int i =1;i<=n;i++){
        cout<<inv[i]<<'\n';
    }
    return 0;
}