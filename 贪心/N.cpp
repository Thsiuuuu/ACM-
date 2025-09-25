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

/*



    
*/

int n;
string s;

void sol(){


   cin>>n>>s;
   int cnt1=0,cnt2=0;//cnt1表示（，cnt2表示）
   if(n&1) cout<<":(";
   else if(s[0]==')'||s[n-1]=='('){cout<<":(";}
   else{


        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt1++;
        }

        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                if(cnt1<n/2){
                    s[i]='(';
                    cnt1++;
                }else s[i]=')';
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') sum++;
            else sum--;
            if(i<n-1&&sum<=0){
                cout<<":(";
                return ;
            }
        }
        if(!sum) cout<<s;
        else cout<<":(";
   }
   
    
    
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}