#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// 0:上??1:右??2:下??3:左
vector<int> moveDir = { -1, 0, 1, 0, -1 };

// Dijkstra算法
// grid[i][j] == 0 代表障碍
// grid[i][j] == 1 代表道路
// 只能走上、下、左、右??不包括斜?叻较?
// 返回从(startX, startY)到(targetX, targetY)的最短距离
int minDistance1(vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0) {
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[startX][startY] = 1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // 自定义比较函数??按照距离从小到大排序
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
    
    // 0 : 行
    // 1 : 列
    // 2 : 从源点出发到达当前点的距离
    heap.push({startX, startY, 1});
    
    while (!heap.empty()) {
        vector<int> cur = heap.top();
        heap.pop();
        int x = cur[0];
        int y = cur[1];
        if (visited[x][y]) {
            continue;
        }
        visited[x][y] = true;
        if (x == targetX && y == targetY) {
            return distance[x][y];
        }
        for (int i = 0, nx, ny; i < 4; i++) {
            nx = x + moveDir[i];
            ny = y + moveDir[i + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]
                && distance[x][y] + 1 < distance[nx][ny]) {
                distance[nx][ny] = distance[x][y] + 1;
                heap.push({nx, ny, distance[x][y] + 1});
            }
        }
    }
    return -1;
}





// 曼哈顿距离
int f1(int x, int y, int targetX, int targetY) {
    return (abs(targetX - x) + abs(targetY - y));
}

// 对角?呔嗬?
int f2(int x, int y, int targetX, int targetY) {
    return max(abs(targetX - x), abs(targetY - y));
}

// 欧式距离
double f3(int x, int y, int targetX, int targetY) {
    return sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
}


// A*算法
// grid[i][j] == 0 代表障碍
// grid[i][j] == 1 代表道路
// 只能走上、下、左、右??不包括斜?叻较?
// 返回从(startX, startY)到(targetX, targetY)的最短距离
int minDistance2(vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0) {
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[startX][startY] = 1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // 自定义比较函数??按照f值从小到大排序
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
    
    // 0 : 行
    // 1 : 列
    // 2 : 从源点出发到达当前点的距离 + 当前点到终点的预估距离
    heap.push({startX, startY, 1 + f1(startX, startY, targetX, targetY)});
    
    while (!heap.empty()) {
        vector<int> cur = heap.top();
        heap.pop();
        int x = cur[0];
        int y = cur[1];
        if (visited[x][y]) {
            continue;
        }
        visited[x][y] = true;
        if (x == targetX && y == targetY) {
            return distance[x][y];
        }
        for (int i = 0, nx, ny; i < 4; i++) {
            nx = x + moveDir[i];
            ny = y + moveDir[i + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]
                && distance[x][y] + 1 < distance[nx][ny]) {
                distance[nx][ny] = distance[x][y] + 1;
                heap.push({nx, ny, distance[x][y] + 1 + f1(nx, ny, targetX, targetY)});
            }
        }
    }
    return -1;
}



// 为了测试
vector<vector<int>> randomGrid(int n) {
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((double)rand() / RAND_MAX < 0.3) {
                // 每个格子有30%概率是0
                grid[i][j] = 0;
            } else {
                // 每个格子有70%概率是1
                grid[i][j] = 1;
            }
        }
    }
    return grid;
}

// 为了测试
int main() {

    srand(time(0));
    
    int len = 100;
    int testTime = 10000;
    cout<<"功能测试开始\n";
    for (int i = 0; i < testTime; i++) {
        int n = (rand() % len) + 2;
        vector<vector<int>> grid = randomGrid(n);
        int startX = rand() % n;
        int startY = rand() % n;
        int targetX = rand() % n;
        int targetY = rand() % n;
        int ans1 = minDistance1(grid, startX, startY, targetX, targetY);
        int ans2 = minDistance2(grid, startX, startY, targetX, targetY);
        if (ans1 != ans2) {
            cout<<"出错了\n";
        }
    }
    cout << "功能测试结束" << endl;

    cout << "性能测试开始" << endl;
    vector<vector<int>> grid = randomGrid(4000);
    int startX = 0;
    int startY = 0;
    int targetX = 3900;
    int targetY = 3900;
    
    // 修正?罕苊獗淞棵?冲突??改用 clk_start / clk_end
    clock_t clk_start, clk_end; 
    clk_start = clock();
    int ans1 = minDistance1(grid, startX, startY, targetX, targetY);
    clk_end = clock();
    cout << "运行Dijkstra算法结果: " << ans1 
         << ", 运行时间(毫秒) : " << (clk_end - clk_start) * 1000 / CLOCKS_PER_SEC << endl;
    
    clk_start = clock();
    int ans2 = minDistance2(grid, startX, startY, targetX, targetY);
    clk_end = clock();
    cout << "运行A*算法结果: " << ans2 
         << ", 运行时间(毫秒) : " << (clk_end - clk_start) * 1000 / CLOCKS_PER_SEC << endl;
    
    cout << "性能测试结束" << endl;

    return 0;

}