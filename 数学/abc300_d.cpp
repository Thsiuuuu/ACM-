#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*

    枚举的话，考虑一下数据范围，最劣的情况c<1e6
    
    可以预处理出所有范围内的素数，然后进行枚举


*/

#define int long long 

const int N=3e5+10;
bool vis[N];
int n;

int qmi(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        b>>=1;
        a*=a;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    vector<int> prm;
    for(int i=2;i*i<=N-2;i++){
        if(!vis[i]){
            for(int j=i*i;j<=N-2;j+=i){
                vis[j]=true;
            }
        }
    }
    for(int i=2;i<=N-2;i++){
        if(!vis[i]) prm.push_back(i);
    }
    int ans=0;
    int siz=prm.size();
    for(int i=0;qmi(prm[i],5)<n&&i<siz;i++){
        for(int j=i+1;qmi(prm[j],3)<n&&j<siz;j++){
            for(int k=j+1;qmi(prm[i],2)*qmi(prm[k],2)*prm[j]<=n&&k<siz;k++){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}