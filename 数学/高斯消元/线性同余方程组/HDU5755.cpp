#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define int long long 
const int mod=3,N=1010;
/*


    这个是可以通过列方程解出来的
    设分别对x1,x2...xn的格子操作了若干次
    那么可以列出方程，每一个格子对自己格子的贡献是2，对别的格子的贡献是1
    然后贡献是在mod3意义下满足和原来的各自能够凑成3的
    然后再分析一下，一个格子对自己操作l次和操作l%3次的效果是一样的

*/

vector<vector<int>> mat(N,vector<int>(N));
int dir[5]={0,-1,0,1,0};
int n,m,s,t;
int inv[mod];
void bul(){
    inv[1]=1;
    for(int i=2;i<mod;i++){
        inv[i]=(int)(mod-(int)inv[mod%i]*(mod/i)%mod);
    }
}

void swap(int a,int b){
    vector<int> tmp=mat[a];
    mat[a]=mat[b];
    mat[b]=tmp;
}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void build(){
    for(int i=1;i<=s;i++)
        for(int j=1;j<=s+1;j++)
            mat[i][j]=0;
    
    int cur,row,col;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cur=i*m+j+1;
            mat[cur][cur]=2;
            for(int d=0;d<=3;d++){
                row=i+dir[d];
                col=j+dir[d+1];
                if(row>=0&&row<n&&col>=0&&col<m){
                    mat[cur][row*m+col+1]=1;
                }
            }
        }
    }
}

void gauss(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i&&mat[j][j]){
                continue;
            }
            if(mat[j][i]){
                swap(i,j);
                break;
            }
        }
        if(mat[i][i]){
            for(int j=1;j<=n;j++){
                if(i!=j&&mat[j][i]){
                    int g=gcd(mat[j][i],mat[i][i]);
                    int a=mat[i][i]/g;
                    int b=mat[j][i]/g;
                    if(j<i&&mat[j][j]){
                        mat[j][j]=(mat[j][j]*a)%mod;
                    }
                    for(int k=i;k<=n+1;k++){
                        mat[j][k]=((mat[j][k]*a-mat[i][k]*b)%mod+mod)%mod;
                    }
                }
            }
        }
        
    }
    for(int i=1;i<=n;i++){
        if(mat[i][i]){
            mat[i][n+1]=(mat[i][n+1]*inv[mat[i][i]])%mod;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    bul();
    cin>>t;
    while(t--){
        cin>>n>>m;
        s=n*m;
        build();
        for(int i=1;i<=s;i++){
            int x;
            cin>>x;
            mat[i][s+1]=(3-x)%mod;
        }
        gauss(s);
        int ans=0;
        for(int i=1;i<=s;i++) ans+=mat[i][s+1];
        cout<<ans<<'\n';
        for(int i=1,id=1;i<=n;i++){
            for(int j=1;j<=m;j++,id++){
                while(mat[id][s+1]-->0){
                    cout<<i<<" "<<j<<'\n';
                }
            }
        }//把二维网格的每一个各自从左到右从上到下进行标号，然后每一个格子只要参与了贡献，就输出一次
    }
    return 0;
}