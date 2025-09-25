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
    
    这里两种操作
    s取头部，添加到t尾部
    t取尾部，添加到u尾部

    也就是说t相当于一个中转的作用，每一个字母都一进一出
    因为想要构造字典序相对最小，所以应该把较小的字母都排到前面
    怎么操作呢
    对于栈顶的字符而言，如果它是最小的，那么它一定是小于等于未放入的最小值的，
    
    字符串题常用
    头大则字典序大

*/



void sol(){

    string s;
    cin>>s;
    stack<char> t;
    vector<char> u;
    int n=s.size();
    vector<char> dp(n);
    for(int i=n-1;i>=0;i--){
        if(i==n-1) dp[i]=s[i];
        else dp[i]=min(dp[i+1],s[i]);
    }
    for(int i=0;i<n-1;i++){
        t.push(s[i]);
        while(!t.empty()&&t.top()<=dp[i+1]){
            u.push_back(t.top());
            t.pop();
        }
    }
    t.push(s[n-1]);
    while(!t.empty()){
        u.push_back(t.top());
        t.pop();
    }
    for(int i=0;i<u.size();i++){
        cout<<u[i];
    }

    
    
    
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}