#include <stack>
#include <iostream>
#include <string>

using namespace std;


int q[101],top;
string s;
char b[101];

int main(){

    cin>>s;
    for(size_t i=0;i<s.size();i++){
        if(s[i]=='[') q[++top]=i,b[i]=']';
        else if(s[i]=='(') q[++top]=i,b[i]=')';
        else{
            if(!top||b[q[top]]!=s[i])
              if(s[i]==')') b[i]='(';else b[i]='[';
            else b[q[top--]]=' ';
        }
    }
    for(size_t i=0;i<s.size();i++){
        if(b[i]=='('||b[i]=='[') cout<<b[i];
        cout<<s[i];
        if(b[i]==')'||b[i]==']') cout<<b[i];
    }
    return 0;
}