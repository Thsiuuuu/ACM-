#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int trie[200010][26],cnt[200010],idx;
vector<string> str;
string s;

/*

    构造字典树
    如果能够拥有前缀的话，那么在查询过程走完之前一定有一个次数为1的点，这个点就是前缀的最后一位
    如果没有的话，那么就是他自己就是前缀，直接返回自己即可

*/
int getnum(char x){
    return x-'a';
}

void insert(string s){
    int p=0,len=s.size();
    for(int i=0;i<len;i++){
        int c=getnum(s[i]);
        if(!trie[p][c]){
            trie[p][c]=++idx;
        }
        p=trie[p][c];
        cnt[p]++;
    }
}

int find(string s){
    int p=0,len=s.size();
    for(int i=0;i<len;i++){
        int c=getnum(s[i]);
        p=trie[p][c];
        if(cnt[p]==1){
            return i;
        }
    }
    return len-1;
}

void  sol(){
    while(cin>>s){
        str.push_back(s);
        insert(s);
    }
    for(string s:str){
        cout<<s<<" ";
        for(int i=0;i<=find(s);i++){
            cout<<s[i];
        }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();
}