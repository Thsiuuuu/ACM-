#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define int long long 

const int maxn=5e5+10;


/*

	这个题如果直接采取从左向右弹的方法，不知道当前的是不是最大值
	但是可以转化一下，最大值等于当前前缀和减去范围内前缀和最小值
	因此可以维护一个单调递增的栈

*/


int sum[maxn],arr[maxn],q[maxn];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i]=sum[i-1]+arr[i];
			
	}
	
	//cout<<"1\n";
	//for(int i=1;i<n;i++) cout<<sum[i]-sum[i-1]<<" ";
	
	// for(int i=1;i<=m;i++){
	// 	while(!num.empty()&&num.front()<=0){
	// 		num.pop();
	// 	}
	// 	ans=max(ans,sum[i]);
	// 	num.push(i);
	// }
	
	// //cout<<"1\n";
	
	// for(int i=m;i<n;i++){
	// 	while(!num.empty()){
	// 		if(arr[num.front()]<=0||num.size()>=m){
	// 		ans=max(ans,sum[i-1]-sum[num.front()-1]);
	// 		//cout<<i<<" "<<num.front()<<"\n";
	// 		num.pop();
	// 		}else break;
	// 	}
		
	// 	if(!num.empty()){
	// 		ans=max(ans,sum[i-1]-sum[num.front()-1]);
	// 		ans=max(ans,sum[i]-sum[num.front()-1]);
	// 	}
		
	// 	num.push(i);
	// }

	int ans=-1145141919;
	int l=1,r=1;
	q[1]=0;
	for(int i=1;i<=n;i++){
		while(l<=r&&q[l]<i-m) l++;
		ans=max(ans,sum[i]-sum[q[l]]);
		while(l<=r&&sum[q[r]]>=sum[i]) r--;
		q[++r]=i;
	}
	
	cout<<ans;
	return 0;
	
	
	
	
	
}

