#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N=21;
int prime[N<<1];
bool vis[N];
int n;

vector<int> ans;
/*


    以EOF为结束的时候，只需要while(cin>>n)就可以
    然后注意多组样例要清空之前的东西


*/

void build(){
    
    prime[1]=prime[2]=prime[3]=prime[5]=0;

    prime[4]=1;
    for(int i=6;i<=N*2;i++){
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                prime[i]=1;//打标记的时候出错了
                break;
            }
        }
    }
}

void dfs(int k,int num){

    if(num==n&&(!prime[k+1])){
        // cout<<"1\n";
        for(int i=0;i<num-1;i++){
            cout<<ans[i]<<" ";
        }
        cout<<ans[num-1];
        cout<<'\n';
        return ;
    }

    // cout<<"1\n";
    for(int i=((k&1)?2:1);i<=n;i+=2){

        // cout<<i<<'\n';

        if(vis[i]||(prime[i+k])){
            continue;
        }

        vis[i]=true;
        ans.push_back(i);

        // cout<<i<<'\n';
        
        dfs(i,num+1);

        vis[i]=false;
        ans.pop_back();

    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    build();
    int cnt=0;
    while(cin>>n){

        if(cnt) cout<<'\n';

        int num=1;
        cout<<"Case "<<(++cnt)<<":\n";

        vis[1]=true;
        ans.push_back(1);

        dfs(1,1);

        

        ans.pop_back();
 
    }
    // for(int i=1;i<=41;i++){
    //     cout<<i<<" "<<prime[i]<<"\n";
    // }
    return 0;
}