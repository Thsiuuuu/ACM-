#include <algorithm>
#include <iostream>

using namespace std;


#define int long long 



/*


    树上dp，要注意j一定是逆序枚举，才能保证没有选过这一个子树

*/

int son[105][105],f[105][105];
int n,m,w[105][105],cnt[105],vis[105];


void dfs(int k){
    vis[k]=1;
    for(int i=1;i<=cnt[k];i++){
        int ny=son[k][i];
        if(vis[ny]==1) continue;
        vis[ny]=1;
        dfs(ny);
        for(int j=m;j>=1;j--){
            for(int g=j-1;g>=0;g--){
                f[k][j]=max(f[k][j],f[ny][g]+f[k][j-g-1]+w[k][ny]);
            }
        }
    }
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        w[x][y]=w[y][x]=z;
        son[x][++cnt[x]]=y;
        son[y][++cnt[y]]=x;
    }
    dfs(1);
    cout<<f[1][m];
    return 0;
}
