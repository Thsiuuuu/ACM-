#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
/*

    首先爆搜会超时，考虑剪枝，
    首先可以对R,H进行限制
    然后从下向上考虑得到每个R和H的最大值范围
    然后还可以对V和S进行限制
    还可以从上向下考虑，再对S进行限制

*/

const int N=25,inf=1e9;

int n,m;
int minv[N],mins[N];
int R[N],H[N];
int ans=inf;

void dfs(int u,int  v,int s){
    if(v+minv[u]>n) return;
    if(s+mins[u]>=ans) return ;
    if(s+2*(n-v)/R[u+1]>=ans) return;

    if(u==0){
        if(v==n) ans=s;
        return ;
    }

    for(int r=min(R[u+1]-1,(int)sqrt(double(n-v)));r>=u;r--){
        for(int h=min(H[u+1]-1,(n-v)/r/r);h>=u;h--){
            int tmp=0;
            if(u==m) tmp=r*r;
            R[u]=r,H[u]=h;
            dfs(u-1,v+r*r*h,s+2*r*h+tmp);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        minv[i]=minv[i-1]+i*i*i;
        mins[i]=mins[i-1]+2*i*i;
    }
    R[m+1]=H[m+1]=inf;
    dfs(m,0,0);
    if(ans==inf) ans=0;
    printf("%d",ans);
    return 0;
}