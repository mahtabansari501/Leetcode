/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* root, int targetSum, int &f) {
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr) {
            if(root->val == targetSum) {
                f = 1;
            }
            return;
        }

        if(root->left != nullptr) {
            dfs(root->left, targetSum - root->val, f);
        }

        if(root->right != nullptr) {
            dfs(root->right, targetSum - root->val, f);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int f = 0;
        dfs(root, targetSum, f);
        return f;
    }
};
