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
    void dfs(TreeNode* root,int targetSum,vector<vector<int>>&ans,vector<int>&a){
        if(root==nullptr){
            return ;
        }
        if(root->left == nullptr && root->right == nullptr) {
            if(root->val == targetSum) {
                a.push_back(root->val);
                ans.push_back(a);
                a.pop_back();
            }
            return;
        }
        if(root->left != nullptr) {
            a.push_back(root->val);
            dfs(root->left, targetSum - root->val,ans,a);
            a.pop_back();
        }

        if(root->right != nullptr) {
            a.push_back(root->val);
            dfs(root->right, targetSum - root->val,ans,a);
            a.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>a;
        dfs(root,targetSum,ans,a);
        return ans;

    }
};