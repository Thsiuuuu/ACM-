#include <iostream>
#include <algorithm>
using namespace std;
/*


    分块，以3的幂次分块

    时间复杂度O(t*log3(n))
*/

int t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        
        int ans=0;
        int i=0,mi=1;
        while(mi<=l){
            mi*=3;
            i++;
        }
        ans+=(i*2);//这部分没问题

        while(mi-1<r){
            ans+=((mi-max(l+1,mi/3))*i);
            mi*=3;
            i++;
        }
        ans+=((r-max(l+1,mi/3)+1)*i);
        cout<<ans<<'\n';
    }
}