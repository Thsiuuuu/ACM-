#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N=10010;
int n,m,res=0;
int f[N];
vector<int> a;
int sg(int u){
    if(f[u]^-1) return f[u];
    
    set<int> S;
    for(int i=0;i<m&&a[i]<=u;i++){//这里判断条件最开始写反了，写反了有可能先判断a[i]<=u造成了数组越界，判断条件一定先要保证不越界
        S.insert(sg(u-a[i]));
    }
    for(int i=0;;i++){
        if(!S.count(i)) return f[u]=i;
    }
}

int main(){

    scanf("%d",&m);
    a.resize(m);
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    scanf("%d",&n);
    vector<int> b(n);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);

    sort(a.begin(),a.end());
    memset(f,-1,sizeof(f));
    for(int i=0;i<n;i++){
        res^=sg(b[i]);
    }
    if(res){
        printf("Yes");
    }else printf("No");
    return 0;
}
