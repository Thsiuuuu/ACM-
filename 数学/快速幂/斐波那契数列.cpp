#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*

    同样的，矩阵的幂也可以分解成若干二进制下的和，
    类似乘法快速幂，对幂进行二进制分解即可

    因为这个斐波那契数列数据范围很大，直接套用矩阵快速幂求即可
    每次的矩阵是斐波那契矩阵

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
    vector<vector<int>> ans={
        {1,1},
        {1,0}
    };
    for(;p;p>>=1){
        if((p&1)){
            m=multiply(m,ans);
        }
        ans=multiply(ans,ans);
    }
    return m;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    if(n<=2){
        cout<<1;
        return 0;
    }
    if(n==3){
        cout<<2;
        return 0;
    }

    vector<vector<int>> ans={{2,1}};
    
    cout<<qmi(ans,n-3)[0][0];
    

    
    return 0;
    
}