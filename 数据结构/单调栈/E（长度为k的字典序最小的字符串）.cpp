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


const int N=3e5+10;

int k,n;
string s,t,a;

/*
    采用单调栈解决
    为什么呢
    因为首先字典序最小应该使得每一个字母都尽可能的小
    但是选了一个字母我们并不知道是不是最小的，
    如果之后碰到更小的应该再进行调整
    所以要求任何一个字母都应该能进能出

    这跟单调栈的原理不谋而合
    我们可以考虑维护一个递增单调栈，碰到小于栈首且还能选k个数字就弹出'

    单调栈边界情况要特别注意
    严格递增还是递增需要具体分析
    这题如果要求严格递增，那么会把可能得最小淘汰出去
    比如:abbbbbb    bccc
    这样不严格递增形如abbbbbbbc
    严格的话就是abbbbccc

*/



void sol(){

    cin>>n>>k>>s;


    stack<int> stk;

    
    for(int i=0;i<n;i++){
        while(!stk.empty()&&s[stk.top()]>s[i]&&(k<=n-i-1+stk.size())){
            stk.pop();
        }
        if(stk.size()<k){
            stk.push(i);
        }
    }

    stack<int> a;
    while(!stk.empty()){
        a.push(stk.top());
        stk.pop();
    }

    for(int i=0;i<k;i++){
        cout<<s[a.top()];
        a.pop();
    }


}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}