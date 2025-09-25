#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define int long long 

const int N=2e5+10;

struct node{
    int l=1145141919,r=-1145141919;
    vector<int> e;
};
/*


    自底向上考虑
    这里要特别注意根节点的判断

    然后区间左端点等于所有左端点最小值，右端点等于所有右端点最小值

*/


vector<node> mem(N);

int siz[N]={0};

int cnt=1;

void dfs(int u,int fa){
    
    if(fa&&mem[u].e.size()==1){

        //cout<<"hello\n";

        mem[u].l=cnt;
        mem[u].r=cnt++;
        return ;
    }

    for(auto v:mem[u].e){
        if(v!=fa){

            //cout<<v<<" "<<u<<'\n';
            
            dfs(v,u);
            mem[u].l=min(mem[u].l,mem[v].l);
            mem[u].r=max(mem[u].r,mem[v].r);
        }
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mem[u].e.push_back(v);
        mem[v].e.push_back(u);
    }

    
    dfs(1,0);

    //cout<<cnt<<"\n";
    for(int  i=1;i<=n;i++){
        cout<<mem[i].l<<" "<<mem[i].r<<"\n"; 
    }
    // for(int i=1;i<=n;i++) cout<<siz[i]<<" ";
    // cout<<siz[1]<<"\n";
    

    return 0;


}