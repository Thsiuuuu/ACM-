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

struct node{
    int l,r,tm;
};

bool cmp(const node&a,const node&b){
    if(a.r==b.r) return a.l>b.l;
    return a.r<b.r;
}

void sol(){

    int n;
    cin>>n;
    vector<node> seg(n);
    for(int i =0;i<n;i++){
        cin>>seg[i].l>>seg[i].r;
    }

    sort(seg.begin(),seg.end(),cmp);
    
    int  st=0,cnt=0;
    for(int i =0;i<n;i++){
        if(seg[i].l>=st){
        st=seg[i].r;
        cnt++;}
        
    }
    cout<<cnt;

}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}