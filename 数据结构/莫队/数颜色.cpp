#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

/*


    带修莫队，如果没有时间的限制，可以通过莫队进行维护，如果有了时间的限制
    相当于在二维基础上又添加了一维，通过不断的时间变换进行莫队

*/

int n,m;
int block;
const int  N=1e6+10;
int blo[N],num[N],vis[N],sum=0,ans[N];
struct node{
    int l,r;
    int id;
    int tim;
    bool operator<(const node&w) const{
        if(l/block!=w.l/block) return l<w.l;
        if(r/block!=w.r/block) return r<w.r;
        return tim<w.tim;
    }
}p[N];

struct R{
    int p,c;
}r[N];

int pt,rt;
std::string op;

void add(int x){
    vis[x]++;
    if(vis[x]==1){
        sum++;
    }
}

void sub(int x){
    vis[x]--;
    if(vis[x]==0){
        sum--;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    block=pow(n,0.66);
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    // for(int i=1;i<=n;i++){
    //     blo[i]=(i-1)/block;
    // }

    int lh,rh;
    for(int i=1;i<=m;i++){
       cin>>op>>lh>>rh;
       if(op=="Q"){
            p[++pt]={lh,rh,pt,rt};
       }else{
            r[++rt]={lh,rh};
       }
    }

    lh=1,rh=0;
    sort(p+1,p+pt+1);
    for(int i=1,x=0;i<=pt;i++){
        while(lh<p[i].l) sub(num[lh++]);
        while(lh>p[i].l) add(num[--lh]);
        while(rh<p[i].r) add(num[++rh]);
        while(rh>p[i].r) sub(num[rh--]);

        while(x<p[i].tim){
            int p=r[++x].p;
            if(lh<=p&&p<=rh){
                sub(num[p]);
                add(r[x].c);
            }
            swap(num[p],r[x].c);
        }
        while(x>p[i].tim){
            int p=r[x].p;
            if(lh<=p&&p<=rh){
                sub(num[p]);
                add(r[x].c);
            }
            swap(num[p],r[x--].c);
        }
        ans[p[i].id]=sum;
    }
    for(int i=1;i<=pt;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
