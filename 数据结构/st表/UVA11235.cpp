#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


const int maxn=100001;
const int limit=17;


int arr[maxn],log[maxn],bucket[maxn],left[maxn],right[maxn];
int stmax[maxn][limit];


void build(int n){
    arr[0]=-23333333;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(arr[i-1]!=arr[i]){
            right[cnt]=i-1;
            left[++cnt]=i;
        }
        bucket[i]=cnt;
    }

    right[cnt]=n;
    log[0]=-1;
    for(int i=1;i<=cnt;i++){
        log[i]=log[i>>1]+1;
        stmax[i][0]=right[i]-left[i]+1;
    }
    for(int p=1;p<=log[cnt];p++){
        for(int i=1;i+(1<<p)-1<=cnt;i++){
            stmax[i][p]=max(stmax[i][p-1],stmax[i+(1<<p-1)][p-1]);
        }
    }
}


int query(int l,int r){
    if(l>r){
        int tmp=l;
        l=r;
        r=tmp;
    }

    int lbucket=bucket[l];
    int rbucket=bucket[r];
    if(lbucket==rbucket){
        return r-l+1;
    }
    int a=right[lbucket]-l+1,b=r-left[rbucket]+1,c=0;
    if(lbucket+1<rbucket){
        int from=lbucket+1,to=rbucket-1,p=log[to-from+1];
        c=max(stmax[from][p],stmax[to-(1<<p)+1][p]);
    }
    return max(max(a,b),c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n>>m){
        if(!n)  break;
        for(int i=1;i<=n;i++)[
            cin>>arr[i];
        ]
        build(n);
        for(int i=1,l,r;i<=m;i++){
            cin>>l>>r;
            cout<<query(l,r)<<"\n";
        }
    }
    return 0;
}