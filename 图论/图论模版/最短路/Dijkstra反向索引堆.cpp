#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100001;
const int MAXM = 200001;
const int INF = 0x3f3f3f3f;

// 链式前向星
int head[MAXN], next_edge[MAXM], to[MAXM], weight[MAXM];
int cnt = 1;  // 边计数器从1开始（与Java保持一致）

// 反向索引堆
int heap[MAXN], where[MAXN], distance[MAXN];
int heapSize = 0;

int n, m, s;

// 初始化图和堆
void build() {
    cnt = 1;
    heapSize = 0;
    memset(head, 0, sizeof(head));  // head数组初始化为0
    fill(where + 1, where + n + 1, -1);  // where[v]=-1表示未入堆
    fill(distance + 1, distance + n + 1, INF);  // 距离初始化为无穷大
}

// 添加有向边
void addEdge(int u, int v, int w) {
    next_edge[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}

// 向堆中添加或更新节点
void addOrUpdateOrIgnore(int v, int w) {
    if (where[v] == -1) {  // 从未入堆
        heap[heapSize] = v;
        where[v] = heapSize++;
        distance[v] = w;
        heapInsert(where[v]);
    } else if (where[v] >= 0) {  // 存在于堆中，更新距离
        if (w < distance[v]) {
            distance[v] = w;
            heapInsert(where[v]);
        }
    }
    // 已弹出的节点（where[v]=-2）忽略
}

// 堆上浮操作
void heapInsert(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (distance[heap[i]] >= distance[heap[parent]]) break;
        swap(heap[i], heap[parent]);
        swap(where[heap[i]], where[heap[parent]]);  // 更新索引位置
        i = parent;
    }
}

// 堆弹出操作
int pop() {
    int ans = heap[0];
    heap[0] = heap[--heapSize];
    where[heap[0]] = 0;  // 更新新堆顶的位置
    heapify(0);
    where[ans] = -2;  // 标记为已弹出
    return ans;
}

// 堆下沉操作
void heapify(int i) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        if (l < heapSize && distance[heap[l]] < distance[heap[smallest]])
            smallest = l;
        if (r < heapSize && distance[heap[r]] < distance[heap[smallest]])
            smallest = r;
        if (smallest == i) break;
        swap(heap[i], heap[smallest]);
        swap(where[heap[i]], where[heap[smallest]]);  // 更新索引位置
        i = smallest;
    }
}

// 判断堆是否为空
bool isEmpty() {
    return heapSize == 0;
}

// Dijkstra算法主函数
void dijkstra() {
    addOrUpdateOrIgnore(s, 0);
    while (!isEmpty()) {
        int v = pop();
        for (int ei = head[v]; ei != 0; ei = next_edge[ei]) {
            int neighbor = to[ei];
            int newDist = distance[v] + weight[ei];
            addOrUpdateOrIgnore(neighbor, newDist);
        }
    }
}

// 快速输入输出优化
struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastIO;

int main() {
    while (cin >> n >> m >> s) {
        build();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
        dijkstra();
        cout << distance[1];
        for (int i = 2; i <= n; i++) {
            cout << " " << (distance[i] == INF ? -1 : distance[i]);
        }
        cout << endl;
    }
    return 0;
}