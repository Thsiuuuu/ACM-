#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int  N=1e5+10;
struct node{
    int l,r;
    int val;
    bool operator<(const node&a) const{
        return val<a.val;
    }
}p[N];

int n,q,blo;
int lf[N],rf[N]

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>q;
    blo=sqrt(n);
    while(q--){
        int op,a,b,c;
        cin>>op>>a>>b;
        if(op==1){
            cin>>c;

        }else{

        }
    }
}