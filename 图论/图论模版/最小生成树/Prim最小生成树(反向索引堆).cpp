#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 5001;
const int MAXM = 400001;

int n, m;

// 链式前向星建图
int head[MAXN];
int next_edge[MAXM];
int to[MAXM];
int weight[MAXM];
int cnt;

// 改写的堆结构
int heap[MAXN][2];
int where[MAXN];
int heapSize;
int nodeCnt;

void build() {
    cnt = 1;
    heapSize = 0;
    nodeCnt = 0;
    memset(head, 0, sizeof(head));
    memset(where, -1, sizeof(where));
}

void addEdge(int u, int v, int w) {
    next_edge[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}



// 堆上，i位置的信息 和 j位置的信息 交换
void swap(int i, int j) {
    int a = heap[i][0];
    int b = heap[j][0];
    where[a] = j;
    where[b] = i;
    int tmp0 = heap[i][0];
    int tmp1 = heap[i][1];
    heap[i][0] = heap[j][0];
    heap[i][1] = heap[j][1];
    heap[j][0] = tmp0;
    heap[j][1] = tmp1;
}





void heapInsert(int i) {
    while (heap[i][1] < heap[(i - 1) / 2][1]) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// 当前处理的是编号为ei的边
void addOrUpdateOrIgnore(int ei) {
    int v = to[ei];
    int w = weight[ei];
    // 去往v点，权重w
    if (where[v] == -1) {
        // v这个点，从来没有进入过堆
        heap[heapSize][0] = v;
        heap[heapSize][1] = w;
        where[v] = heapSize++;
        heapInsert(where[v]);
    } else if (where[v] >= 0) {
        // v这个点的记录，在堆上的位置是where[v]
        if (w < heap[where[v]][1]) {
            heap[where[v]][1] = w;
            heapInsert(where[v]);
        }
    }
}



int u;
int w;

// 堆顶的记录：节点 -> u、到节点的花费 -> w
void heapify(int i) {
    int l = i * 2 + 1;
    while (l < heapSize) {
        int best = l + 1 < heapSize && heap[l + 1][1] < heap[l][1] ? l + 1 : l;
        best = heap[best][1] < heap[i][1] ? best : i;
        if (best == i) {
            break;
        }
        swap(best, i);
        i = best;
        l = i * 2 + 1;
    }
}


void pop() {
    u = heap[0][0];
    w = heap[0][1];

    swap(0, --heapSize);
    heapify(0);
    where[u] = -2;
    nodeCnt++;
}



bool isEmpty() {
    return heapSize == 0;
}


int prim() {
    // 1节点出发
    nodeCnt = 1;
    where[1] = -2;
    for (int ei = head[1]; ei > 0; ei = next_edge[ei]) {
        addOrUpdateOrIgnore(ei);
    }
    int ans = 0;
    while (!isEmpty()) {
        pop();
        ans += w;
        for (int ei = head[u]; ei > 0; ei = next_edge[ei]) {
            addOrUpdateOrIgnore(ei);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (cin >> n >> m) {
        build();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        int ans = prim();
        cout << ((nodeCnt == n )? to_string(ans) : "orz") << endl;
    }
    
    return 0;
}    