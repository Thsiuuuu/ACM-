#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

/*

    直接bfs模拟即可

    开两个队列，一个记录火，一个记录人

    这道题细节处理比较多，自己把行和列给搞反了，然后时间的计算也比较奇葩，需要额外加1，还有要注意命名变量最好不要用已经用过的变量
    自己写的是火和人同时跑bfs
    其实还有另外一种写法，那就是先把火跑一遍bfs，然后预处理出每个格子着火的时间，然后再对人跑bfs，只需要保证人到的时间小于着火时间就可以

*/

char map[1010][1010];
int t,r,c,sx,sy,fx,fy;
bool vis[1010][1010];

struct node{
    int x,y;
};

typedef pair<node,node> pnn;

int dir[5]={0,1,0,-1,0};

int  main(){

    scanf("%d",&t);
    while(t--){

       memset(vis,false,sizeof(vis));
  
       queue<node>que;

       queue<node> ans;

        scanf("%d%d",&r,&c);

        for(int i=0;i<r;i++){
            scanf("%s",map[i]);
            for(int j=0;j<c;j++){
                if(map[i][j]=='F'){
                    que.push({i,j});
                }else if(map[i][j]=='J'){
                    vis[i][j]=true;
                    map[i][j]='.';
                    sx=i,sy=j;
                    ans.push({i,j});
                }
            }
        }

        if(sx==0||sx==r-1||sy==0||sy==c-1){
            printf("1\n");

            //printf("yes\n");
            continue;
        }//初始就在边界位置

        int level=0,siz;
        bool st=false;

        while(!st&&(ans.size())){

            level++;
            siz=que.size();
            for(int i=0;i<siz;i++){
                node mod=que.front();
                que.pop();

                for(int j=0;j<4;j++){
                    sx=mod.x+dir[j],sy=mod.y+dir[j+1];
                    
                    if(sx<0||sx>=r||sy<0||sy>=c){
                        continue;
                    }

                    char ch=map[sx][sy];
                    if(ch=='#'||ch=='F'){
                        continue;
                    }//障碍物或者已经着了就不走

                    if(ch=='.'){
                        map[sx][sy]='F';
                        que.push({sx,sy});
                    }//如果没着火就着火，沿着它接着着

                }
            }

            siz=ans.size();
            for(int i=0;i<siz&&(!st);i++){

                node mod=ans.front();
                ans.pop();
                for(int j=0;j<4;j++){
                    sx=mod.x+dir[j],sy=mod.y+dir[j+1];

                    // printf("%d %d\n",sx,sy);

                    if(sx<0||sx>=r||sy<0||sy>=c){
                        // printf("%d %d\n",sx,sy);
                        continue;
                    }//越界就跳过

                    char ch=map[sx][sy];
                    if(ch=='#'||ch=='F'||vis[sx][sy]){
                        // printf("%d %d\n",sx,sy);
                        continue;
                    }//走过了或者着火//障碍物就不能走


                    // printf("%d %d\n",r,c);
                    // printf("%d\n",sx==c-1?1:0);
                    if(sx==0||sx==r-1||sy==0||sy==c-1){

                        // printf("%d %d",r,c);
                        // printf("%d %d\n",sx,sy);
                        st=true;
                        break;
                    }//符合题意就弹出

                    if(ch=='.'){
                        // printf("%d %d\n",sx,sy);
                        vis[sx][sy]=true;
                        ans.push({sx,sy});
                    }//可以走的放进去
                }

            }

        }

        if(st){
            printf("%d\n",++level);
        }else{
            printf("IMPOSSIBLE\n");
        }

    }
    return 0;
}