#include <iostream>
#include <algorithm>

using namespace std;

/*


    先把1e7范围内的质数都预处理好，然后检验


*/

const int N=1e7+10;

bool visited[N];
int primes[N];
int top;
void prime(){
    
    for(int i=2;i<N;i++){
        if(!visited[i]){
            primes[top++]=i;
        }
        for(int j=0;j<top;j++){
            if(i*primes[j]>=N){
                break;
            }
            visited[i*primes[j]]=true;
            if(i%primes[j]==0){
                break;
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int t;
    scanf("%d",&t);
    prime();
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int j=0;primes[j]<=n/2;j++){
            if(!visited[n-primes[j]]){
                ans++;
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}