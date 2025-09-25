#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN = 101;
const int MAXM = 10001;

int path[MAXM];
int dist[MAXN][MAXN];
int n, m, v,e,ans,i,j,w;

void build() {
    for (int i = 0; i <v; i++) {
        for (int j = 0; j <v; j++) {
            if(i==j)  dist[i][j]==0;
            else dist[i][j] = INT_MAX;
        }
    }
}

void floyd() {

    for (int bridge = 0; bridge <v; bridge++) { // 跳板
        for (int i = 0; i <v; i++) {
            for (int j = 0;j<v; j++) {

                if (dist[i][bridge] != INT_MAX 
                        && dist[bridge][j] != INT_MAX
                        && dist[i][j] > dist[i][bridge] + dist[bridge][j]) {
                    dist[i][j] = dist[i][bridge] + dist[bridge][j];
                }
            }
        }
    }
}


bool check(){

    for(int i=0;i<v;i++){
        if(dist[i][i]<0){
            cout<<"NEGATIVE CYCLE";
            return false;
        }
    }
    
    return true;
}

int main() {
        
        
        cin>>v>>e;
        build();
        for(int k=0;k<e;k++){
            cin>>i>>j>>w;
            dist[i][j]=w;
        }

        
        floyd();

        if(check()){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    if(dist[i][j]==INT_MAX) cout<<"INF ";
                    else cout<<dist[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        
    return 0;
}