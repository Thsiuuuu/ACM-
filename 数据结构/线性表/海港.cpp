#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

#define int long long 

const int maxn=1e5+10;
struct travel{
    int t,x;
}ply;
int n,f[maxn],ans;
queue<travel> ppl;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        int t,k;
        cin>>t>>k;
        for(int j=0;j<k;j++){
            int x;
            cin>>x;
            ppl.push({t,x});
            if(f[x]==0){
                ans++;
            }
            f[x]++;
        }
        while(!ppl.empty()&&ppl.front().t+86400<=t){
            if(f[ppl.front().x]==1){
                ans--;
            }
            f[ppl.front().x]--;
            ppl.pop();
        }
        cout<<ans<<"\n";
    }
    return 0;

}