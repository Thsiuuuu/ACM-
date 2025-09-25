#include <iostream>
#include <algorithm>

using namespace std;

const int  N=7;
int main(){
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<=7;i++){
            if((n>>i)&1){
                cout<<(1<<i)<<'\n';
                break;
            }
        }
    }
    return 0;
}