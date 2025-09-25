#include <iostream>



using namespace std;


#define int  long long

int ans;

int n,w;
int a[20];
int f[1<<20],len[1<<20];

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>w;
    for(int i=0;i<n;i++) cin>>a[i];

    int s=(1<<n);

    for(int i=0;i<s;i++){
        f[i]=11451419198;
    }

    
    f[0]=1;
    len[0]=w;
    for(int i=0;i<s;i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)) continue;
            if(len[i]>=a[j]){
                if(f[i|(1<<j)]>=f[i]){
                    f[i|(1<<j)]=f[i];
                    len[i|(1<<j)]=max(len[i|(1<<j)],len[i]-a[j]);
                }
            }else{
                if(f[i]+1<=f[i|(1<<j)]){
                    f[i|(1<<j)]=f[i]+1;
                    len[i|(1<<j)]=max(len[i|(1<<j)],w-a[j]);
                }
            }
        }
    }


    cout<<f[s-1];
    return 0;


}