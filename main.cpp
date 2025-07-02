#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<string>& values) {
    if (values.empty() || values[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(values[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front(); q.pop();
        if (values[i] != "null") {
            current->left = new TreeNode(stoi(values[i]));
            q.push(current->left);
        }
        i++;
        if (i < values.size() && values[i] != "null") {
            current->right = new TreeNode(stoi(values[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

TreeNode* findLCA(TreeNode* root, int p, int q) {
    if (!root || root->val == p || root->val == q) return root;
    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);
    return left && right ? root : left ? left : right;
}

int main() {
    string input = "3,5,1,6,2,0,8,null,null,7,4";
    vector<string> values;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        values.push_back(token);
    }

    int p = 5, q = 1;
    TreeNode* root = buildTree(values);
    TreeNode* lca = findLCA(root, p, q);
    if (lca)
        cout << "LCA of " << p << " and " << q << " is " << lca->val << endl;
    else
        cout << "LCA not found.\n";
    return 0;
}
