#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long 
const int N=40010;
int vis[N],p[N],cnt;
int phi[N],ans;

void get_phi(int n){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            p[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;i*p[j]<=n;j++){
            int m=i*p[j];
            vis[m]=1;
            if(i%p[j]==0){
                phi[m]=p[j]*phi[i];
                break;
            }else{
                phi[m]=(p[j]-1)*phi[i];
            }
        }
    }    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    get_phi(n);
    int sum=0;
    for(int i=1;i<n;i++){
        sum+=phi[i];
    }
    sum*=2;
    cout<<sum+1;
    return 0;
    
}