#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int sum,num;
int len;
int t;
/*

    从大到小枚举，跑dfs

    依次拼好每一根棍子


*/

const int N=105;
int stick[N],v[N];

bool cmp(int a,int b){
    return a>b;
}
bool dfs(int cnt,int num,int las){
    if(cnt>t) return true;

    if(num==len){
        return dfs(cnt+1,0,0);
    }

    int fail=0;
    for(int i=las;i<n;i++){
        if(!v[i]&&stick[i]+num<=len&&fail!=stick[i]){
            v[i]=1;
            if(dfs(cnt,num+stick[i],i)) return true;
            v[i]=0,fail=stick[i];
            if(num==0) return false;
        }
    }

    return false;
}

int main(){
    while(scanf("%d",&n),n){

        bool st=false;
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&stick[i]);
            sum+=stick[i];
        }

        sort(stick,stick+n,cmp);
        for(len=stick[0];len<=sum/2;len++){//如果两份都分不出来，只能是一份，可以降低不少复杂度
            if(sum%len!=0){
                continue;
            }

            memset(v,0,sizeof(v));
            t=sum/len;
            if(dfs(1,0,0)){
                st=true;
                printf("%d\n",len);
                break;
            }
        }
        if(!st){
            printf("%d\n",sum);
        }
    }    
    return 0;
}