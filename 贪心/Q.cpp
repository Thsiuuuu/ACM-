#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define int long long 

/*

    两种情况
    第一种头部数字>=2，
    如果第一位以后都是9，那就是这个数
    如果有一位不是9，则是a0-1 9 9 9 9 

    第二种开头是1，
    
    情况1:100000这个时候最大的就是99999
    情况2：
    找之后最近的>=1的，
    如果这位之后一直是9，就不用发生变化
    如果有一位不是9，则变成a0 a1 a2 .... ai-1 9 9 9 

*/





void sol(){


   int t;
   cin>>t;
   while(t--){
    // cout<<t<<1" ";
    string s;
    cin>>s;
    if(s.size()==1) cout<<s<<"\n";
    else{
        if(s[0]>='2'){
            bool st=true;
            for(int i=1;i<s.size();i++){
                if(s[i]!='9'){
                    char a=s[0]-1;
                    cout<<a;
                    for(int j=0;j<s.size()-1;j++) cout<<"9";
                    cout<<"\n";
                    st=false;
                    break;
                }
            }
            if(st) cout<<s<<"\n";
        }else{

            bool test=false;
            for(int i=1;i<s.size();i++){
                if(s[i]!='0'){test=true;break;}
            }
            
            // cout<<"1\n";
            if(!test){
                // cout<<"1\n";
                for(int i=0;i<s.size()-1;i++){
                    cout<<"9";
                }
                cout<<"\n";
                continue;
            }//100000000

            if(s[0]=='1'&&s.size()==2){
                cout<<s<<"\n";
                continue;
            }

            bool st=false;
            int ans=0;
            for(int i=1;i<s.size()-1;i++){
                if(s[i]>='1'){
                    st=true;
                    ans=i;
                    break;
                }
            }
             
            if(!st){
                cout<<s<<"\n";
            }else{

                bool judge=true;
                for(int i=ans+1;i<s.size();i++){
                    if(s[i]!='9'){
                        s[i]='9';
                        judge=false;
                    }
                }
                if(!judge) s[ans]-=1;
                cout<<s<<"\n";
            }
        }
    }
   }
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}