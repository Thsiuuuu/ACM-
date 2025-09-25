#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>


using namespace std;

#define int long long 

int t,x,n,m;

void sol(){

    cin>>t;
    while(t--){
        cin>>x>>n>>m;
        int cnt1=n,cnt2=m,st=true;
        while(n){
            int a=x/2+10;
            if(a<x){
                n--;
                x=a;
            }else{
                break;
            }
        }
        while(m){
            x-=10;
            m--;
            if(x<=0){
                st=false;
                break;
            }
        }
        if(!st){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }

}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}