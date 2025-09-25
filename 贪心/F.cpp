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

    依然是字符串
    构造字典序最小从头出发，只要一位比其余所有可能都小，那它就是最小
    所以考虑贪心

    把非a的尽可能化小
    所以a:不用转化
    b:b->a,b->c->a
    c:c->b,c->a

*/



void sol(){

    int t;
    cin>>t;
    while(t--){
        int n,q;
        string s;

        vector<vector<set<int>>> st(3,vector<set<int>>(3));
        
        cin>>n>>q>>s;


        for(int i=0;i<q;i++){
            char x,y;
            cin>>x>>y;
            st[x-'a'][y-'a'].insert(i);
        }

        for(int i=0;i<n;i++){
            if(s[i]=='a') continue;
            if(s[i]=='b'){
                if(!st[1][0].empty()){
                    st[1][0].erase(st[1][0].begin());
                    s[i]='a';
                    continue;
                }
                if(!st[1][2].empty()){
                    auto tra1=*st[1][2].begin();
                    auto tra2=st[2][0].lower_bound(tra1);
                    if(tra2!=st[2][0].end()){
                        st[1][2].erase(tra1);
                        st[2][0].erase(tra2);
                        s[i]='a';
                        continue;
                    }
                }
            }
            if(s[i]=='c'){
                if(!st[2][0].empty()){
                    st[2][0].erase(st[2][0].begin());
                    s[i]='a';
                    continue;
                }
                if(!st[2][1].empty()){
                    auto tra1=*st[2][1].begin();
                    auto tra2=st[1][0].lower_bound(tra1);
                    st[2][1].erase(tra1);
                    s[i]='b';
                    if(tra2!=st[1][0].end()){
                        st[1][0].erase(tra2);
                        s[i]='a';
                        continue;
                    }
                    
                }
            }
        }
        cout<<s<<"\n";
        
    }
    
    
    
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}