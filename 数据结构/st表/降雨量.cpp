#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


const int maxn=50004;
const int limit=16;



int  year[maxn],num[maxn];
/*

    这里考虑离散化的方式，如果根据以年份作为下标进行离散化的话
    那如果这个年份是空的话，我们很难处理

    但是如果以年份的编号作为下标的话，那我们很容易就找到这个区间之内的编号
    可以采用二分查找的方式进行查找


*/


int lg[maxn];
int stmax[maxn][limit];

void build(int n){
    lg[0]=-1;

    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
        stmax[i][0]=num[i];
    }

    for(int p=1;p<=lg[n];p++){
        for(int i=1;i+(1<<p)-1<=n;i++){
            stmax[i][p]=max(stmax[i][p-1],stmax[i+(1<<(p-1))][p-1]);
        }
    }
}

int query(int l,int r){
    int p=lg[r-l+1];
    int a=max(stmax[l][p],stmax[r-(1<<p)+1][p]);
    return a;
}



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>year[i]>>num[i];
    }

    build(n);

    //cout<<"1\n";

    int q;
    cin>>q;

    while(q--){
        int x,y;
        cin>>y>>x;
        int st=lower_bound(year+1,year+1+n,y)-year,
        ed=lower_bound(year+1,year+1+n,x)-year;

        if(year[ed]!=x&&year[st]!=y){
            cout<<"maybe\n";
        }else if(year[ed]==x&&year[st]!=y){
            if(ed==st){
                cout<<"maybe\n";
            }else{
                if(query(st,ed-1)>=num[ed]){
                    cout<<"false\n";
                }else{
                    cout<<"maybe\n";
                }
            }

        }else if(year[ed]!=x&&year[st]==y){
            if(ed-1==st){
                cout<<"maybe\n";
            }else{
                if(query(st+1,ed-1)>=num[st]){
                    cout<<"false\n";
                }else{
                    cout<<"maybe\n";
                }
            }
        }else{
            if(num[ed]>num[st]){


                //cout<<"test3\n";

                cout<<"false\n";
            }else{
                if(st+1<=ed-1){
                    if(query(st+1,ed-1)>=num[ed]){
                        
                        //cout<<"test4\n";

                        cout<<"false\n";
                    }else if(ed-st==year[ed]-year[st]){
                        cout<<"true\n";
                    }else cout<<"maybe\n";
                }else{
                    if(ed-st==year[ed]-year[st]){
                        cout<<"true\n";
                    }else cout<<"maybe\n";
                }
            }
        }
    }

    return 0;

}