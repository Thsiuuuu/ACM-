#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*

    Prim算法
    初始任选一个顶点加入树T，此时树中只含有一个顶点，
    之后选择与当前T中顶点集合距离最近的顶点，并将该顶点和相应的边加入T，每次操作后T中的顶点数和边数都增1
    重复以上步骤，直到所有的顶点都并入T，T就是最小生成树


*/



int prim(const vector<vector<pair<int, int>>>& graph) {


    int n = graph.size() - 1; // 节点数
    
    // 最小堆，存储边的权重和终点
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    

    // 标记节点是否已加入生成树
    vector<bool> set(n + 1, false);
    int nodeCnt = 1;
    set[1] = true;
    int ans = 0;

    
    // 将节点1的所有边加入堆
    for (auto& edge : graph[1]) {
        heap.push({edge.second, edge.first});
    }
    
    
    while (!heap.empty()) {
        auto [cost, next] = heap.top();
        heap.pop();
        
        if (!set[next]) {
            nodeCnt++;
            set[next] = true;
            ans += cost;
            
            // 将新加入节点的所有边加入堆
            for (auto& e : graph[next]) {
                heap.push({e.second, e.first});
            }
        }
    }
    
    return nodeCnt == n ? ans : -1; // 返回-1表示无法生成最小生成树
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // 构建邻接表
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    // 调用Prim函数
    int result = prim(graph);
    
    // 输出结果
    cout << (result != -1 ? to_string(result) : "orz") << endl;
    
    return 0;
}    