#include <algorithm>
#include <iostream>

using  namespace std;

int main()(
    int n;
    scanf("%d",&n);
    if(n<=1){
        printf("no");
    }else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                printf("yes");
                break;
            }
        }
    }
    return 0;
)