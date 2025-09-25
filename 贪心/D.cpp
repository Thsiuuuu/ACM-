#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>


using namespace std;

#define int long long 



/*

    如果一头奶牛，任何一条路都上不去，那么结束\
    

    n是牛的数量
    m是路的数量
    d是前后限制
    l是最小限制

*/

void sol(){

    int n,m,d,l;
    cin>>n>>m>>d>>l;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    sort(num.begin(),num.end());
    
    vector<int> path(m,0);
    int pt=0,ans=0;
    for(int i=0;i<n;i++){

        int len=path[pt];
        int res=max(num[i]-d*len,(int)0);
        if(res>=l){
            path[pt++]++;
            ans++;
            pt%=m;
        }

    }

    cout<<ans;
    return ;
    
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}