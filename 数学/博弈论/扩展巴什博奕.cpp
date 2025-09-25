#include <iostream>


using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%6==0){
            cout<<"Roy wins!\n";
        }else cout<<"October wins!\n";
    }
    return 0;
}