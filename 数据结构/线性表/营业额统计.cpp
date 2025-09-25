#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define int long long

int n;
int sum=0;
set<int> money;


signed main(){
    
    
    
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i==1){
            money.insert(x);
            sum+=x;
        }else{
            
            auto it=money.lower_bound(x);
           
            if(it==money.end()){
                auto l=--money.lower_bound(x);
                sum+=abs(x-*l);
            }else if(it==money.begin()){
                sum+=abs(x-*it);
            }else{
                auto l=--money.lower_bound(x);
                sum+=min(abs(x-*it),abs(x-*l));
            }
            money.insert(x);
        }
        //cout<<sum<<"\n";
        
    }

    cout<<sum;
    return 0;
}