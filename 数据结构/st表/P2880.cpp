#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*

   st表进行区间查询的应用
 
   st表可以理解为把一段需要进行线性查询的请求

   把每一段进行二进制分解的预处理，然后方便查询
   这样就把O(n)的时间复杂度降为O(log2(n))


   构造st表的过程利用了动态规划的思想：
   从2的n-1次方转移到2的n次方

*/

/*
   那么什么时候使用st表呢
   这就引出了st表的适用范围

   如果A区间和B区间可能有重叠的部分
   但是并不影响A+B区间的答案，能通过 A区间答案和B区间答案就加工出来
   那么对应的区间询问，就是一个  可重复贡献  问题
   
    例如：区间最大值，区间最小值，区间公约数等，但是区间求和就不符合这个要求
    再例如：区间按位与、区间按位或，st表都能高效地解决
*/

/*
    st表的优势和劣势
    RMQ问题可以使用st表维护，也可以用线段树等结构维护
    st表的优势：构建过程时间复杂度O(n*logn)，单词查询时间复杂度O(1)，代码量较小
    st表的劣势：需要空间较大，能维护的信息非常有限，不支持修改操作
*/
const int maxn=50001;
const int limit=16;

int arr[maxn];


//log2数组表示：查询<=i的情况下，最大的2的幂，是2的几次方
int log[maxn];
int stmax[maxn][limit],stmin[maxn][limit];

void build(int n){
    log[0]=-1;//对值为1时进行初始化用的

    for(int i=1;i<=n;i++){
        log[i]=log[i>>1]+1;
        stmax[i][0]=arr[i];
        stmin[i][0]=arr[i];
    }

    for(int p=1;p<=log[n];p++){
        for(int i=1;i+(1<<p)-1<=n;i++){
            stmax[i][p]=max(stmax[i][p-1],stmax[i+(1<<(p-1))][p-1]);
            stmin[i][p]=min(stmin[i][p-1],stmin[i+(1<<(p-1))][p-1]);
        }
    }//这里实际是一个动态规划的过程，左右子区间合成新的区间
    //并且通过画图可以知道，这是一个形如上三角形矩阵的东西（）
}

int query(int l,int r){
    int p=log[r-l+1];
    int a=max(stmax[l][p],stmax[r-(1<<p)+1][p]);
    int b=min(stmin[l][p],stmin[r-(1<<p)+1][p]);
    return a-b;
}//这里的选最大值和最小值是分别从左右端点筛选的
//因为有重复并不影响最终的结果



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(n);


    for(int i=1,l,r;i<=m;i++){
        cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }

    return 0;

}