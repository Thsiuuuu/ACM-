#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long 

/*

    感觉和石子合并弱化版思路差不多，只不过多了一个最大值

    qwq好吧，没有注意到这个是环，所以要拆环成链
*/

const int N=210;
int dp1[N][N],dp2[N][N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> arr(2*n+1),sum(2*n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum[i]=(sum[i-1]+arr[i]);
    }
    for(int i=n+1;i<=2*n;i++){
        arr[i]=arr[i-n];
        sum[i]=(sum[i-1]+arr[i]);
    }

    memset(dp1,0,sizeof(dp1));
    memset(dp2,0x3f3f3f,sizeof(dp2));
    for(int i=1;i<=2*n;i++){
        dp1[i][i]=0;
        dp2[i][i]=0;
    }
    
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){
            for(int k=l;k<l+len-1;k++){
                int r=l+len-1;
                dp1[l][r]=max(dp1[l][k]+dp1[k+1][r]+sum[r]-sum[l-1],dp1[l][r]);
                dp2[l][r]=min(dp2[l][k]+dp2[k+1][r]+sum[r]-sum[l-1],dp2[l][r]);
            }
        }
    }

    int ans1=0,ans2=1145141919;
    for(int l=1;l+n-1<=2*n;l++){
        ans1=max(ans1,dp1[l][l+n-1]);
        ans2=min(ans2,dp2[l][l+n-1]);
    }

    cout<<ans2<<"\n"<<ans1;
    return 0;

}