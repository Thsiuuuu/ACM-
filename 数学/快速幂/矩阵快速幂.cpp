#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*

    同样的，矩阵的幂也可以分解成若干二进制下的和，
    类似乘法快速幂，对幂进行二进制分解即可

*/
#define int long long 

const int mod=1e9+7;

vector<vector<int>> multiply(const vector<vector<int>>& a,const vector<vector<int>>& b){
    int n=a.size();
    int m=b[0].size();
    int k=a[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int c=0;c<k;c++){
                ans[i][j]=(ans[i][j]+a[i][c]*b[c][j])%mod;
            }
        }
    }
    return ans;
}

vector<vector<int>> qmi(vector<vector<int>> m,int p){
    int n=m.size();
    vector<vector<int>> ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        ans[i][i]=1;
    }
    for(;p;p>>=1){
        if((p&1)){
            ans=multiply(ans,m);
        }
        m=multiply(m,m);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,p;
    cin>>n>>p;
    vector<vector<int>> num(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>num[i][j];
        }
    }

    num=qmi(num,p);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<num[i][j]%mod<<" ";
        }
        cout<<'\n';
    }
    return 0;
    
}