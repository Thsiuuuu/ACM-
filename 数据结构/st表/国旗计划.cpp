#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


/*

    st表的一个经典例题
    首先暴力解法，暴力枚举即可，时间复杂度为O(n*n)
    
    这里可以对筛选，也就是第二层n进行简化
    因为暴力解法我们采用的是线性枚举的方法，时间复杂度为O(n)
    然后我们知道一个数可以被若干个2的i次方累加得出
    所以我们通过这个思路，把这个数分解，并进行筛选
    通过枚举二进制位，来表示答案
    这里时间复杂度可以被降至log2(n)的时间复杂度
    总时间复杂度就变为了O(n*log2(n))


    然后是这个题设计到的小技巧：拆环成链


 */


struct Line{
    int id;
    int s;
    int e;
};


const int maxn=2e6+10;
const int limit=18;
int stjump[maxn<<1][limit],ans[maxn];
Line line[maxn<<1];

int n,m,power;


bool cmp(const Line&a,const Line& b){
    return a.s<b.s;
}


int log2(int n){
    int ans=0;
    while((1<<ans)<=(n>>1)){
        ans++;
    }

    return ans;

}


void build(){
    for(int i=1;i<=n;i++){
        if(line[i].s>line[i].e){
            line[i].e+=m;
        }
    }


    sort(line+1,line+n+1,cmp);


    for(int i=1;i<=n;i++){
        line[i+n].id=line[i].id;
        line[i+n].s=line[i].s+m;
        line[i+n].e=line[i].e+m;
    }

    int e=n*2;
    for(int i=1,arrive=1;i<=e;i++){
        while(arrive+1<=e&&line[arrive+1].s<=line[i].e){
            arrive++;
        }
        stjump[i][0]=arrive;
    }

    for(int p=1;p<=power;p++){
        for(int i=1;i<=e;i++){
            stjump[i][p]=stjump[stjump[i][p-1]][p-1];
        }
    }

}


int jump(int i){
    int aim=line[i].s+m,cur=i,next,ans=0;
    for(int p=power;p>=0;p--){
        next=stjump[cur][p];
        if(next!=0&&line[next].e<aim){
            ans+=1<<p;
            cur=next;
        }
    }

    return ans+1+1;
}

void compute(){
    power=log2(n);
    build();
    for(int i=1;i<=n;i++){
        ans[line[i].id]=jump(i);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        line[i].id=i;
        cin>>line[i].s>>line[i].e;
    }


    compute();
    cout<<ans[1];
    for(int i=2;i<=n;i++){
        cout<<" "<<ans[i];
    }

    cout<<"\n";
    return 0;
}