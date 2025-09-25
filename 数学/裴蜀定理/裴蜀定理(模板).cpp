#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

    裴蜀定理:
    
    存在整数x,y使得ax+by=gcd(a,b)成立
    任意的x,y,都有gcd(a,b)|ax+by成立//因为是ax+by一定能被gcd表示出来


*/

int gcd(int a,int b){
    return !b?a:gcd(b,a%b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> num(n);
    for(int i =0;i<n;i++){
        cin>>num[i];
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans=gcd(ans,abs(num[i]));
    }
    cout<<ans;
    return 0;

}