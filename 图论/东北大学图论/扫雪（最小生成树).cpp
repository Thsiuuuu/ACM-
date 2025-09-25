#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

const int MAXN = 1010;
// 存储点的坐标
double points[MAXN][2]; 
// 邻接矩阵存边权（距离）
double graph[MAXN][MAXN]; 
// 标记点是否加入生成树
bool visited[MAXN]; 
// 记录当前到生成树的最小距离
double dist[MAXN]; 

// 计算两点 (x1,y1) 和 (x2,y2) 的距离
double calcDist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

// Prim 算法求最小生成树总权值
double prim(int n) {
    // 初始化距离数组为无穷大
    fill(dist, dist + n, INT_MAX); 
    // 标记数组初始化
    fill(visited, visited + n, false); 
    // 第一个点加入生成树
    dist[0] = 0; 
    double total = 0;

    for (int i = 0; i < n; i++) {
        // 找当前距离生成树最近的点
        int u = -1;
        double minDist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // 无法连通（题目保证 n>=2，实际不会出现）
        visited[u] = true;
        total += minDist;

        // 更新其他点到生成树的距离
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] < dist[v]) {
                dist[v] = graph[u][v];
            }
        }
    }
    return total;
}

int main() {
    int n;
    // 多组输入，直到 EOF
    while (cin >> n) { 
        // 读入每个点的坐标
        for (int i = 0; i < n; i++) { 
            cin >> points[i][0] >> points[i][1];
        }

        // 构建邻接矩阵
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = calcDist(points[i][0], points[i][1], 
                                      points[j][0], points[j][1]);
            }
        }

        // 求最小生成树总长度
        double result = prim(n); 
        // 保留 1 位小数输出
        cout << fixed << setprecision(1) << result << endl; 
    }
    return 0;
}