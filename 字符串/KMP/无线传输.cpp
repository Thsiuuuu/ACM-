#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int siz,nex[1000001],j;
char s1[1000001];
//找最小循环节
int main(){
    scanf("%d%s",&siz,s1+1);
    j=0;
    for(int i=1;i<siz;i++){
        while(s1[j+1]!=s1[i+1]&&j) j=nex[j];
        if(s1[j+1]==s1[i+1]) nex[i+1]=++j;
    }
    printf("%d\n",siz-nex[siz]);
}