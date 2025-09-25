#include <iostream>
#include <algorithm>
using namespace std;

/*

	莫队
	可以不遍历的，因为一种颜色当且仅当到达2的倍数的时候，对答案的贡献才会+1 
	应该静下心想一想，一个颜色什么时候会让总答案+1 
	这个题如果不采取上面的方法会超时，还有比赛时候一直re是因为add和sub写成void类型了 
*/
#define int long long 
const int N=2e6+10;
int n,q,num[N],vis[N],ans[N],sorted[N];
int block,blo[N];
int l=1,r=0;
int s=1;
int cnt=0; 

struct node{
	int l,r;
	int id;
	bool operator<(const node&a)const{
		return (l/block)!=(a.l/block)?l<a.l:((l/block)%2?r>a.r:r<a.r);
	}
}p[N];

void add(int x){
	vis[num[x]]++;
	if(vis[num[x]]%2==0){
		cnt++;
	}
}

void sub(int x){
	vis[num[x]]--;
	if(vis[num[x]]&1){
		cnt--;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	
	cin>>q;
	
	block=sqrt(n);

	
	for(int i=1;i<=q;i++){
		cin>>p[i].l>>p[i].r;
		p[i].id=i;
	}
	
	sort(p+1,p+1+q);
	
	for(int i=1;i<=q;i++){
		while(l<p[i].l) sub(l++);
		while(l>p[i].l) add(--l);
		while(r<p[i].r) add(++r);
		while(r>p[i].r) sub(r--);
		ans[p[i].id]=cnt;
	}
	
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
	
}
 

