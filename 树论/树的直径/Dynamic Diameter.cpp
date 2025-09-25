#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int N=3e5+10;
/*


    首先题目很明显，可以从树的直径的角度出发
    如果不在直径上，那么一定对答案是无影响的
    因为如果连接的这个点是端点，但是不在直径上面，那么它能延伸出来的最大长度不会超过d-1
    这时候加上新边直径也是d
    如果不是端点的话，那不如走原来的路
    如果在直径上面，但是不在直径的端点上面的话，显然原来的直径还是最长的
    如果在直径的端点上的话，直径的长度会+1
    所以只需要处理出直径的端点就可以，因为打印所有的直径
    所以说可以给每个直径的端点打上标记

    注意特判，等于1的时候自己的程序会越界，而且得不到正确答案
*/

vector<int> e[N];
int last[N],dis[N],st[N]={0};
bool vis[N]={false};
int head,tail,d;
int n;

void dfs1(int u,int fa){
    dis[u]=dis[fa]+1;
    last[u]=fa;
    for(int v:e[u]){
        if(v^fa){
            dfs1(v,u);
        }
    }
}

void diameter(){
    head=tail=0;
    dfs1(1,0);
    for(int i=2;i<=n;i++){
        if(dis[head]<=dis[i]) head=i;
    }
    dis[0]=-1;
    dfs1(head,0);
    for(int i=1;i<=n;i++){
        if(dis[tail]<=dis[i]) tail=i;
    }
    st[tail]=st[head]=1;
    for(int i=tail;i;i=last[i]){
        vis[i]=true;
    }
    d=dis[tail];
}

void dfs2(int u,int fa,int w){
    if(++w==d){
        st[u]=1;
        return ;
    }
    for(int v:e[u]){
        if(v^fa){
            dfs2(v,u,w);
        }
    }
}

void check(){
    int l=1;
    for(int i=last[tail];i!=head;i=last[i]){
        for(int v:e[i]){
            if(!vis[v]){
                dfs2(v,i,max(l,d-l));
            }
        }
        l++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    if(n==1){
    	cout<<1;//忘记特判了，因为如果只有一个点的话，再加入一个点，构成的直径是1
    	return 0;
	}
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    diameter();
    check();
    for(int i=1;i<=n;i++){
        if(st[i]){
            cout<<d+1<<'\n';
        }else cout<<d<<'\n';
    }
    return 0;
}