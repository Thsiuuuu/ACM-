#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


#define int long long 


const int N=1e5+10;

int n;
int cnt=1;
int dp[N];
vector<int> a[N];
/*

邻接表存图

每个点的高度等于度数+最大子树高度

*/

void dfs(int i){
	for(int j=0;j<a[i].size();j++){
		// if(a[i][j]!=fa){
			//cout<<"1\n";
			dfs(a[i][j]);
			// cout<<a[i][j]<<" "<<dp[a[i][j]]<<"\n";
			dp[i]=max(dp[i],dp[a[i][j]]+(int)(a[i].size()));
		// }
	}
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(int i=2;i<=n;i++){
		int  x;
		cin>>x;
		a[x].push_back(i);
	}
	dfs(1);
	cout<<dp[1];
	return 0;
	
}