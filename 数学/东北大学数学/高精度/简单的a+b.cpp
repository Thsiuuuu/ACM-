#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmpAbs(const vector<int>& A, const vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return false; // 相等时返回false
}

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

// 处理带符号的大整数加法
pair<vector<int>, bool> addSigned(vector<int>& A, bool signA, vector<int>& B, bool signB) {
    // 符号相同：绝对值相加，符号不变
    if (signA == signB) {
        return {addAbs(A, B), signA};
    }
    // 符号不同：绝对值相减，符号取绝对值大的数的符号
    else {
        if (cmpAbs(A, B)) {
            return {subAbs(A, B), signA};
        } else if (cmpAbs(B, A)) {
            return {subAbs(B, A), signB};
        } else {
            return {{0}, false}; // A和B绝对值相等，结果为0（符号为正）
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin >>a>>b;

    // 处理符号
    bool signA = (a[0] != '-'); // true表示正数，false表示负数
    bool signB = (b[0] != '-'); // true表示正数，false表示负数

    // 提取绝对值部分
    vector<int> absA, absB;
    for (int i = a.size() - 1; i >= (signA ? 0 : 1); i--) {
        absA.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= (signB ? 0 : 1); i--) {
        absB.push_back(b[i] - '0');
    }

    // 处理零的情况（避免前导零）
    if (absA.size() == 1 && absA[0] == 0) signA = true;
    if (absB.size() == 1 && absB[0] == 0) signB = true;

    // 执行带符号的加法
    auto [result, signResult] = addSigned(absA, signA, absB, signB);

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