#include <queue>
#include <iostream>

using namespace std;

int n,m,cnt=0,number;
bool st[1002];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>m>>n;
    queue<int> mem;

    for(int i=1;i<=n;i++){
        cin>>number;
        if(!st[number]){
            if(mem.size()>=m){
                st[mem.front()]=false;
                mem.pop();
            }
            mem.push(number);
            st[number]=true;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;

}