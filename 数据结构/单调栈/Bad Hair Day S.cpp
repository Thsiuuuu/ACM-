#include <iostream>
#include <stack>


using namespace std;

const int maxn=1e5;
int cow[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    stack<int> stk;
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cow[i];
        while(!stk.empty()&&cow[stk.top()]<=cow[i]){
            ans+=(i-stk.top()-1);
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()){
        ans+=(n-1-stk.top());
        stk.pop();
    }
    cout<<ans;

}