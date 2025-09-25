#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long 

/*

    首先从简单的情况入手，如果任意一个深度只有一个节点，那么一定是唯一的
    如果说存在一个深度，有多个节点，它的下一个节点也有多个节点，则不唯一，因为可以随便放了

    根据这个方法检验就可以

    具体的构造方法找到第一个分裂的点，第一次都放到一个点底下，第二次支出来一个放到另一个底下
*/

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n;
    cin>>n;
    vector<int> depth(n+1);
    bool st=true;
    int ans=0;
    for(int i=0;i<n+1;i++){
        cin>>depth[i];
        if(i>0&&depth[i]>1&&depth[i-1]>1){
            st=false;
            ans=i-1;
        }
    }
    if(st) cout<<"perfect\n";
    else{

        cout<<"ambiguous\n";
        int cnt=0;
        for(int i=0;i<n+1;i++){
            for(int j=1;j<=depth[i];j++){
                cout<<cnt<<" ";
            }
            cnt+=depth[i];
        }
        cout<<"\n";

        cnt=0;
        for(int i=0;i<n+1;i++){
            if(i==ans+1){
                cout<<cnt-1<<" ";
                for(int j=1;j<depth[i];j++){
                    cout<<cnt<<" ";
                }
            }
            else{
                for(int j=1;j<=depth[i];j++){
                    cout<<cnt<<" ";
                }
                
            }
            cnt+=depth[i];
        }
    }   
    return 0;
}