#include <iostream>
#include <algorithm>
#include <vector>

#define int long long 

using namespace std;

const int maxn=5e5+10;

int arr[maxn],sp[maxn],tree[maxn];
int n,m;

int lowbit(int i){
    return i&(-i);
}

void add(int i,int v){
    while(i<=m){
        tree[i]+=v;
        i+=lowbit(i);
    }
}

int query(int i){
    int ans=0;
    while(i>0){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;

}

struct Node{
    int  ans1,ans2;
}l[maxn],r[maxn];

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sp[i]=arr[i];
    }

    sort(sp+1,sp+n+1);
    m=1;
    for(int i=2;i<=n;i++){
        if(sp[m]!=sp[i]){
            sp[++m]=sp[i];
        }
    }

    for(int i=1;i<=n;i++){
        arr[i]=lower_bound(sp+1,sp+m+1,arr[i])-sp;
    }

    
    for(int i=n;i>=1;i--){
        r[i].ans2=query(arr[i]-1);//ans2逆序
        r[i].ans1=n-i-r[i].ans2;//ans1顺序
        add(arr[i],1);
    }
    memset(tree,0,sizeof(tree));
    for(int i=1;i<=n;i++){
        l[i].ans1=query(arr[i]-1);
        l[i].ans2=i-1-l[i].ans1;
        add(arr[i],1);
    }

    int  tri1=0,tri2=0;
    for(int i=1;i<=n;i++){
        tri1+=l[i].ans2*r[i].ans1;
        tri2+=l[i].ans1*r[i].ans2;
    }

    cout<<tri1<<" "<<tri2<<"\n";

    return 0;

}
