#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 并查集数据结构定义
vector<int> parent;
vector<int> rk;


//可以使用set，自动去重，从而收集出每个联通块的头部结点

int find(int u) {
    while (parent[u] != u) {
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}


void unite(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);
    if (uRoot == vRoot) return;
    if (rk[uRoot] < rk[vRoot]) {
        parent[uRoot] = vRoot;
    } else {
        parent[vRoot] = uRoot;
        if (rk[uRoot] == rk[vRoot]) {
            rk[uRoot]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    rk.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }


    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    set<int> roots;
    for (int i = 1; i <= n; ++i) {
        roots.insert(find(i));
    }

    int k = roots.size() - 1;
    cout << k << endl;

    if (k > 0) {
        vector<int> rootList(roots.begin(), roots.end());
        for (int i = 0; i < k; ++i) {
            cout << rootList[i] << " " << rootList[i + 1] << endl;
        }
    }

    return 0;
}    