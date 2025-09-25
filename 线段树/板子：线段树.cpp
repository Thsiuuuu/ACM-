#include <iostream>
#include <algorithm>


int a[N];

struct SegmentTree{
    int f[N*4],tag[N*4];
    void build(int u ,int l,int r){
        if(l==r){f[u]=a[l];return ;}
        int mid=(l+r)/2;
        build(u*2,l,mid);
        build(u*2+1,mid+1,r);
    }//初始化

    void pushDown(int u,int l,int r){
        f[u*2]=x*(mid-l+1);tag[u*2]+=x;
        f[u*2+1]=x*(r-mid);tag[u*2+1]+=x;

        tag[u]=0;

    }


    void pushUp(int u){f[u]=f[u*2]+f[u*2+1];}//维护区间信息
    void modify(int u ,int l,int r,int p,int x){
        if(l==r){f[u]=x;}
        int mid=(l+r)/2;
        if(p<=mid){
            modify(u*2,l,mid,p,x);
        }else{
            modify(u*2+1,mid+1,r,p,x);
        }
        pushUp(u);
    }//修改

    void query(int u,int l,int r,int pl,int pr,int &x){
        if(l==pr&&r==pr){x+=f[u];return;}
        int mid=(l+r)>>1;
        if(pr<=mid){query(u*2,l,mid,pl,pr,x);}
        else if(pl>mid){query(u*2,mid+1,r,pl,pr,x);}
        else{
            query(u*2,l,mid,pl,mid,x);
            query(u*2,mid+1,r,mid+1,pr,x);
        }
        pushUp(x);
    }
}

