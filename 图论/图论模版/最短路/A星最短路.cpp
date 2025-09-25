#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// 0:��??1:��??2:��??3:��
vector<int> moveDir = { -1, 0, 1, 0, -1 };

// Dijkstra�㷨
// grid[i][j] == 0 �����ϰ�
// grid[i][j] == 1 �����·
// ֻ�����ϡ��¡�����??������б?߷��?
// ���ش�(startX, startY)��(targetX, targetY)����̾���
int minDistance1(vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0) {
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[startX][startY] = 1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // �Զ���ȽϺ���??���վ����С��������
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
    
    // 0 : ��
    // 1 : ��
    // 2 : ��Դ��������ﵱǰ��ľ���
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





// �����پ���
int f1(int x, int y, int targetX, int targetY) {
    return (abs(targetX - x) + abs(targetY - y));
}

// �Խ�?߾��?
int f2(int x, int y, int targetX, int targetY) {
    return max(abs(targetX - x), abs(targetY - y));
}

// ŷʽ����
double f3(int x, int y, int targetX, int targetY) {
    return sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
}


// A*�㷨
// grid[i][j] == 0 �����ϰ�
// grid[i][j] == 1 �����·
// ֻ�����ϡ��¡�����??������б?߷��?
// ���ش�(startX, startY)��(targetX, targetY)����̾���
int minDistance2(vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0) {
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[startX][startY] = 1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // �Զ���ȽϺ���??����fֵ��С��������
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
    
    // 0 : ��
    // 1 : ��
    // 2 : ��Դ��������ﵱǰ��ľ��� + ��ǰ�㵽�յ��Ԥ������
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



// Ϊ�˲���
vector<vector<int>> randomGrid(int n) {
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((double)rand() / RAND_MAX < 0.3) {
                // ÿ��������30%������0
                grid[i][j] = 0;
            } else {
                // ÿ��������70%������1
                grid[i][j] = 1;
            }
        }
    }
    return grid;
}

// Ϊ�˲���
int main() {

    srand(time(0));
    
    int len = 100;
    int testTime = 10000;
    cout<<"���ܲ��Կ�ʼ\n";
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
            cout<<"������\n";
        }
    }
    cout << "���ܲ��Խ���" << endl;

    cout << "���ܲ��Կ�ʼ" << endl;
    vector<vector<int>> grid = randomGrid(4000);
    int startX = 0;
    int startY = 0;
    int targetX = 3900;
    int targetY = 3900;
    
    // ����?���������?��ͻ??���� clk_start / clk_end
    clock_t clk_start, clk_end; 
    clk_start = clock();
    int ans1 = minDistance1(grid, startX, startY, targetX, targetY);
    clk_end = clock();
    cout << "����Dijkstra�㷨���: " << ans1 
         << ", ����ʱ��(����) : " << (clk_end - clk_start) * 1000 / CLOCKS_PER_SEC << endl;
    
    clk_start = clock();
    int ans2 = minDistance2(grid, startX, startY, targetX, targetY);
    clk_end = clock();
    cout << "����A*�㷨���: " << ans2 
         << ", ����ʱ��(����) : " << (clk_end - clk_start) * 1000 / CLOCKS_PER_SEC << endl;
    
    cout << "���ܲ��Խ���" << endl;

    return 0;

}