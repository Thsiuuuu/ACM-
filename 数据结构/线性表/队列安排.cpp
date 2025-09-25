#include <iostream>

using namespace std;


int n,m,k,p;

const int maxn=1e5+10;
int ne[maxn],fr[maxn];


struct node{
    int l,r;
    int d;
}t[maxn]={0};

void add(int i,int k,int p){
    if(p==1){
        t[k].r=t[i].r;
        t[k].l=i;
        t[i].r=k;
        t[t[k].r].l=k;
    }else{
        t[k].r=i;
        t[k].l=t[i].l;
        t[i].l=k;
        t[t[k].l].r=k;
    }
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    t[0].r=0,t[0].l=0;
    add(0,1,1);
    for(int i=2;i<=n;i++){

        cin>>k>>p;

        add(k,i,p);
    }
    cin>>m;
    while(m--){
        int x;
        cin>>x;
        t[x].d=1;
    }
    for(int i=t[0].r;i;i=t[i].r){
        if(!t[i].d){
            cout<<i<<" ";
        }
    }
    return 0;
}