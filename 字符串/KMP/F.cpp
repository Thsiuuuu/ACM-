#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string s;
int nex[1000010];

void sol(){
    while(cin>>s){
        if(s=="."){
            return ;
        }
        int len=s.size();
        s=" "+s;
        int j=0;   
        for(int i=1;i<len;i++){
            while(s[i+1]!=s[j+1]&&j){
                j=nex[j];
            }
            if(s[i+1]==s[j+1]){
                nex[i+1]=++j;
            }
        }
        if(len%(len-nex[len])==0){
            cout<<len/(len-nex[len])<<'\n';
        }else{
            cout<<"1\n";
        }
        fill(nex,nex+1000010,0);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();

}