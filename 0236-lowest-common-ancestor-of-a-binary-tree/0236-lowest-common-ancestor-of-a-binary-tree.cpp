/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool get_path(TreeNode* root,vector<TreeNode*>&a,TreeNode* p){
        if(!root)return false;
        a.push_back(root);
        if(root==p)return true;
        if(get_path(root->left,a,p)||get_path(root->right,a,p)){
            return true;
        }
        a.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,b;
        get_path(root,a,p);
        get_path(root,b,q);
        int i=0;
        while (i<min(a.size(),b.size())&&a[i] ==b[i]) {
            i++;
        }
        return a[i-1]; 
    }
};