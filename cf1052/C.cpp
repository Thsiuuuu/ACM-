#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

int t;

/*

    这个题就是要为1的都能找到，为0的没法总是找到
    那么什么时候是稳定的呢，那一定是左边元素都比它小，右边元素都比它大
    这个之后只需要保证每一个为1的数的左边都小，右边都大就可
    但是注意，如果1之间只差了一个0的话，那么一定不行，因为这样相邻的1区间
    一定是单调增的，这个时候这个为0位置的数也是不合题意的

    所以说这个只需要为1的区间都升序，为0的区间都降序就可以
    这个差一点就做出来了，主要是代码实现能力太差了


*/

//写法1
void sol1(){
    int n;
    string s;
    cin>>n>>s;
    
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ans.push_back(i+1);
        }else{
            int j=i;
            while(j+1<n&&s[j+1]=='0'){
                j++;
            }
            if(j==i){
                cout<<"no\n";
                return ;
            }
            for(int k=j;k>=i;k--){
                ans.push_back(k+1);
            }
            i=j;
        }
    }
    cout<<"yes\n";
        for(int x:ans){
            cout<<x<<" ";
        }
    cout<<"\n";

}

//写法2,开双指针
void sol2(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> ans(n);
    iota(ans.begin(),ans.end(),1);//构造从1开始的递增序列
    for(int l=0,r=l;l<n;l=r){
        while(r<n&&s[r]==s[l]){
            r++;
        }
        if(s[l]=='0'){
            if(r==l+1){
                cout<<"no\n";
                return ;
            }else{
                reverse(ans.begin()+l,ans.begin()+r);
            }
        }
    }
    cout<<"yes\n";
    for(int x:ans) cout<<x<<" ";
    cout<<'\n';
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        sol2();
    }
    return 0;
}