#include <iostream>
#include <algorithm>

using namespace std;



int main(){
    int n;
    cin>>n;

    bool visit[n+1];
    
    for(int i=2;i*i<=n;i++){
        if(!visit[i]){
            for(int j=i*i;j<=n;j+=i){
                visit[j]=true;
            }
        }
    }

    int cnt=0;
    for(int i=2;i<=n;i++){
        if(!visit[i]){
            cnt++;
        }
    }
    cout<<cnt;
}