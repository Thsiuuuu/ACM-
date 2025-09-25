#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

/*

    如果采取直接搜索的方式，时间复杂度是O(2^40)，
    这里采用折半搜索，将数据分成两部分，每部分的时间复杂度都是O(2^(n/2))
    分组打包好之后，采用双指针算法，进行枚举
*/

const int N=40,M=1<<20;

int arr[N],lsum[M],rsum[M];

int  dfs(int i,int e,int s,int w,int ans[],int j){
    if(s>w){
        return j;
    }
    if(i==e){
        ans[j++]=s;
    }else{
        j=dfs(i+1,e,s,w,ans,j);
        j=dfs(i+1,e,s+arr[i],w,ans,j);
    }
    return j;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,w;
    cin>>n>>w;

    for(int  i=0;i<n;i++){
        cin>>arr[i];
    }

    int  ln=dfs(0,n>>1,0,w,lsum,0);
    int rn=dfs(n>>1,n,0,w,rsum,0);
    sort(lsum,lsum+ln);
    sort(rsum,rsum+rn);

    int ans=0;
    for(int i=rn-1,j=0;i>=0;i--){
        while(j<ln&&lsum[j]+rsum[i]<=w){
            j++;
        }
        ans+=j;
    }
    cout<<ans<<"\n";
    return 0;

}