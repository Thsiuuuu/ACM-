#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int T;
int a,b,m;

int Times,Remain;

signed main()
{
	cin>>T;
	while(T--)
	{
		Times=0;
		cin>>a>>b>>m;
		if(b<a)
		{
			Times=m/b;
			Times+=2;
			Remain=m%b;
			if(Remain+b>=a)
			{
				Times++;
			}
			cout<<Times*160<<'\n';
		}else if(a==b)
		{
			Times=m/b;
			Times+=2;
			Times*=2;
			cout<<Times*160<<'\n';
		}else
		{
			if(b%a==0)
			{
				Times=m/b;
				int Real = 2+Times+m/a;
				cout<<Real*160<<'\n';
			}else
			{
				Times = m/((b/a+1)*a);
				int Real = 2+m/a+Times;
				cout<<Real*160<<'\n';
			}
		}
	}
	
}