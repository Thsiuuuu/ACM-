#include  <vector>
#include <algorithm>
#include <iostream>

using namespace std;


const int maxn=1010;
const int limit =10;

int arr[maxn];
int log[maxn];
int stgcd[maxn][limit];


int gcd(int a,int b){
    return !b?a:gcd(b,a%b);
}

void build(int n){
    log[0]=-1;
    for(int i=1;i<=n;i++){
        log[i]=log[i>>1]+1;
        stgcd[i][0]=arr[i];
    }
    for(int p=1;p<=log[n];p++){
        for(int i=1;i+(1<<p)-1<=n;i++){
            stgcd[i][p]=gcd(stgcd[i][p-1],stgcd[i+(1<<(p-1))][p-1]);
        }
    }
}

int query(int l,int r){
    int p=log[r-l+1];
    return gcd(stgcd[l][p],stgcd[r-(1<<p)+1][p]);
}


int main(){



    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(n);
    for(int i=1,l,r;i<=m;i++){
        cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }
    return 0;

}