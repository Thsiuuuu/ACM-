#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 


const int N=10001;
const int base=499;
int nums[N];
int n;

int v(char c){
    if(c>='0'&&c<='9'){
        return c-'0'+1;
    }else if(c>='A'&&c<='Z'){
        return c-'A'+11;
    }else{
        return c-'a'+37;
    }
}

int  value(string s){
    int ans=v(s[0]);
    for(int i=1;i<s.size();i++){
        ans=ans*base+v(s[i]);
    }
    return ans;
}

int cnt(){
    sort(nums,nums+n);
    int ans=1;
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            ans++;
        }
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i =0;i<n;i++){
        string s;
        cin>>s;

        nums[i]=value(s);
    }
    cout<<cnt();
}