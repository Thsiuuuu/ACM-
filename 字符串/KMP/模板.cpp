#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

using  namespace std;

const int N=1000010;
char s[N];
char t[N];
int fail[N];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    int p;

    fail[0]=0;
    fail[1]=0;
    p=0;

    for(int i=1;i<m;i++){
        while(t[p+1]!=t[i+1]&&p) p=fail[p];//fail数组既记录了包含自己在内的最大相同前后缀长度，也记录了这个点的最大前缀长度的右端点
        //只要当前的下一位不相等，那么我就跳转到我当前最大相同前后缀长度的上一个拥有最大相同前后缀长度的前缀的右端点
        if(t[p+1]==t[i+1]){
            p++;
        }
        fail[i+1]=p;
    }
    

    p=0;
    for(int i=1;i<=n;i++){
        while(t[p+1]!=s[i]&&p) p=fail[p];
        if(t[p+1]==s[i]){
            p++;
        }
        if(p==m){
            printf("%d\n",i-m+1);
            p=fail[p];//匹配成功也需要进行跳转
        }
    }

    for(int i=1;i<=m;i++){printf("%d ",fail[i]);}
    return 0;    
}