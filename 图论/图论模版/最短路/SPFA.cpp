#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 2001;
const int MAXM = 6001;

// 链式前向星建图需要
int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int weight[MAXM];
int cnt;

// SPFA需要
int dist[MAXN];  // 源点出发到每个节点的距离表
int updateCnt[MAXN]; // 节点被松弛的次数
bool enter[MAXN];    // 节点是否已经在队列中

void build(int n) {
    cnt = 1;
    memset(head, 0, sizeof(head));
    memset(enter, false, sizeof(enter));
    fill(dist + 1, dist + n + 1, INT_MAX);
    memset(updateCnt, 0, sizeof(updateCnt));
}

void addEdge(int u, int v, int w) {
    nxt[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}

// Bellman-Ford + SPFA优化的模版
bool spfa(int n) {
    dist[1] = 0;
    updateCnt[1]++;
    queue<int> q;
    q.push(1);
    enter[1] = true;
    
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
                    // 松弛次数超过n-1就有负环
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
    
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; i++) {
        int n, m;
        cin >> n >> m;
        build(n);
        
        for (int j = 0; j < m; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            
            if (w >= 0) {
                addEdge(u, v, w);
                addEdge(v, u, w);
            } else {
                addEdge(u, v, w);
            }
        }
        
        cout << (spfa(n) ? "YES" : "NO") << endl;
    }
    
    return 0;
}