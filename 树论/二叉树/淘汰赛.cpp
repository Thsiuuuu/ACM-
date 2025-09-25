#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


/*

    跑bfs，然后队列只有两个元素即可
    因为是一层一层递归的，而且每一层除了顶点都是偶数
    所以每次取两个再把数值大的放进队列即可

*/
struct node{
    int id;
    int str;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,num;
    queue<node> que;
    cin>>n;
    num=1<<n;
    for(int i=1;i<=num;i++){
        int x;
        cin>>x;
        que.push({i,x});
    }

    int siz;
    while(que.size()>2){
        siz=que.size();

        for(int i=0;i<siz/2;i++){
            node l1=que.front();
            que.pop();
            node l2=que.front();
            que.pop();
            if(l1.str<l2.str){
                swap(l1,l2);
            }
            que.push(l1);
        }
    }
    node l1=que.front();
    que.pop();
    node l2=que.front();
    if(l1.str>l2.str) swap(l1,l2);
    cout<<l1.id;
    return 0;

}