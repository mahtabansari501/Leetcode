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
    void dfs(TreeNode* root, vector<int>& ans){
        if(root == nullptr){
            ans.push_back(-1e5);
            return;
        }
        ans.push_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> tree1, tree2;

        dfs(p, tree1);
        dfs(q, tree2);

        if(tree1.size() != tree2.size()) return false;

        for(int i = 0; i < tree1.size(); i++){
            if(tree1[i] != tree2[i]) return false;
        }
        return true;
    }
};
