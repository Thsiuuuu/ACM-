#include <iostream>


using namespace std;

#define int long long

const int maxn=1e6+10;
int a[maxn],tree[maxn];

int  n;

int lowbit(int x){
    return x&-x;
}

void add(int i,int v){
    while(i<=n){
        tree[i]+=v;
        i+=lowbit(i);
    }
}

int sum(int i){
    int ans=0;
    while(i>0){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

int  query(int l,int r){
    return sum(r)-sum(l-1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int q,op;
    cin>>n>>q;
    for(int i=1;i<=n;i++){cin>>a[i];add(i,a[i]);}

    while(q--){
        cin>>op;
        int i,x;
        cin>>i>>x;
        if(op==1){add(i,x);}
        else cout<<query(i,x)<<"\n";
    }
    return 0;

}