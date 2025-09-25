#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, p;
        cin >> n >> p;
        
        vector<int> next(n + 1, 0); // next[i] 表示从i出发能到达的下一站
        for (int i = 0; i < p; ++i) {
            int l, r;
            cin >> l >> r;
            next[l] = r;
        }
        
        int q;
        cin >> q;
        while (q--) {
            int m;
            cin >> m;
            
            // BFS 初始化
            vector<int> dist(n + 1, INT_MAX);
            queue<int> q;
            q.push(m);
            dist[m] = 0;
            bool found = false;
            
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                
                if (current == 1) {
                    cout << dist[current] << endl;
                    found = true;
                    break;
                }
                
                int next_station = next[current];
                if (next_station != 0 && dist[next_station] == INT_MAX) {
                    dist[next_station] = dist[current] + 1;
                    q.push(next_station);
                }
            }
            
            if (!found) {
                cout << "GG" << endl;
            }
        }
    }
    return 0;
}