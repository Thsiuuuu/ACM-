#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define int long long 
const int MAX_J = 50 * 1e9 + 10; // 足够大的价值范围，覆盖所有可能的vi*mi组合
int dp[MAX_J];

signed main() {
    int N;
    int W;
    cin >> N >> W;
    fill(dp, dp + MAX_J, LLONG_MAX);
    dp[0] = 0; // 初始状态：价值0，重量0

    for (int i = 0; i < N; i++) {
        int v;
        int w, m;
        cin >> v >> w >> m;
        // 二进制拆分多重背包，转化为01背包
        for (int k = 1; k <= m; k <<= 1) {
            int take = min(k, m);
            int val = take * v;
            int weight = take * w;
            // 逆序更新，避免重复选取同一物品多次（01背包处理方式）
            for (int j = MAX_J - 1; j >= val; j--) {
                if (dp[j - val] != LLONG_MAX && dp[j] > dp[j - val] + weight) {
                    dp[j] = dp[j - val] + weight;
                }
            }
            m -= take;
        }
        // 处理剩余的m（若m>0）
        if (m > 0) {
            int val = m * v;
            int weight = m * w;
            for (int j = MAX_J - 1; j >= val; j--) {
                if (dp[j - val] != LLONG_MAX && dp[j] > dp[j - val] + weight) {
                    dp[j] = dp[j - val] + weight;
                }
            }
        }
    }

    int max_val = 0;
    // 查找最大价值j，其对应的重量≤W
    for (int j = 0; j < MAX_J; j++) {
        if (dp[j] <= W && j > max_val) {
            max_val = j;
        }
    }
    cout << max_val << endl;
    return 0;
}