#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameter;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }
    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int left_path = dfs(node->left);
        int right_path = dfs(node->right);
        diameter = max(diameter, left_path + right_path);
        return max(left_path, right_path) + 1;
    }
};