#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN=1000001;
const int MAXM=1000001;

int head[MAXN];
int edge[MAXN];
int to[MAXM];
int cnt;

int heap[MAXN];
int heapsize;

int indegree[MAXN];

int ans[MAXN];

int n,m;


void build(int n){
    cnt=1;
    heapsize=0;
    memset(head,0,(n+1)*sizeof(int));
    memset(indegree,0,(n+1)*sizeof(int));
}


void addEdge(int f,int t){
    edge[cnt]=head[f];
    to[cnt]=t;
    head[f]=cnt++;
}


void push(int num){
    int i=heapsize++;
    heap[i]=num;
    while(heap[i]<heap[(i-1)/2]){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }
}


int pop(){
    int ans=heap[0];
    heap[0]=heap[--heapsize];
    int i=0,l=1;
    while(l<heapsize){
        int best=l+1<heapsize&&heap[l+1]<heap[l]?l+1:l;
        best=heap[best]<heap[i]?best:i;
        if(best==i) break;

        swap(heap[best],heap[i]);
        i=best;
        l=i*2+1;
    }
    return ans;
}

bool isempty(){
    return heapsize==0;
}

void toposort(){
    for(int i=1;i<=n;i++)
        if(indegree[i]==0) 
            push(i);

    int fill=0;
    while(!isempty()){
        int cur=pop();
        ans[fill++]=cur;
        for(int ei=head[cur];ei!=0;ei=edge[ei]){
            if(--indegree[to[ei]]==0){
                push(to[ei]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m){
        build(n);
        for(int i=0,from,to;i<m;i++){
            cin>>from>>to;
            addEdge(from,to);
            indegree[to]++;
        }
    }
    toposort();
    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[n-1]<<"\n";
    return 0;
}