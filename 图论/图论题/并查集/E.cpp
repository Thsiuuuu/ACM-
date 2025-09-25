#include <iostream>
#include <vector>

using  namespace std;

const int N=5e5+10;

int f[N],siz[N];
int n,m;

/*

    并查集板子题，合并并查集即可
    最后查找每个人所在集合的元素有多少个

*/

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    f[y]=x;
    siz[x]+=siz[y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<=n;i++){
        f[i]=i;
        siz[i]=1;
    }
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        vector<int> ppl(k);
        for(int j=0;j<k;j++){
            cin>>ppl[j];
            if(j){
                unite(ppl[j],ppl[j-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){

        // cout<<find(i)<<" ";

        cout<<siz[find(i)]<<" ";

        // cout<<"\n";
    }
    return 0;
}