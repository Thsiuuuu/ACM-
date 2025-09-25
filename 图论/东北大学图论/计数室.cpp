#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int number=1005;

int cols,sets;
int n,m;

int father[number*number];
char house[number][number];

int index(int r,int c){
    return r*m+c;
}


void build(){
    sets=0;
    for(int a=0;a<n;a++){
        for(int b=0,idx;b<m;b++){
            if(house[a][b]=='.'){
                idx=index(a,b);
                father[idx]=idx;
                sets++;
            }
        }
    }
}

int find(int i){
    if(i!=father[i]) father[i]=find(father[i]);
    return father[i];
}


void unin(int a,int b,int c,int d){
    int fx=find(index(a,b));
    int fy=find(index(c,d));
    if(fx!=fy){
        father[fx]=fy;
        sets--;
    }
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>house[i][j];
        


    build();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(house[i][j]=='.'){
                if(j>0&&house[i][j-1]=='.')
                    unin(i,j,i,j-1);
                if(i>0&&house[i-1][j]=='.')
                    unin(i,j,i-1,j);
            }
        }
    }

    cout<<sets;
    return 0;
}