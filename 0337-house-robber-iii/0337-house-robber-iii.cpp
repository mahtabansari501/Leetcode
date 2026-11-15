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
    unordered_map<TreeNode*,int>mp;
    int rob(TreeNode* root) {
        if(!root)return 0;
        if(mp.count(root))return mp[root];
        int take=root->val;
        if(root->left){
            take+=rob(root->left->left);
            take+=rob(root->left->right);
        }
        if(root->right){
            take+=rob(root->right->left);
            take+=rob(root->right->right);
        }
        int not_take=rob(root->left)+rob(root->right);
        return mp[root]=max(take,not_take);
    }
};