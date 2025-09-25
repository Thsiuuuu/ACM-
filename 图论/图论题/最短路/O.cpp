#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using  namespace std;

#define int long  long 

/*

    因为每一次的代价都是1，并且求最短，考虑bfs

    但是直接强行建边很容易超时

    因为两个点如果有边一定是有公因子的，
    如果可以拿公因子建边，时间复杂度会下降
    这里考虑拿质因子作虚点，

*/


const int N=6e5+2;

int n,a,s,t,d[N],x;
vector<int> v[N],g;
queue<int> q;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=2;j*j<=a;j++){
            if(a%j==0){
                v[i].push_back(n+j),v[n+j].push_back(i);
                while(a%j==0) a/=j;
            }
            
        }
        if(a>1) v[i].push_back(n+a),v[n+a].push_back(i);

    }

    cin>>s>>t;
    q.push(s),d[s]=1;
    while(!q.empty()){
        x=q.front(),q.pop();
        for(int k:v[x]){
            if(!d[k]) d[k]=d[x]+1,q.push(k);
        }
    }
    if(!d[t]){
        cout<<"-1";
        return 0;
    }
    g.push_back(t);
    for(int i=t;i!=s;){
        for(int k:v[i]){
            if(d[k]+1==d[i]){
                i=k;
                g.push_back(k);
                break;
            }
        }
    }
    reverse(g.begin(),g.end());
    cout<<(g.size()+1)/2<<"\n";
    for(int k:g){
        if(k<=n){
            cout<<k<<" ";
        }
    }
    return 0;
}