#include <iostream>
#include <queue>

using namespace std;

int  n,m,e=1,c;
queue<int> ppl;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ppl.push(i);
    }
    while(!ppl.empty()){
        if(e==m){
            cout<<ppl.front()<<" ";
            ppl.pop();
            e=1;
            
        }else{
            e++;
            ppl.push(ppl.front());
            ppl.pop();
        }
    }
    return 0;
}