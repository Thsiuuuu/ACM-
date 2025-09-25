#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/*

    分块

*/

const int K=711,N=5e5+10;
int sum[K][K];
int num[N];

int q,t,x,y;

int  main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>q;
    while(q--){
        cin>>t>>x>>y;
        if(t==1){
            num[x]+=y;
            for(int i=1;i<K;i++){
                sum[i][x%i]+=y;
            }
        }else{
            if(x>=K){
                int ans=0;
                for(int i=y;i<=500000;i+=x){
                    ans+=num[i];
                }
                cout<<ans<<'\n';
            }else{
                cout<<sum[x][y]<<'\n';
            }
        }
    }
    return 0;
}