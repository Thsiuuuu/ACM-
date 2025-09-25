#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int  h,w;
    cin>>h>>w;
    vector<vector<char>> mp(h+1,vector<char>(w+1));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(mp[i][j]=='.'){
                int ans=0;
                for(int k=i-1;k<=i+1;k++){
                    for(int l=j-1;l<=j+1;l++){
                        if(k==0||k==h+1||l==0||l==w+1||(k==i&&l==j)){
                            continue;
                        }
                        if(mp[k][l]=='#') ans++;
                    }
                }
                mp[i][j]='0'+ans;
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<mp[i][j];
        }
        cout<<'\n';
    }
    return 0;
}