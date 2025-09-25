#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>  // 用于INT_MAX
using namespace std;

const int MAXN = 10001;
const int MAXM = 50001;
const int LIMIT = 21;

// 用结构体存储边，替代原生数组
struct Edge {
    int u, v, w;
} edges[MAXM];  // 现在edges的元素是结构体，支持赋值

// 其他全局变量定义不变...
int power;
int father[MAXN];
bool visited[MAXN];
int head[MAXN];
int nxt[MAXM << 1];  // 避免使用next_，改用nxt更安全
int to_[MAXM << 1];
int weight_[MAXM << 1];
int cnt;
int deep[MAXN];
int stjump[MAXN][LIMIT];
int stmin[MAXN][LIMIT];

// log2函数不变...
int log2(int n) {
    int ans = 0;
    while ((1 << ans) <= (n >> 1)) {
        ans++;
    }
    return ans;
}

// build函数不变...
void build(int n) {
    power = log2(n);
    cnt = 1;
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    memset(visited, false, sizeof(visited));
    memset(head, 0, sizeof(head));
}

// find函数不变...
int find(int i) {
    if (i != father[i]) {
        father[i] = find(father[i]);
    }
    return father[i];
}

// addEdge函数不变...
void addEdge(int u, int v, int w) {
    nxt[cnt] = head[u];
    to_[cnt] = v;
    weight_[cnt] = w;
    head[u] = cnt++;
}

// Kruskal算法中排序部分修改为结构体比较...
void kruskal(int n, int m) {
    // 对结构体数组按w降序排序
    sort(edges + 1, edges + m + 1, [](const Edge& a, const Edge& b) {
        return a.w > b.w;  // 按权重从大到小排序
    });
    
    for (int i = 1; i <= m; i++) {
        int a = edges[i].u;  // 访问结构体成员
        int b = edges[i].v;
        int fa = find(a);
        int fb = find(b);
        if (fa != fb) {
            father[fa] = fb;
            addEdge(a, b, edges[i].w);
            addEdge(b, a, edges[i].w);
        }
    }
}

// dfs函数不变（仅调整stmin的初始值为INT_MAX）...
void dfs(int u, int w, int f) {
    visited[u] = true;
    if (f == 0) {
        deep[u] = 1;
        stjump[u][0] = u;
        stmin[u][0] = INT_MAX;  // 使用INT_MAX更规范
    } else {
        deep[u] = deep[f] + 1;
        stjump[u][0] = f;
        stmin[u][0] = w;
    }
    
    for (int p = 1; p <= power; p++) {
        stjump[u][p] = stjump[stjump[u][p-1]][p-1];
        stmin[u][p] = min(stmin[u][p-1], stmin[stjump[u][p-1]][p-1]);
    }
    
    for (int e = head[u]; e != 0; e = nxt[e]) {
        if (!visited[to_[e]]) {
            dfs(to_[e], weight_[e], u);
        }
    }
}

// lca函数不变...
int lca(int a, int b) {
    if (find(a) != find(b)) {
        return -1;
    }
    
    if (deep[a] < deep[b]) {
        swap(a, b);
    }
    
    int ans = INT_MAX;
    for (int p = power; p >= 0; p--) {
        if (deep[stjump[a][p]] >= deep[b]) {
            ans = min(ans, stmin[a][p]);
            a = stjump[a][p];
        }
    }
    
    if (a == b) {
        return ans;
    }
    
    for (int p = power; p >= 0; p--) {
        if (stjump[a][p] != stjump[b][p]) {
            ans = min(ans, min(stmin[a][p], stmin[b][p]));
            a = stjump[a][p];
            b = stjump[b][p];
        }
    }
    
    ans = min(ans, min(stmin[a][0], stmin[b][0]));
    return ans;
}

// main函数中输入部分修改为结构体赋值...
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        // 给结构体成员赋值
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    build(n);
    kruskal(n, m);
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0, 0);
        }
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}