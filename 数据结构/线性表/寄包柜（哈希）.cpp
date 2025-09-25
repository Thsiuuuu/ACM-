#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

/*
    因为数据过于稀疏，连续开辟内存会浪费很多内存
    所以考虑建立映射
    那么怎么映射呢
    这里采用二维映射
    第一维映射快递柜
    第二维映射格子
*/

map<int,map<int,int>> box;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    while(q--){
        int op,i,j,k;
        cin>>op>>i>>j;
        if(op==1){

            cin>>k;
            box[i][j]=k;
        }else{
            cout<<box[i][j]<<"\n";
        }
    }
    return 0;

}