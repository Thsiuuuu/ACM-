#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define int long long

const int MAXN = 100001;
const int MAXM = 500002;

// 链式前向星
int head[MAXN];
int next_edge[MAXM];
int to[MAXM];
int weight[MAXM];
int cnt;

// 距离数组
int distance_to[MAXN];
// 标记数组，记录节点是否已处理
bool visited[MAXN];

int n, m, s;

// 初始化
void build() {
    cnt = 1;
    fill(head, head + n + 1, 0);
    fill(distance_to, distance_to + n + 1, INT_MAX);
    fill(visited, visited + n + 1, false);
}

// 添加边
void addEdge(int u, int v, int w) {
    next_edge[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}

// Dijkstra算法
void dijkstra() {
    // 定义优先队列，存储pair<距离, 节点>，使用greater实现小根堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    // 起点入队
    distance_to[s] = 0;
    heap.push({0, s});
    
    while (!heap.empty()) {
        // 取出当前距离最小的节点
        int dist = heap.top().first;
        int u = heap.top().second;
        heap.pop();
        
        // 如果节点已经处理过，跳过
        if (visited[u]) continue;
        visited[u] = true;
        
        // 遍历所有邻接边
        for (int ei = head[u]; ei != 0; ei = next_edge[ei]) {
            int v = to[ei];
            int w = weight[ei];
            
            // 松弛操作
            if (distance_to[v] > dist + w) {
                distance_to[v] = dist + w;
                heap.push({distance_to[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (cin>>n>>m>>s) {
        build();
        
        // 读入边
        for (int i=0,u,v,w;i<m;i++){
            cin>>u>>v>>w;
            addEdge(u, v, w);
        }
        
        // 执行Dijkstra算法
        dijkstra();
        
        // 输出结果
        for(int i=0;i<n;i++){
            if(distance_to[i]==INT_MAX){
                cout<<"INF\n";
                continue;
            }
            cout<<distance_to[i]<<"\n";
        }
    }
    
    return 0;
}    