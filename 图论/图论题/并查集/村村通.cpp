#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010;

/*

    不用开桶，直接统计所有并查集头部等于自己的就可以
    因为每个集合必定有且仅有一个头，这个元素标号一定等于自己


*/


int father[N];
int siz[N],num[N],cnt;

int find(int x){
    return father[x]==x?x:father[x]=find(father[x]);
}

void unite(int x,int y){
    
    int fx=find(x),fy=find(y);
    if(fx==fy) return ;
    if(siz[fx]<=siz[fy]){
        swap(fx,fy);
    }

    siz[fx]+=siz[fy];
    father[fy]=fx;



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    while(cin>>n>>m){
        if(!n){
            return 0;

        }
        fill(father,father+1+N,0);
        fill(siz,siz+1+N,0);
        fill(num,num+1+N,0);
        cnt=0;
        for(int i=1;i<=n;i++){
            father[i]=i;
            siz[i]=1;
        }
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            unite(u,v);
        }

        for(int i=1;i<=n;i++){
            if(!num[find(i)]){
                num[find(i)]=1;

                // cout<<find(i)<<"\n";

                cnt++;
            }
        }
        cout<<cnt-1<<'\n';
    }
}

