#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


#define int long long

const int maxn=1e5+10;

int dp[maxn],arr[maxn],num[maxn]={0};

map<int,int> mp;

signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    sort(arr+1,arr+1+n);
    int m=1;
    mp[m]=arr[1];
    num[mp[1]]=1;
    for(int i=2;i<=n;i++){
        if(arr[i]!=arr[i-1]){
            mp[++m]=arr[i];
            num[mp[m]]+=1;
        }else{
            num[mp[m]]+=1;
        }
    }

    if(m==1){
        cout<<mp[m]*num[mp[m]];
    }else if(m==2){
        int a=mp[1],b=mp[2];
        int x=a*num[a];
        int y=b*num[b];
        if(a+1==b){
            cout<<max(x,y);
        }else{
            cout<<x+y;
        }
    }else{
        for(int i=m;i>=1;i--){
            if(i==m){
               int a=mp[m];
               dp[m]=a*num[a];
               
            }else if(i==m-1){
                int a=mp[i],b=mp[i+1];
                int x=a*num[a],y=b*num[b];

                if(a+1==b) dp[i]=max(x,y);
                else dp[i]=x+y;
            }else{
                int a=mp[i],b=mp[i+1],c=mp[i+2];
                int x=a*num[a],y=b*num[b],z=c*num[c];
            

                if(a+1==b){
                    dp[i]=max(x+dp[i+2],dp[i+1]);
                }else{
                    dp[i]=x+dp[i+1];
                }
            }
        }




        cout<<dp[1];
    }

    return 0;
    

}