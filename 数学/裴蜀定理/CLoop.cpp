#include <iostream>
#include <algorithm>

/*

    比赛的时候没做出来，
    这里是因为取模没弄明白
    因为任意的解都符合
    x=x0+(b/d)*n的形式，也就是说
    要得到最小的正整数解，可以先%一下b/d，然后+(b/d)再摸一下就可以得到了
*/

using namespace std;


#define int long  long  



int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
	int g=gcd(a,b);	
	return a*b/g;
}

int qmi(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=(ans*a);
		}
		a=(a*a);
		b>>=1;
	}
	return ans;
}

int exgcd(int a,int b,int &x,int &y){
	if(!b){
		return x=1,y=0,a;
	}
	int r=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return r;
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int a,b,c,k;
	while(cin>>a>>b>>c>>k){
		if((!a)&&(!b)&&(!c)&&(!k)){
			return 0;
		}
		
		if(b==a){
			cout<<"0\n";
			continue;
		}
	
		int mod=qmi(2,k);
		int x,y;
		
		int g=exgcd(c,mod,x,y);
		int sum;
		if(b<a){
			 sum=mod-(a-b);
		}else{
			sum=b-a;
		} 
//		cout<<g<<"\n";
//		cout<<x<<"\n";
		
		if(sum%g!=0){
			cout<<"FOREVER\n";
			continue;
		}
		
		int d=sum/g;
		cout<<(x*d%(mod/g)+mod/g)%(mod/g)<<'\n';	
	}
	
	return 0;
}