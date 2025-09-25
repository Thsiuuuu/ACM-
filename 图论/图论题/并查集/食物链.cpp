#include <iostream>
#include <algorithm>

using namespace std;

const int N=5e5+10;
int father[N],k;
int op,x,y,n;


/*

    开两个并查集，
    一个表示同类的并查集，另外一个表示吃和被吃关系的并查集

    扩展域并查集
    开3n的大小,1~n表示同类并查集,n+1~2*n表示能吃的并查集，2*n+1~3*n表示吃自己的并查集


*/

int find(int i){
    return father[i]==i?i:father[i]=find(father[i]);
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    father[fy]=fx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=3*n;i++){
        father[i]=i;
    }

    int sum=0;
    for(int i=0;i<k;i++){
        cin>>op>>x>>y;
        if(x>n||y>n){
            sum++;
            continue;
        }//x或y比n大，假话
        if(op==1){
            
            if(find(x)==find(y+n)||find(x)==find(y+2*n)){
                sum++;
                continue;
            }

            unite(x,y);
            unite(x+n,y+n);
            unite(x+2*n,y+2*n);
        }else{

            if(x==y||(find(x)==find(y))||find(x)==find(y+n)){
                sum++;
                continue;
            }
            unite(y+2*n,x);
            unite(x+n,y);
            unite(x+2*n,y+n);
        }
    }
    cout<<sum;
    return 0;

}
