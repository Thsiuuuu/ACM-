#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int t;

struct node{
    vector<int> num;
};

void sol(){
    int n,m;
    cin>>n>>m;
    vector<node> st(n);
    vector<int> cnt(m+1);
    int flag=m;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        for(int j=0;j<l;j++){
            int x;
            cin>>x;
            st[i].num.push_back(x);
            cnt[x]++;
            if(cnt[x]==1){
                flag--;
            }
        }
    }
    if(flag){
        cout<<"no\n";
        return ;//凑不出一组方法
    }else{
        int res=0;
        for(int i=0;i<n&&res<2;i++){
            bool tri=true;
            for(auto x:st[i].num){
                if(cnt[x]==1){
                    tri=false;
                    break;
                }
            }
            if(tri) res++;
        }
        if(res==2){
            cout<<"yes\n";
            return ;
        }
        else cout<<"no\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}