#include <iostream>
#include <algorithm>

using namespace std;


const int maxn=1e5+10;


int father[maxn];
pair<int,int> pii;

int n,m;

void build(){
    for(int i=0;i<n;i++){
        father[i]=i;
    }
}



int find(int i){

    if(father[i]!=i) father[i]=find(father[i]);
    
    return father[i];

}

int main(){

    cin>>n>>m;

    build();

    bool st=true;

    for(int i=0;i<m;i++){

        int x,y;
        cin>>x>>y;

        int l=find(x),r=find(y);
        if(l==r){
            st=false;
        }else{
            father[x]=father[y];
        }

    }

    if(!st) cout<<"IMPOSSIBLE";
    else{

        for(int i=0;i<m;i++)
            if(father[i]==i) cout<<
    }




}