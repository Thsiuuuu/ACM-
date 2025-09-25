#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

typedef long long ll;

vector<pair<ll, ll>> generate_subsets(vector<pair<ll, ll>>& items){
    vector<pair<ll, ll>> res;
    int n = items.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        ll w = 0, v= 0;
        for (int i = 0; i<n;i++) {
            if (mask & (1<<i)) {
                w += items[i].second;
                v += items[i].first;
            }
        }
        res.emplace_back(w, v);
    }
    return res;
}//二进制枚举

int main() {
    ll N, W;
    cin >>N >> W;
    vector<pair<ll, ll>> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].first >> items[i].second; // v, w
    }
    int half=N/2;
    vector<pair<ll, ll>> first_half(items.begin(), items.begin() + half);
    vector<pair<ll, ll>> second_half(items.begin() + half, items.end());
    
    vector<pair<ll, ll>> A = generate_subsets(first_half);
    vector<pair<ll, ll>> B = generate_subsets(second_half);
    
    // 处理A：按w排序，同w保留最大v
    sort(A.begin(), A.end()); // 按重量排序
    vector<pair<ll, ll>> sorted_A;
    ll current_w = -1, current_max_v = -1;
    for (auto& p:A) {
        if(p.first > W) continue; // 超过总容量的子集跳过
        if (p.second >= current_max_v) {
            current_max_v = p.second;
            sorted_A.emplace_back(p.first, p.second);
        }
    }
    if (current_w != -1) {
        sorted_A.emplace_back(current_w, current_max_v);
    }
    
    ll max_val = 0;
    for (auto& p:B) {
        ll pw = p.first, pv = p.second;
        if (pw>W) continue;
        ll rem=W-pw;
        // 在sorted_A中找最大的w≤rem
        auto it = upper_bound(sorted_A.begin(), sorted_A.end(),make_pair(rem, LLONG_MAX),[](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.first < b.first;
        });
        if (it != sorted_A.begin()) {
            it--;
            max_val = max(max_val, pv + it->second);
        }
    }
    cout<<max_val<<endl;
    return 0;
}