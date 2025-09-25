#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

/*


    看见不会形成奇环，想到二分图
    其实就是把树分成一个二分图，然后看两个集合之间还有多少个点没有相连就可以

    最开始写的O(n3)的复杂度


*/

const int N=110;
int n;
vector<int> e[N];

vector<int> c1,c2;
int l1=0,l2=0;
bool st[N][N]={false};

struct node{
    int i,j;
}stk[N*N];
int sz=0;

void dfs(int u,int c,int fa){
    if(c==1){
        c1.push_back(u);
        l1++;
        st[u][fa]=true;
        st[fa][u]=true;
    }else{
        c2.push_back(u);
        l2++;
        st[u][fa]=true;
        st[fa][u]=true;
    }
    for(int  v:e[u]){
        if(v!=fa){
            dfs(v,3-c,u);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs(1,1,0);
    int cnt=l1*l2-n+1;
    cout<<((cnt&1)?"First":"Second")<<'\n';
    cout.flush();
    
    for(int x:c1){
        for(int y:c2){
            if(!st[x][y]){
                stk[++sz]={x,y};
            }
        }
    }
    while(cnt){
        if(cnt%2==0){
            int x,y;
            cin>>x>>y;
            if(x==-1&&y==-1) return 0;
            st[x][y]=st[y][x]=true;
        }else{
            while(sz&&st[stk[sz].i][stk[sz].j]){
                sz--;
            }
            int u=stk[sz].i,v=stk[sz].j;
            cout<<min(u,v)<<" "<<max(u,v)<<'\n';//要求输出从小到大的顺序，没看题干
            cout.flush();
            st[u][v]=st[v][u]=true;
            sz--;
        }
        cnt--;
    }

    return 0;
}