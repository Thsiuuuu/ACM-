#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


const int MAXN = 1002;
const int MAXM = 2002;


int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int weight[MAXM];
int cnt;


int dist[MAXN];  
int updateCnt[MAXN]; 
bool enter[MAXN];    

int r;

void build(int n) {
    cnt = 1;
    memset(head, 0, sizeof(head));
    memset(enter, false, sizeof(enter));
    fill(dist, dist + n + 1, INT_MAX);
    memset(updateCnt, 0, sizeof(updateCnt));
}

void addEdge(int u, int v, int w) {
    nxt[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}


bool spfa(int n) {
    dist[r] = 0;
    updateCnt[r]++;
    queue<int> q;
    q.push(r);
    enter[r] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        enter[u] = false;
        
        for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
            int v = to[ei];
            int w = weight[ei];
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                
                if (!enter[v]) {

                    if (++updateCnt[v] > n - 1) {
                        return true;
                    }
                    
                    q.push(v);
                    enter[v] = true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
        int n, m;
        cin >> n >> m>>r;
        build(n);
        
        for (int j = 0; j < m; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u,v,w);
        }
        
        if(spfa(n)) cout<<"NEGATIVE CYCLE";
        else{
            for(int i=0;i<n;i++){
                if(dist[i]==INT_MAX) cout<<"INF\n";
                else cout<<dist[i]<<"\n";
            }
        }    
    return 0;
}