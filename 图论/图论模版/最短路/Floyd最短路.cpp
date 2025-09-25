#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN = 101;
const int MAXM = 10001;

int path[MAXM];
int distance[MAXN][MAXN];
int n, m, ans;

// 初始时设置任意两点之间的最短距离为无穷大，表示任何路不存在
void build() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distance[i][j] = INT_MAX;
        }
    }
}

void floyd() {
    // O(N^3)的过程
    // 枚举每个跳板
    // 注意，跳板要最先枚举！跳板要最先枚举！跳板要最先枚举！
    for (int bridge = 0; bridge < n; bridge++) { // 跳板
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // i -> .....bridge .... -> j
                // distance[i][j]能不能缩短
                // distance[i][j] = min ( distance[i][j] , distance[i][bridge] + distance[bridge][j])
                if (distance[i][bridge] != INT_MAX 
                        && distance[bridge][j] != INT_MAX
                        && distance[i][j] > distance[i][bridge] + distance[bridge][j]) {
                    distance[i][j] = distance[i][bridge] + distance[bridge][j];
                }
            }
        }
    }
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            cin >> path[i];
            path[i]--; // 转换为0-based索引
        }
        // 这道题给的图是邻接矩阵的形式
        // 任意两点之间的边权都会给定
        // 所以显得distance初始化不太必要
        // 但是一般情况下，distance初始化一定要做
        build();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> distance[i][j];
            }
        }
        floyd();
        ans = 0;
        for (int i = 1; i < m; i++) {
            ans += distance[path[i - 1]][path[i]];
        }
        cout << ans << endl;
    }
    return 0;
}