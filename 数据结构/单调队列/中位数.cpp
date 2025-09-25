#include <queue>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;

    priority_queue<int> low;
    priority_queue<int,vector<int>,greater<int>> high;

    for(int i=1;i<=n;i++){
        
        int x;
        cin>>x;

        if(i==1) low.push(x);
        else{
            if(x>low.top()){
                high.push(x);
            }else low.push(x);
            int a=low.size(),b=high.size();
            while(abs(a-b)>1){
                
                
                if(a>b){
                    high.push(low.top());
                    low.pop();
                }else{
                    low.push(high.top());
                    high.pop();
                }
                a=low.size(),b=high.size();
            }
        }
        if(i%2==1){
            if(low.size()>high.size()) cout<<low.top()<<"\n";
            else cout<<high.top()<<"\n";
        }

    
    }

    return 0;
}