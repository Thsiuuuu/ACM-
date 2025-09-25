#include <iostream>

using namespace std;

#define int long long 

/*

    因为1~n+1范围下，每条斜率为1的线到(1,1)距离相同
    走蛇形

*/


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    if(n==1){
        cout<<"1\n";
        cout<<"1 1\n";
    }else{
        int all=(n)/2+1;
        cout<<all<<"\n";
        int x=1,y=1;
        cout<<x<<" "<<y<<"\n";
        for(int i=1;i<n;i++){
            if(i%2==0){
                x++;
            }else{
                y++;
            }cout<<x<<" "<<y<<"\n";
        }
    }
}