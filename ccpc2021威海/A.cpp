#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e6+10;
/*


    至多有一个三度的点
*/

bool flag=false;
vector<int> e[N];
int ans=0;
int deg[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    
    for(int i=1;i<=n;i++){
        if(deg[i]>3){
            cout<<0;
            return 0;
        }else if(deg[i]==3){
            ans++;
        }
    }
    cout<<n-ans;
    return 0;
}