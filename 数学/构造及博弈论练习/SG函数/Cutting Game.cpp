#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int w,h;
const int N=210;
int f[N][N];

int sg(int u,int v){
    if(f[u][v]>=0) return f[u][v];
    if(u==v&&v==1) return 0;

    set<int> S;
    
    for(int i=v-1;i>=1;i--){
        S.insert(sg(u,i));
    }
    for(int i=u-1;i>=1;i--){
        S.insert(sg(i,v));
    }

    for(int i=0;;i++){
        if(!S.count(i)){
            return f[u][v]=i;
        }
    }
}

int main(){
    while(scanf("%d%d",&w,&h)!=EOF){
        for(int i=0;i<=210;i++){
            for(int j=0;j<=210;j++){
                f[i][j]=-1;
            }
        }

        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                printf("%d ",f[i][j]);
            }
            printf("\n");
        }
        int res=0;
        res=sg(w,h);
        if(!res){
            printf("LOSE\n");
        }else printf("WIN\n");
    }
}