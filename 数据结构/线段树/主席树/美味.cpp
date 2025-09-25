#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*


    首先见到左右区间，然后还有对整个值域进行查找，考虑主席树
    异或这里肯定是优先高位的，那怎么判断呢，
    1或者是0，肯定要找它相反的位，最开始直接找就可以
    如果匹配一段之后呢，既然可以匹配，就说明肯定有对应的数
    设之前已经匹配了ans大小，下面需要最优匹配的数是x的话，我只需要看看最优方向有没有这样的数就可以

*/

const int N=2e5+10;
const int T=N*22;
int n,m,s;
int arr[N],sorted[N],root[N],ls[T],rs[T],siz[T],sum[T];

int clone(int  i){
    int rt=++cnt;
    ls[rt]=ls[i];
    rs[rt]=rs[i];
    sum[rt]=sum[i];
    return rt;
}

void up(int i){
    sum[i]=sum[ls[i]]+sum[rs[i]];
}

int build(int l,int  r){
    int rt=++cnt;
    if(l==r){
        sum[rt]=arr[l];
    }else{
        int mid=(l+r)>>1;
        ls[rt]=build(l,mid);
        rs[rt]=build(mid+1,r);
        up(rt);
    }
    return rt;
}

int addRange(int jobl,int jobr,intt jobv,int l,int r,int i){
    int rt=clone(i);
    if(jobl<=l&&r<=jobr){
        lazy
    }
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return sum[i];
    }
    int mid=(l+r)>>1;
    int ans=0;
    if(jobl<=mid){
        ans+=query(jobl,jobr,l,mid,ls[i]);
    }
    if(jobr>mid){
        ans+=query(jobl,jobr,mid+1,r,rs[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    root[0]=build(1)
    for(int i=1;i<=m;i++){
        int b,x,l,r;
        cin>>b>>x>>l>>r;
        int ans=0;
        for(int j=20;j>=0;j--){
            if((b>>j)&1){
                if(!query(ans,ans+(1<<j)-1,root[l-1],root[r])){
                    ans+=(1<<j);
                }
            }else{
                if(query(ans+(1<<j),ans+(1<<(j+1))-1,root[l-1],root[r])){
                    ans+=(1<<j);
                }
            }
        }
        cout<<(b^(ans+x))<<'\n';
    }
    return 0;
}