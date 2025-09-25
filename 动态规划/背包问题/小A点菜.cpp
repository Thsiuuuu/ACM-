#include <iostream>
#include <algorithm>

using namespace std;

#define int long long


const int N=110;

int a[N],bag[1010];


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    memset(bag,0,sizeof(bag));

    bag[0]=1;
    for(int i=0;i<n;i++){
        for(int j=m;j>=a[i];j--){
            bag[j]=(bag[j]+bag[j-a[i]]);
        }
    }

    cout<<bag[m];
    return 0;
}