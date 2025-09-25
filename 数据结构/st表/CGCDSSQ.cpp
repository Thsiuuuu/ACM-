#include  <vector>
#include <algorithm>
#include <iostream>
#include <map>

#define int long long


using namespace std;


const int maxn=100010;
const int limit=20;

int arr[maxn];
int lg[maxn];
int stgcd[maxn][limit];

map<int,int>  all;


int gcd(int a,int b){
    return !b?a:gcd(b,a%b);
}

void build(int n){
    lg[0]=-1;
    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
        stgcd[i][0]=arr[i];
    }
    for(int p=1;p<=lg[n];p++){
        for(int i=1;i+(1<<p)-1<=n;i++){
            stgcd[i][p]=gcd(stgcd[i][p-1],stgcd[i+(1<<(p-1))][p-1]);
        }
    }
}

int query(int l,int r){
    int p=lg[r-l+1];
    return gcd(stgcd[l][p],stgcd[r-(1<<p)+1][p]);
}


signed main(){



    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(n);
    

    for(int i=1;i<=n;i++){

        int start=i;
        while(start<=n){

            int model=query(i,start);

            int l=start,r=n;
            int ans=start;
            while(l<=r){
                int mid=(l+r)/2;
                if(model!=query(i,mid)){
                    r=mid-1;
                }else{
                    ans=mid;
                    l=mid+1;
                }
            }


            all[model]+=(ans-start+1);
            start=ans+1;

        }

    }


    cin>>q;

    while(q--){
        int x;
        cin>>x;
        cout<<all[x]<<"\n";

    }



    return 0;

}