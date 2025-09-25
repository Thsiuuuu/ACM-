#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/*

    统计最长回文路径

*/


const int N=11000001;
string a;
int p[N<<1];

void sol(){
    while(cin>>a){
        
        int n=a.size()*2+1;
        string s(n,' ');
        for(int i=0,j=0;i<n;i++){
            s[i]=(i&1)==0?'#':a[j++];
        }

        int mx=0;
        for(int i=0,c=0,r=0,len;i<n;i++){

            len=r>i?min(p[2*c-i],r-i):1;
            while(i+len<n&&i-len>=0&&s[i+len]==s[i-len]){
                len++;
            }
            if(i+len>r){
                r=i+len;
                c=i;
            }
            mx=max(mx,len);
            p[i]=len;
        }
        cout<<mx-1<<'\n';
        fill(p,p+N,0);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();
}