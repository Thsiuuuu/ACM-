#include <iostream>
#include <algorithm>
#include <vector>

#define int long long 


using namespace std;

const int  maxn=1010;

struct node{
    int w,v;

    int  c;
};


vector <int> dp(maxn,0),dp1(maxn,0);

vector<node> arr(maxn); 
vector<vector<node>> sp(maxn);

bool cmp(const node&a,const node&b){
    return a.c<b.c;
}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,l;
    cin>>l>>n;
    for(int i=0;i<n;i++){
        
        cin>>arr[i].w>>arr[i].v>>arr[i].c;
        
    }



    //cout<<"1\n";
    
    sort(arr.begin(),arr.begin()+n,cmp);

    int  m=1;

    /*for( int i=0;i<n;i++){
        cout<<arr[i].c<<" "<<arr[i].v<<" "<<arr[i].w;
    }*/
    
    sp[1].push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i].c!=arr[i-1].c){
            sp[++m].push_back(arr[i]);
        }else{
            sp[m].push_back(arr[i]);
        }
    }

    //cout<<m<<"\n";

    //cout<<"1\n";
    
    for(int i=1;i<=m;i++){

        dp1=dp;
        for(auto tri:sp[i]){
            for(int t=l;t>=tri.w;t--){
                dp[t]=max(dp[t],dp1[t-tri.w]+tri.v);
            }
        }
        
        //cout<<m<<"\n";
        //cout<<"1\n";
    }


    //for(int i=1;i<=m;i++) cout<<dp[i]<<"\n";
    cout<<dp[l];
    return 0;


}