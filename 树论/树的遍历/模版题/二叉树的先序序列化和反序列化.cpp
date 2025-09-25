#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 辅助函数：分割字符串
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    for (char c : s) {
        if (c == delimiter) {
            tokens.push_back(token);
            token.clear();
        } else {
            token += c;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

// 序列化函数
string serialize(TreeNode* root) {
    if (root == nullptr) {
        return "#,";
    }
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

// 全局变量：当前处理到的位置
int cnt = 0;

// 辅助函数：递归反序列化
TreeNode* deserializeHelper(const vector<string>& vals) {
    if (cnt >= vals.size() || vals[cnt] == "#") {
        cnt++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(stoi(vals[cnt++]));
    node->left = deserializeHelper(vals);
    node->right = deserializeHelper(vals);
    return node;
}

// 反序列化函数
TreeNode* deserialize(string data) {
    vector<string> vals = split(data, ',');
    cnt = 0;
    return deserializeHelper(vals);
}