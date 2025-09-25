#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long //不开long long 
int n;
int cnt=1;
int sum[4];//有一个bug，这里只需要统计排序下前三个的，其他的不需要，到三不退出会数组越界
int ans;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector<int> cpy=num;
    sort(cpy.begin(),cpy.end());
    // for(int x:cpy){
    //     cout<<x<<" ";
    // }
    sum[1]=1;
    for(int i=1;i<n;i++){
        
        if(cpy[i]!=cpy[i-1]){
            cnt++;
        }
        if(cnt==4){
            break;
        }
        sum[cnt]++;
    }

    if(cpy[0]==cpy[1]&&cpy[1]==cpy[2]){
        ans=(sum[1]*(--sum[1])*(--sum[1])/6);
    }else{
        if(cpy[2]==cpy[1]&&cpy[1]!=cpy[0]){
            ans=sum[1]*sum[2]*(--sum[2])/2;
        }else if(cpy[0]==cpy[1]&&cpy[2]!=cpy[1]){
            ans=(sum[1]*(--sum[1])*sum[2])/2;
        }else{
            ans=sum[1]*sum[2]*sum[3];
        }
    }
    cout<<ans;
    return 0;
}