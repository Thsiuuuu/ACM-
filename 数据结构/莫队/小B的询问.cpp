#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N=5e4+10;
int  ans[N],num[N],cnt[N],blo[N],block;
struct node{
    int l,r;
    int id;
    bool operator<(const node&w) const{
        return blo[l]!=blo[w.l]?l<w.l:(blo[w.l]%2==0?r<w.r:r>w.r);
    }
}p[N];

/*

    莫队是通过按照左端点块数相同情况下，块数是偶数，右端点降序排序
    块数是奇数，右端点升序排序解决
    排完序之后进行遍历

*/

int n,m,k,l=1,r=0;
int sum=0;
void add(int  x){
    sum-=(cnt[x]*cnt[x]);
    cnt[x]++;
    sum+=(cnt[x]*cnt[x]);
}
void sub(int x){
    sum-=(cnt[x]*cnt[x]);
    cnt[x]--;
    sum+=(cnt[x]*cnt[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=m;i++){
        cin>>p[i].l>>p[i].r;
        p[i].id=i;
    }

    int block=n/sqrt(m);
    for(int i=1;i<=n;i++){
        blo[i]=(i-1)/block+1;
    }

    sort(p,p+m);
    for(int i=1;i<=m;i++){
        while(l<p[i].l) sub(num[l++]);
        while(l>p[i].l) add(num[--l]);
        while(r<p[i].r) add(num[++r]);
        while(r>p[i].r) sub(num[r--]);
        ans[p[i].id]=sum;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
