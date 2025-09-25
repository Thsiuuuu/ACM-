#include <iostream>

using namespace std;

#define int long long 

const int mod=1e9+7;
const int N=1e5+10;
int money[N],arr[N];
int n,w;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    money[0]=1;
    for(int i=0;i<=w;i++){
        for(int j=0;j<n;j++){
            if(i>=arr[j]){
                money[i]=(money[i]%mod+money[i-arr[j]])%mod;
            }
        }
    }
    cout<<money[w]%mod;
    return 0;
}