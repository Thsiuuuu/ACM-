#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int N=1e6+10;

int fail[N];
string s;
int q;
int m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>s>>q;

    m=s.size();
    int p=0;
    for(int i=1;i<m;i++){
        while(s[p+1]!=s[i+1]&&p) p=fail[p];
        if(s[p+1]==s[i+1]) p++;
        fail[i+1]=p;
    }
    sort(fail+1,fail+m);
    while(q--){
        int idx;
        cin>>idx;
        int l=1,r=m;
        int ans;
        while(l<r){
            int mid=(l+r)>>1;
            if(fail[mid]<=idx){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<ans;
    }
    return 0;
}