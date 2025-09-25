#include <vector>
#include <algorithm>
#include <string>

using namespace std;


const int maxn=500001;
const int limit=20;

int power,cnt;

int head[maxn],next[maxn<<1],to[maxn<<1],deep[maxn].stjump[maxn][limit];


int log(int n){
    int ans=0;
    while((1<<ans)<=(n>>1)){
        ans++;
    }
    return ans;
}

void build(int n){
    power=log(n);
    cnt=1;
    fill(head+1,head+n+1,0);
}


void addEdge(int u,int v){
    next[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}


