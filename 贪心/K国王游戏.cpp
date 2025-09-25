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

    邻项交换法

    相邻两项交换只会影响这两项之间的最大值，
    尽可能让相邻两个人之间最大值最小，然后让总体最小

*/

const int MAXN=1010;

struct ppl{
    const int BASE=1e4;
    int a[MAXN<<2],len;
    ppl(int len=0){
        this->len=len;
    }
    ppl operator=(int rhs){
        len=0;
        if(rhs==0){
            len=1;
            return *this;
        }
        while(rhs){
            a[++len]=rhs%BASE;
            rhs/=BASE;
        }
        return *this;
    }
    ppl operator=(const ppl rhs){
        memcpy(a,rhs.a,sizeof(rhs.a));
        len=rhs.len;
        return *this;
    }
    void operator*=(const int rhs){
        for(int i=1;i<=len;i++)
            a[i]*=rhs;
        for(int i=1;i<=len;i++){
            a[i+1]+=a[i]/BASE;
            a[i]%=BASE;
            if(i+1>len&&a[i+1])
                len++;
        }
        while(len&&a[len]==0)
            len--;
    }
    ppl operator/(const int rhs){
        ppl c;
        c=*this;
        while(c.len&&c.a[c.len]==0)
            c.len--;
        for(int i=c.len;i;i--){
            c.a[i-1]+=(c.a[i]%rhs)*BASE;
            c.a[i]/=rhs;
        }
        while(c.len&&c.a[c.len]==0)
            c.len--;
        return c;
    }
    void print(){
        while(len&&a[len]==0)
            len--;
        if(len==0){
            putchar('0');
            return;
        }
        printf("%d",a[len]);
        for(int i=len-1;i;i--)
            printf("%04d",a[i]);
    }
    bool operator>(const ppl &rhs)const{
        if(len!=rhs.len)
            return len>rhs.len;
        for(int i=len;i;i--)
            if(a[i]!=rhs.a[i])
                return a[i]>rhs.a[i];
        return 0;
    }
}mul,ans;

struct node{
    int a,b;
    bool operator<(const node &rhs)const{
        return a*b<rhs.a*rhs.b||(a*b==rhs.a*rhs.b&&a<rhs.a);
    }
}p[MAXN];

signed main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%d%d",&p[i].a,&p[i].b);
    sort(p+1,p+n+1);
    mul=p[0].a;
    for(int i=1;i<=n;i++){
        ppl tmp=mul/p[i].b;
        if(tmp>ans)
            ans=tmp;
        mul*=p[i].a;
    }
    ans.print();
    return 0;
}