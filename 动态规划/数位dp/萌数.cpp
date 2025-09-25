#include <iostream>
#include <string>

using namespace std;

#define int long long 

const int mod=1000000007;
const int maxn=1001;


int dp[maxn][11][11][2];

void build(int n){
    for(int a=0;a<n;a++){
        for(int b=0;b<=10;b++){
            for(int c=0;c<=10;c++){
                for(int d=0;d<=1;d++){
                    dp[a][b][c][d]=-1;
                }
            }
        }
    }
}


int f(string num,int i,int pp,int p,int free){
    if(i==(int)num.size()) return 1;
    if(dp[i][pp][p][free]!=-1) return dp[i][pp][p][free];
    int ans=0;
    if(free==0){
        if(p==10){
            ans=(ans+f(num,i+1,10,10,1))%mod;
            for(int cur=1;cur<num[i]-'0';cur++){
                ans=(ans+f(num,i+1,p,cur,1))%mod;
            }
            ans=(ans+f(num,i+1,p,num[i]-'0',0))%mod;
        }else{
            for(int cur=0;cur<num[i]-'0';cur++){
                if(pp!=cur&&p!=cur)
                    ans=(ans+f(num,i+1,p,cur,1))%mod;
            }
            if(pp!=num[i]-'0'&&p!=num[i]-'0'){
                ans=(ans+f(num,i+1,p,num[i]-'0',0))%mod;
            }

        }
    }else{
        if(p==10){
            ans=(ans+f(num,i+1,10,10,1))%mod;
            for(int cur=1;cur<=9;cur++){
                ans=(ans+f(num,i+1,p,cur,1))%mod;
            }
        }else{
            for(int cur=0;cur<=9;cur++){
                if(pp!=cur&&p!=cur){
                    ans=(ans+f(num,i+1,p,cur,1))%mod;
                }
            }
        }
    }

    dp[i][pp][p][free]=ans;
    return ans;
}

bool check(string num){
    for(int pp=-2,p=-1,i=0;i<num.size();pp++,p++,i++){
        if(pp>=0&&num[pp]==num[i]) return true;
        if(p>=0&&num[p]==num[i]) return true;
        
    }
    return false;
}


int cnt(string num){
    if(num[0]=='0') return 0;
    int n=num.size();
    int all=0;
    int base=1;
    for(int i=n-1;i>=0;i--){
        all=(all+base*(num[i]-'0'))%mod;
        base=(base*10)%mod;
    }
    build(n);
    return (all-f(num,0,10,10,0)+mod)%mod;
}


int query(string l,string r){
    int ans=(cnt(r)-cnt(l)+mod)%mod;
    if(check(l)){
        ans=(ans+1)%mod;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string a,b;
    cin>>a>>b;
    cout<<query(a,b);
    return 0;
}