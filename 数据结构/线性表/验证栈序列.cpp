#include <stack>
#include <iostream>

using namespace std;


int q,n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        vector<int> in(n),out(n);
        for(int i=0;i<n;i++) cin>>in[i];
        for(int i=0;i<n;i++) cin>>out[i];

        stack<int> num;
        int cnt=out.size()-1;
        for(int i=0;i<n;i++){
            num.push(in[i]);
            while(!num.empty()&&num.top()==out[cnt]){
                num.pop();
                cnt--;
            }   
        }
        if(cnt==-1) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}