#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N=20000001;
int z[N],e[N];

void zArray(string s,int n){
    z[0]=n;
    for(int i=1,c=1,r=1,len;i<n;i++){
        len=r>i?min(r-i,z[i-c]):0;
        while(i+len<n&&s[i+len]==s[len]){
            len++;
        }
        if(i+len>r){
            r=i+len;
            c=i;
        }
        z[i]=len;
    }
}

void eArray(string a,string b,int n,int m){
    for(int i=0,c=0,r=0,len;i<n;i++){
        len=r>i?min(r-i,z[i-c]):0;
        while(i+len<n&&len<m&&a[i+len]==b[len]){
            len++;
        }
        if(i+len>r){
            r=i+len;
            c=i;
        }
        e[i]=len;
    }
}

long  long eor(int arr[] ,int n){
    long long ans=0;
    for(int i=0;i<n;i++){
        ans^=(long long )(i+1)*(arr[i]+1);
    }
    return ans;
}

void sol(){
    string a,b;
    cin>>a>>b;;
    zArray(b,b.size());
    eArray(a,b,a.size(),b.size());
    cout<<eor(z,b.size())<<'\n';
    cout<<eor(e,a.size());
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();
    return 0;

}