#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

/*

    理解错题意了（不止一处），以为会有被放回去的情况
    题意就是跑一个bfs，但是可以剪枝，因为有的路走过了
    但是拿没拿钥匙是有区别的，很显然如果来到同一个点的情况下，钥匙状态相同，那么就不走了

    注意数据量不大的时候表示一个选取的状态（我怎么知道那个选了，那个没选？）的时候，可以采用状态压缩
    


*/

char map[25][25];
int vis[25][25][1025];
int t,n,m;
int sx,sy;

int dir[5]={-1,0,1,0,-1};

struct node{
    int x,y;
    int idx;
};

int bfs(int sx,int sy){

    memset(vis,0,sizeof(vis));

    queue<node> que;

    que.push({sx,sy,0});

    while(!que.empty()){

        node mod=que.front();
        que.pop();

        int temx=mod.x,temy=mod.y,temidx=mod.idx;

        if(vis[temx][temy][temidx]+1>=t){
            return -1;
        }
        
        for(int i=0;i<4;i++){

            int temx=mod.x,temy=mod.y,temidx=mod.idx;
            
            sx=temx+dir[i],sy=temy+dir[i+1];//移动之后的坐标

            if(sx<0||sx>=n||sy<0||sy>=m) continue;
            char c=map[temx+dir[i]][temy+dir[i+1]];//移动之后的字符
            

            if(map[sx][sy]=='*'||vis[sx][sy][temidx]){
                continue;
            }

            if(map[sx][sy]=='^'){
                return vis[temx][temy][temidx]+1;
            }
            
            if(c=='.'||c=='@'){
                vis[sx][sy][temidx]=vis[temx][temy][temidx]+1;
                que.push({sx,sy,temidx});
            }
           
            if(c<='J'&&c>='A'&&(temidx&(1<<(c-'A')))){
                vis[sx][sy][temidx]=vis[temx][temy][temidx]+1;
                que.push({sx,sy,temidx});
            }

            if(c<='j'&&c>='a'&&(!vis[sx][sy][temidx])){
                int res=temidx|(1<<(c-'a'));
                vis[sx][sy][res]=vis[temx][temy][temidx]+1;
                que.push({sx,sy,res});
            }

        }
    }

    return -1;
}

int main(){

    while(scanf("%d%d%d",&n,&m,&t)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",map[i]);
            for(int j=0;j<m;j++){
                if(map[i][j]=='@'){
                    sx=i,sy=j;
                    break;
                }
            }
        }

        printf("%d\n",bfs(sx,sy));
    }
    return 0;
}