#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 比较两个非负大整数的大小
bool cmpAbs(const vector<int>& A, const vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return false; // 相等时返回false
}

// 大整数加法（处理非负整数）
vector<int> addAbs(vector<int>& A, vector<int>& B) {
    if (A.size() < B.size()) return addAbs(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}

// 大整数减法（处理非负整数，要求A >= B）
vector<int> subAbs(vector<int>& A, vector<int>& B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 去除前导零
    return C;
}

// 处理带符号的大整数减法 a - b
pair<vector<int>, bool> subtractSigned(vector<int>& A, bool signA, vector<int>& B, bool signB) {
    // 处理符号逻辑：a - b = a + (-b)
    if (signA == signB) {
        // 符号相同：比较绝对值，用大的减小的
        if (cmpAbs(A, B)) {
            return {subAbs(A, B), signA}; // 结果符号与A相同
        } else if (cmpAbs(B, A)) {
            return {subAbs(B, A), !signA}; // 结果符号与A相反
        } else {
            return {{0}, true}; // A和B相等，结果为0（符号为正）
        }
    } else {
        // 符号不同：绝对值相加，符号与A相同
        return {addAbs(A, B), signA};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    // 处理符号：true表示正数，false表示负数
    bool signA = (a[0] != '-');
    bool signB = (b[0] != '-');

    // 提取绝对值部分（逆序存储）
    vector<int> absA, absB;
    for (int i = a.size() - 1; i >= (signA ? 0 : 1); i--) {
        absA.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= (signB ? 0 : 1); i--) {
        absB.push_back(b[i] - '0');
    }

    // 处理零的特殊情况（避免前导零）
    if (absA.size() == 1 && absA[0] == 0) signA = true;
    if (absB.size() == 1 && absB[0] == 0) signB = true;

    // 执行带符号的减法
    auto [result, signResult] = subtractSigned(absA, signA, absB, signB);

    // 输出结果
    if (!signResult && !(result.size() == 1 && result[0] == 0)) {
        cout << "-";
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}