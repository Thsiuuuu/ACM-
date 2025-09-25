#pragma GCC optimize(2)
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using  namespace std;
/*

    这种可以列出来数量关系的方程，并且他们在mod7意义下是同余的
    但是求出来的是mod7的解，这里观察到题干，发现，day∈[3,9]，所以是可以直接求解的


*/
#define int long long 
const int mod=7;
vector<vector<int> > mat(310,vector<int>(310));
int inv[mod];
map<string,int> days;
int n,m,s;

inline int read(){
    int x=0;
    bool f=false;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-'){
        ch=getchar();
    }
    if(ch=='-'){
        f=true;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return f?-x:x;
}

inline void readstr(char *s){
    int idx=0;
    char ch=getchar();
    while(ch==' '||ch=='\n'||ch=='t'){
        ch=getchar();
    }
    while(ch!=' '&&ch!='\n'&&ch!='\t'){
        s[idx++]=ch;
        ch=getchar();
    }
    s[idx]='\0';
}

void bul(){
    days["MON"]=1;
    days["TUE"]=2;
    days["WED"]=3;
    days["THU"]=4;
    days["FRI"]=5;
    days["SAT"]=6;
    days["SUN"]=7;
    inv[1]=1;
    for(int i=2;i<mod;i++){
        inv[i]=(int)(mod-(int)inv[mod%i]*(mod/i)%mod);
    }
}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void prepare(){
    for(int i=1;i<=s;i++){
        for(int j=1;j<=s+1;j++){
            mat[i][j]=0;
        }
    }
}

void swap(int a,int b){
    vector<int> tmp=mat[a];
    mat[a]=mat[b];
    mat[b]=tmp;
}

int day(string s){
    return days[s];
}

void gauss(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i&&mat[j][j]){
                continue;
            }
            if(mat[j][i]){
                swap(j,i);
                break;
            }
        }
        if(mat[i][i]){
            for(int j=1;j<=n;j++){
                if(i!=j&&mat[j][i]){
                    int g=gcd(mat[i][i],mat[j][i]);
                    int a=mat[i][i]/g;
                    int b=mat[j][i]/g;
                    if(j<i&&mat[j][j]){
                        for(int k=j;k<i;k++){
                            mat[j][k]=(mat[j][k]*a)%mod;
                        }
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
            bool flag=false;
            for(int j=i+1;j<=n;j++){
                if(mat[i][j]){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                mat[i][n+1]=(mat[i][n+1]*inv[mat[i][i]])%mod;
                mat[i][i]=1;
            }
        }
    }
}

signed main(){
    bul();
    while(1){
        n=read();
        m=read();
        if(n==0&&m==0){
            return 0;
        }
        else{
            s=max(n,m);
            prepare();
            for(int i=1;i<=m;i++){
                int k;
                char st[10],ed[10];
                k=read();
                readstr(st);
                readstr(ed);
                for(int j=1;j<=k;j++){
                    int x;
                    x=read();
                    mat[i][x]=(mat[i][x]+1)%mod;
                }
                mat[i][s+1]=((day(string(ed))-day(string(st))+1)%mod+mod)%mod;
            }
            gauss(s);
            int sign=1;
            for(int i=1;i<=s;i++){
                if(mat[i][i]==0&&mat[i][s+1]){
                    sign=-1;
                    break;
                }
                if(i<=n&&mat[i][i]==0){
                    sign=0;
                }
            }
            if(sign==-1){
                printf("Inconsistent data.\n");
            }else if(!sign){
                printf("Multiple solutions.\n");
            }else{
                for(int i=1;i<=n;i++){
                    if(mat[i][s+1]<3){
                        mat[i][s+1]+=7;
                    }
                }
                for(int i=1;i<n;i++){
                    printf("%lld ", mat[i][s+1]);
                }
                printf("%lld\n", mat[n][s+1]);
            }
        }
    }
    return 0;
}
