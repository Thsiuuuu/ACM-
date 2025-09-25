#include <iostream>

using namespace std;


/*
    首先可以发现全是1的状态必胜，这是一个基础的必胜态
    同时全是0的状态必败，基础必败态


    然后我们往回想，每堆都是1的情况下，必然是从一些2&&一些1转移过来的

    但是全是二的状态情况下，后手照着先手走，先手必败，同时可以发现偶数下先手必败，
    也就是说先手面对部分不为偶数的情况，只需要让后手面对全是偶数的情况，那么一定是先手必胜
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    bool st=true;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x&1){
            st=false;
        }
    }
    if(st) cout<<"second\n";
    else cout<<"first\n";
}