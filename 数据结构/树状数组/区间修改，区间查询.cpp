#include <iostream>

using namespace std;



const int maxn=1e6+10;
int tree1[maxn],tree2[maxn];

int  n,q;

int lowbit(int i){
    return i&-i;
}

void add(int tree[],int i,int v){
    while(i<=n){
        tree[i]+=v;
        i+=lowbit(i);
    }
}

int sum(int tree[],int  i){
    int ans=0;
    while(i>0){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

void uni(int l,int r,int v){
    add(tree1,l,v);
    add(tree1,r+1,-v);
    add(tree2,l,(l-1)*v);
    add(tree2,r+1,-r*v);
}

int query(int l,int r){
    return sum(tree1,r)*r-sum(tree2,r)-sum(tree1,l-1)*(l-1)+sum(tree2,l-1);
}


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        uni(i,i,x);
    }

    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            int x;
            cin>>x;

            uni(l,r,x);
        }else cout<<query(l,r)<<"\n";
    }
    return 0;


}